(function($, APP) {
    'use strict';
    
    /**
     * Расположение кораблей
     **/
    APP.Controls.Page.Placement = can.Control.extend({

        lastState: {},
        meReady: false,

        currentDrag: false,
        timeoutWait: false,

        /**
         *
         **/
        init: function() {
            this.$shipsPanel = this.element.find('.ships-panel');
            this.$battlefield = this.element.find('.battle-cube');

            this.getStatus();

            new APP.Controls.Partial.Chat(this.element.find('.js-chat'));
        },

        '.ships-panel .ship mousedown': function($el) {
            this.$battlefield.find('.ship[data-type=' + $el.data('type') + ']').css('opacity', 0.3);
            this.currentDrag = $el;
        },

        '.battle-cube .ship mousedown': function($el) {
            $el.css('opacity', 0.3);
            this.currentDrag = $el;
        },

        '.battle-cube .cell mousemove': function($el) {
            if (this.currentDrag) {
                this.hoverShip($el, this.currentDrag);
            }
        },

        '.battle-cube .cell mouseup': function($el, ev) {
            if (this.currentDrag) {
                this.placeShip($el, this.currentDrag);
                this.currentDrag = false;
                this.hoverShip();
                ev.stopPropagation();
            }
        },

        'mouseup': function() {
            if (this.currentDrag && this.currentDrag.closest(this.$battlefield)) {
                // Унесли корабль с поля - удалить его
                this.clearShip(this.currentDrag);
            }
            this.currentDrag = false;
            this.hoverShip();
        },

        '.js-random click': function() {
            this.clearField(
                this.randomPlacement.bind(this)
            );
        },

        '.js-clear click': function() {
            this.clearField(
                this.getStatus.bind(this)
            );
        },

        '.js-copy click': function() {
            var $link = this.element.find('.header .share .link');
            var range = document.createRange();
            range.selectNode($link.get(0));
            window.getSelection().addRange(range);

            try {
                document.execCommand('copy');
            } catch (e) { }

            window.getSelection().removeAllRanges();
        },

        '.js-ready click': function() {
            this.setMeReady();
        },

        '.field .cell click': function($el) {
            if ($el.find('.ship')) {
                this.rotateShip($el.find('.ship'));
            }
        },

        rotateShip: function($ship) {
            if ($ship.hasClass('process')) return;

            $ship.addClass('process');
            var orientation = $ship.data('orientation');
            $ship.data('orientation', orientation == 'vertical' ? 'horizontal' : 'vertical');
            this.placeShip($ship.closest('.cell'), $ship);
        },

        placeShip: function($cell, $ship) {
            var params = {
                x: parseInt($cell.data('col')),
                y: parseInt($cell.parent().data('row')),
                ship: $ship.data('type'),
                orientation: $ship.data('orientation')
            };

            APP.Helpers.ajaxPost('api-place-ship', params,
                function(data) {
                    if (data.success) {
                        this.getStatus()
                    } else {
                        alert(data.message);
                        this.element.find('.process').removeClass('process');
                    }
                }.bind(this)
            );
        },

        getStatus: function() {
            APP.Helpers.ajaxPost('api-status', {}, function(data) {
                if (data.success) {
                    this.applyStatus(data);
                } else {
                    alert(data.message);
                }
            }.bind(this));
        },

        applyStatus: function(data) {
            this.lastState = data;
            this.meReady = data.game.meReady;
            this.applyPlacement(data.fieldMy, data.usedPlaces);
            this.showInvite(data.game.id, data.game.invite);

            if (this.meReady) {
                this.element.find('.js-ready').hide();
                this.element.find('.js-wait').show();

                if (!this.timeoutWait) {
                    this.waitTimeout();
                }
            }
        },

        applyPlacement: function(field, usedPlaces) {
            var ships = {};
            var x, y, ship, $cell, type, content, visibility;

            for (x = 0; x < APP.Field.SIZE; x++) {
                for (y = 0; y < APP.Field.SIZE; y++) {
                    $cell = this.element.find('[data-row=' + y + '] [data-col=' + x + ']');
                    $cell.html('');
                    content = field[x][y][0];
                    visibility = field[x][y][1];

                    if (content && content != 'empty') {
                        // Корабль
                        if (!ships[content]) ships[content] = [];
                        ships[content].push([x, y]);
                    }
                }
            }

            for (ship in ships) {
                if (!ships.hasOwnProperty(ship)) continue;

                x = ships[ship][0][0];
                y = ships[ship][0][1];
                $cell = this.element.find('[data-row=' + y + '] [data-col=' + x + ']');
                $cell.html(this.getShipHtml(ship, ships[ship]));
            }

            this.$shipsPanel.find('.used').removeClass('used');
            for (ship in usedPlaces) {
                if (!usedPlaces.hasOwnProperty(ship)) continue;
                var $ship = this.$shipsPanel.find('.ship[data-type=' + usedPlaces[ship] + ']');
                $ship.addClass('used');
            }

            if (this.$shipsPanel.find('.ship:not(.used)').length == 0) {
                this.element.find('.js-ready').prop('disabled', false);
            } else {
                this.element.find('.js-ready').prop('disabled', true);
            }
        },

        getCellContent: function(type) {
            switch (type) {
                case 'empty': return '<span class="sprite-place"><span class="miss"></span></span>';
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

        waitTimeout: function() {
            this.timeoutWait = setTimeout(function() {
                APP.Helpers.ajaxPost('api-status', { short: 1 }, function(data) {
                    if (data.game.status == APP.Statuses.GAMING) {
                        window.location.href = APP.Helpers.url('game', APP.Helpers.getGameParams(), false);
                    } else {
                        this.waitTimeout();
                    }
                }.bind(this));
            }.bind(this), 5000);
        },

        setMeReady: function() {
            APP.Helpers.ajaxPost('api-ready', {}, function(data) {
                if (!data.success) {
                    alert(data.message);
                    return;
                }

                if (data.enemyReady) {
                    window.location.href = APP.Helpers.url('game', APP.Helpers.getGameParams(), false);
                } else {
                    this.waitTimeout();
                }
            }.bind(this));

            this.element.find('.js-ready').hide();
            this.element.find('.js-wait').show();
        },

        showInvite: function(id, invite) {
            var $share = this.element.find('.header .share');
            $share.show();

            var link = window.location.origin + '/placement/' + id + '/' + invite;
            $share.find('.link').html(link);
        },

        clearShip: function($ship) {
            APP.Helpers.ajaxPost(
                'api-place-ship',
                { ship: $ship.data('type') },
                function () {
                    this.getStatus();
                }.bind(this)
            );
        },

        clearField: function(callback) {
            this.$shipsPanel.find('.ship.used').removeClass('used');

            APP.Helpers.ajaxPost('api-clear-field', {}, function () {
                if (callback) callback();
            });
        },

        randomPlacement: function() {
            // Отправить данные
            APP.Helpers.ajaxPost(
                'api-place-ship',
                { ships: APP.Helpers.randomizer.getRandomPlacement() },
                function () {
                    this.getStatus();
                }.bind(this)
            );
        },

        hoverShip: function($centerCell, $ship) {
            this.$battlefield.find('.cell').removeClass('hovered');
            if (!$centerCell || !$ship) return;

            var type = $ship.data('type');
            var length = parseInt(type[0], 10);
            var x, y, $cell;
            var orientation = $ship.data('orientation');
            var minX = $centerCell.data('col');
            var minY = $centerCell.parent().data('row');
            var maxX = minX + ((orientation == 'horizontal') ? length : 1);
            var maxY = minY + ((orientation == 'vertical')   ? length : 1);


            for (x = minX; x < maxX; x++) {
                for (y = minY; y < maxY; y++) {
                    $cell = this.$battlefield.find('[data-row=' + y + '] [data-col=' + x + ']');
                    $cell.addClass('hovered');
                }
            }
        }
    });

})(jQuery, window.APP);