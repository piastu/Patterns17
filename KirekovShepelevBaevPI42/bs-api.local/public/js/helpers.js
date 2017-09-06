(function($, APP) {
    'use strict';

    /**
     * Контроллер приложения, запускает контроллеры страниц
     **/
    APP.Urls = {
        'placement': '/placement/#id#/#code#',
        'game':      '/game/#id#/#code#',

        'api-start':       '/api/start/',
        'api-status':      '/api/status/#id#/#code#',
        'api-clear-field': '/api/clear-field/#id#/#code#',
        'api-place-ship':  '/api/place-ship/#id#/#code#',
        'api-ready':       '/api/ready/#id#/#code#',
        'api-shot':        '/api/shot/#id#/#code#',
        'api-chat-load':   '/api/chat-load/#id#/#code#',
        'api-chat-send':   '/api/chat-send/#id#/#code#'
    };

    APP.Statuses = {
        NEW:      1,
        GAMING:   2,
        FINISHED: 3
    };

    APP.Field = {
        SIZE: 10
    };

    APP.Helpers.url = function(name, params, isDomain) {
        if (typeof isDomain === 'undefined') isDomain = true;
        var domain = isDomain && localStorage && localStorage.domain ? localStorage.domain : '';
        var url = APP.Urls[name];
        if (!url) return domain + '/';

        for (var i in params) {
            if (!params.hasOwnProperty(i)) continue;

            url = url.replace('#' + i + '#', params[i]);
        }

        return domain + url;
    };

    APP.Helpers.getGameParams = function() {
        var route = window.location.href;
        var parts = route.split('/');

        if (parts[parts.length - 1] == '') parts.pop();
        return {
            id: parts[parts.length - 2],
            code: parts[parts.length - 1]
        };
    };

    APP.Helpers.ajaxGet = function(url, data, callback) {
        $.ajax({
            url: APP.Helpers.url(url, APP.Helpers.getGameParams()),
            method: 'get',
            dataType: 'json',
            data: data,
            success: function(data) {
                if (callback) callback(data);
            }
        });
    };

    APP.Helpers.ajaxPost = function(url, data, callback) {
        $.ajax({
            url: APP.Helpers.url(url, APP.Helpers.getGameParams()),
            method: 'post',
            dataType: 'json',
            data: data,
            success: function(data) {
                if (callback) callback(data);
            }
        });
    };

    APP.Helpers.randomElement = function(arr) {
        var len = arr.length;
        var index = Math.floor(Math.random() * len);
        return arr[index];
    };

    APP.Helpers.alert = function(message) {
        var $alert = $('<div class="alert-block"></div>');
        $alert.html('<div class="btn big">' + message + '</div>');
        $('body').append($alert);

        setTimeout(function() {
            $alert.remove();
        }, 2000);
    };

    /**
     *
     */
    APP.Helpers.randomizer = {

        ships: [
            '4-1',
            '3-1', '3-2',
            '2-1', '2-2', '2-3',
            '1-1', '1-2', '1-3', '1-4'
        ],

        shipLengths: {
            '1-1': 1,
            '1-2': 1,
            '1-3': 1,
            '1-4': 1,
            '2-1': 2,
            '2-2': 2,
            '2-3': 2,
            '3-1': 3,
            '3-2': 3,
            '4-1': 4
        },

        getRandomPlacement: function() {
            var i, x, y, ship;
            var usedPlaces = [];
            for (x = 0; x < APP.Field.SIZE; x++) {
                usedPlaces[x] = [];
                for (y = 0; y < APP.Field.SIZE; y++) {
                    usedPlaces[x][y] = false;
                }
            }

            var sendData = [];

            for (i = 0; i < this.ships.length; i++) {
                ship = this.ships[i];
                var availablePlacements = [];

                for (x = 0; x < APP.Field.SIZE; x++) {
                    for (y = 0; y < APP.Field.SIZE; y++) {
                        if (this.checkPlacementAvailable(usedPlaces, x, y, this.shipLengths[ship], 'horizontal')) {
                            availablePlacements.push({ship: ship, x: x, y: y, orientation: 'horizontal'});
                        }
                        if (this.checkPlacementAvailable(usedPlaces, x, y, this.shipLengths[ship], 'vertical')) {
                            availablePlacements.push({ship: ship, x: x, y: y, orientation: 'vertical'});
                        }
                    }
                }

                if (!availablePlacements.length) {
                    alert('cant place');
                    return;
                }

                var placement = APP.Helpers.randomElement(availablePlacements);
                usedPlaces = this.fillUsedPlaces(usedPlaces, placement);
                sendData.push(placement);
            }

            return sendData;
        },

        checkPlacementAvailable: function(field, x, y, length, orientation) {
            var lenX = (orientation == 'horizontal') ? length : 1;
            var lenY = (orientation != 'horizontal') ? length : 1;
            var sx, sy;
            for (sx = x; sx < x + lenX; sx++) {
                if (sx >= APP.Field.SIZE) return false;
                for (sy = y; sy < y + lenY; sy++) {
                    if (sy >= APP.Field.SIZE) return false;
                    if (field[sx][sy] === true) return false;
                }
            }

            return true;
        },

        fillUsedPlaces: function(field, placement) {
            var newField = [];
            var x, y;
            var minX = placement.x - 1;
            var minY = placement.y - 1;
            var maxX = placement.x + ((placement.orientation == 'horizontal') ? this.shipLengths[placement.ship] : 1);
            var maxY = placement.y + ((placement.orientation == 'vertical')   ? this.shipLengths[placement.ship] : 1);

            for (x = 0; x < APP.Field.SIZE; x++) {
                newField[x] = [];
                for (y = 0; y < APP.Field.SIZE; y++) {
                    newField[x][y] = field[x][y];
                }
            }

            for (x = minX; x <= maxX; x++) {
                if (x < 0 || x >= APP.Field.SIZE) continue;
                for (y = minY; y <= maxY; y++) {
                    if (y < 0 || y >= APP.Field.SIZE) continue;
                    newField[x][y] = true;
                }
            }

            return newField;
        }
    };

})(jQuery, window.APP);