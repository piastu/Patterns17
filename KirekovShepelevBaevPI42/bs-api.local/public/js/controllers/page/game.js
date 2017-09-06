(function($, APP) {
    'use strict';

    /**
     * Страница процесса игры
     **/
    APP.Controls.Page.Game = can.Control.extend({

        myTurn: false,
        $hoveredCell: false,

        init: function() {
            this.$turn = this.element.find('.js-turn');
            this.$fieldMyOverlay     = this.element.find('.js-field-my .field-overlay');
            this.$fieldMyGraphics    = this.element.find('.js-field-my .field-graphics');
            this.$fieldEnemyOverlay  = this.element.find('.js-field-enemy .field-overlay');
            this.$fieldEnemyGraphics = this.element.find('.js-field-enemy .field-graphics');
            this.getStatus();

            new APP.Controls.Partial.Chat(this.element.find('.js-chat'));
        },

        '.js-field-enemy .field-overlay .cell mouseover': function($cell) {
            var currentCoords = this.getCellCoords(this.$hoveredCell);
            var hoveredCoords = this.getCellCoords($cell);
            if (currentCoords.x != hoveredCoords.x || currentCoords.y != hoveredCoords.y) {
                this.clearSelection($cell);
                this.addSelection($cell);
            }
        },

        '.js-field-enemy mouseout': function($el, ev) {
            if (!$(ev.target).closest('.field').length) {
                this.$hoveredCell = false;
                this.clearSelection();
            }
        },

        '.js-field-enemy .field-overlay .cell click': function($el) {
            if (!this.myTurn) return;

            var row = parseInt($el.parent().data('row'));
            var col = parseInt($el.data('col'));

            $.ajax({
                url: APP.Helpers.url('api-shot', APP.Helpers.getGameParams()),
                method: 'post',
                dataType: 'json',
                data: {
                    y: row,
                    x: col
                },
                success: function(data) {
                    if (data.success) {
                        this.getStatus();
                    } else {
                        alert(data.message);
                    }
                }.bind(this)
            });
        },

        getStatus: function() {
            $.ajax({
                url: APP.Helpers.url('api-status', APP.Helpers.getGameParams()),
                method: 'post',
                dataType: 'json',
                success: function(data) {
                    if (data.success) {
                        this.applyStatus(data);
                    } else {
                        alert(data.message);
                    }
                }.bind(this)
            });
        },

        applyStatus: function(data) {
            this.applyPlacementStatus(this.$fieldMyGraphics,    data.fieldMy,    this.placeMyShips.bind(this));
            this.applyPlacementStatus(this.$fieldEnemyGraphics, data.fieldEnemy, this.placeEnemyShips.bind(this));

            this.showDamage(this.element.find('.js-damage-my'),    data.fieldMy);
            this.showDamage(this.element.find('.js-damage-enemy'), data.fieldEnemy);

            if (!this.myTurn && data.game.myTurn) {
                APP.Helpers.alert('— Твой ход, тысяча чертей!');
            }
            this.myTurn = data.game.myTurn;

            if (data.game.status == APP.Statuses.FINISHED) {
                if (this.myTurn) {
                    alert('Вы выиграли!!');
                } else {
                    alert('Вы проиграли :(');
                }
            } else {
                if (!this.myTurn) {
                    setTimeout(function () {
                        this.getStatus();
                    }.bind(this), 5000);
                }
            }
        },

        applyPlacementStatus: function($field, field, placeShips) {
            var ships = {};
            var x, y, $cell, content, visibility;

            for (x = 0; x < APP.Field.SIZE; x++) {
                for (y = 0; y < APP.Field.SIZE; y++) {
                    $cell = $field.find('[data-row=' + y + '] [data-col=' + x + ']');
                    $cell.html('');
                    content = field[x][y][0];
                    visibility = field[x][y][1];

                    if (content == 'empty' && !visibility) {
                        $cell.html('');
                    } else if (content == 'empty' && visibility) {
                        $cell.html(this.getCellContent('miss'));
                    } else if (content == 'hidden') {
                        $cell.html('');
                    } else {
                        if (content != 'hidden' && content != 'empty') {
                            if (!ships[content]) ships[content] = [];
                            ships[content].push([x, y]);
                        }

                        if (visibility) {
                            $cell.html(this.getCellContent('hit'));
                        }
                    }
                }
            }

            placeShips($field, ships);
        },

        placeMyShips: function($field, ships) {
            var ship, x, y, $cell;
            for (ship in ships) {
                if (!ships.hasOwnProperty(ship)) continue;

                x = ships[ship][0][0];
                y = ships[ship][0][1];
                $cell = $field.find('[data-row=' + y + '] [data-col=' + x + ']');
                $cell.prepend(this.getShipHtml(ship, ships[ship]));
            }
        },

        placeEnemyShips: function($field, ships) {
            var ship, x, y, $cell;
            for (ship in ships) {
                if (!ships.hasOwnProperty(ship)) continue;

                for (var i = 0; i < ships[ship].length; i++) {
                    x = ships[ship][i][0];
                    y = ships[ship][i][1];
                    $cell = $field.find('[data-row=' + y + '] [data-col=' + x + ']');
                    $cell.addClass('black');
                }
            }
        },

        getCellContent: function(type) {
            switch (type) {
                case 'empty': return '<span class="sprite-place"><span class="miss"></span></span>';
                case 'miss': return '<span class="sprite-place"><span class="miss"></span></span>';
                case 'hidden': return '<span class="sprite-place"><span class="hidden"></span></span>';
                case 'hit': return '<span class="sprite-place"><span class="hit"></span></span>';
                default: {
                    return '';
                }
            }
        },

        getShipHtml: function(type, data) {
            var pos = 'r';
            if (data.length > 1 && data[0][1] != data[1][1]) pos = 'l';

            var className = 'ship-' + type[0] + '-' + pos;
            var params = '';
            params += ' data-type="' + type + '"';
            params += ' data-orientation="' + (pos == 'r' ? 'horizontal' : 'vertical') + '"';
            return '<span class="sprite-place"><span class="ship ' + className + '" ' + params + '></span></span>';
        },

        showDamage: function($container, field) {
            var x, y, content, visibility, $ship;

            $container.find('.hit').removeClass('hit');

            for (x = 0; x < APP.Field.SIZE; x++) {
                for (y = 0; y < APP.Field.SIZE; y++) {
                    content = field[x][y][0];
                    visibility = field[x][y][1];

                    if (visibility && content != 'empty') {
                        $ship = $container.find('.ship-dmg[data-type=' + content + ']');
                        $ship.find('i:not(.hit)').eq(0).addClass('hit');
                    }
                }
            }

            var percent = $container.find('.hit').length / $container.find('i').length * 100;
            $container.find('.js-percent').html(Math.round(percent));
        },

        clearSelection: function($cell) {
            var $all = this.$fieldEnemyOverlay.find('.cell');
            if ($cell) {
                $all = $all.not($cell);
            }
            $all.removeClass('selection-row').find('.selection, .js-tooltip').remove();
        },

        addSelection: function($cell) {
            this.$hoveredCell = $cell;

            $cell.addClass('selection-row');
            $cell.append('<span class="selection"></span>');
            var y = parseInt($cell.parent().data('row'));
            var x = parseInt($cell.data('col'));

            for (var i = 0; i < x; i++) {
                this.$fieldEnemyOverlay.find('[data-row=' + y + '] [data-col=' + i + ']').addClass('selection-row');
            }
            for (var j = 0; j < y; j++) {
                this.$fieldEnemyOverlay.find('[data-row=' + j + '] [data-col=' + x + ']').addClass('selection-row');
            }

            var letter = $cell.closest('.battle-cube').find('.line.letters').children().eq(x).text();
            var textCoords = (letter + y).toUpperCase();
            $cell.append('<span class="sprite-place js-tooltip"><span class="tooltip">' + textCoords + ' - Пли!</span></span>');
        },

        getCellCoords: function($cell) {
            if (!$cell || !$cell.length) return {x: -1, y: -1};
            var y = parseInt($cell.parent().data('row'));
            var x = parseInt($cell.data('col'));
            return {x: x, y: y};
        }
    });

})(jQuery, window.APP);