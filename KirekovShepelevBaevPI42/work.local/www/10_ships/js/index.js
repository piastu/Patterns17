'use strict';

var idGame;
var codeGame;
var inviteCodeGame;

$(document).ready(function () {


    var self = this;
    var table;
    var ships;
    var cells;
    var keysTwoDim;

    var tablePlayer;

    var currUrl = window.location['href'];

    var $page = $(document.body);

    // если игрок открывает игру в первый раз, стартуем игру на сервере
    if (currUrl.indexOf('placement') === -1) {
        initStartGameScreen();
        initButtonStart();
        $page.find('.js-place-your-ships').on('click', function () {
            $page.find('.js-place-your-ships-block').eq(0).hide(1000);
            start();
            initTable();
            initShips();
        });
    }
    // иначе - загружаем состояние с сервера
    else {

        var errorUrl = function () {
            alert('Ошибка в URL, либо игры с таким ID не сущесвует\n' +
                'Сайт перенаправит вас на страницу с новым игровым сеансом');
            window.location.href = rootUrl.join('/') + '/';
        };

        var splitCurrUrl = currUrl.split('/');
        var rootUrl = [];
        var gameUrl = [];

        var isRoot = true;
        for (var i = 0; i < splitCurrUrl.length; i++) {
            if (splitCurrUrl[i] !== 'placement' && isRoot) {
                rootUrl.push(splitCurrUrl[i]);
            }
            else {
                isRoot = false;
                gameUrl.push(splitCurrUrl[i]);
            }
        }

        console.log(rootUrl);
        console.log(gameUrl);

        // теперь проверим, что gameUrl написаны верно
        var isGameUrl = true;
        if (!regexGameUrlCheck(gameUrl)) {
            isGameUrl = false;
            errorUrl();
        }

        // теперь проверим , что в базе есть игра с таким id и code

        var id = gameUrl[1];
        var code = gameUrl[2];

        var fieldMy;

        var ajaxLoadGame = function () {
            return $.ajax({
                method: 'POST',
                url: API_METHODS.apiGetStatus(id, code),
                dataType: 'json',
                data: {code: code},

                success: function (data) {
                    console.log(data);
                    // игра с кодом, указаным в url существует
                    // загрузим корабли из нее
                    if (data.success) {
                        idGame = id;
                        codeGame = code;
                        inviteCodeGame = data.game.invite;
                        //console.log('id = ' + idGame + ', codeGame = ' + codeGame + ', invite = ' + inviteCodeGame);
                        fieldMy = data.fieldMy;
                        //loadGame(data.fieldMy);
                    }
                    // url не правильный
                    else {
                        //alert('no');
                        isGameUrl = false;
                    }
                },

                error: function (data, textStatus, thrown) {
                    alert('Error Urlcode. Check console');
                    console.log('------ Error UrlCode -------');
                    console.log(data);
                    console.log(textStatus);
                    console.log(thrown);
                    console.log('--------------------')
                }
            });
        };

        if (isGameUrl) {
            // нужно для того, чтобы ajax запрос гарантировано выполнялся первым
            ajaxLoadGame().then(function () {

                if (!isGameUrl) {
                    errorUrl();
                }
                else {
                    loadGame(fieldMy);
                }
            })
        }


        //'http://work.local/10_ships/placement/129/xu9dutZfOP';
    }

    function initStartGameScreen() {
        $page.find('#actionGameScreen').css('display', 'none');
    }

    function initActionGameScreen() {
        $page.find('#startGameScreen').css('display', 'none');
        $page.find('#actionGameScreen').css('display', 'block');
    }

    function gameStarted() {
        var currentTurn = null;
        var currentFieldMy = null;
        var intervalStatus = setInterval(function () {
            var status = getGameStatus(idGame, codeGame);
            if (status['myTurn'] && currentTurn !== status['myTurn']) {
                console.log('Твой ход!');
                currentTurn = true;
            }
            else if (!status['myTurn'] && currentTurn !== status['myTurn']) {
                console.log('Ход противника');
                currentTurn = false;
            }

            // установка эффектов взрыва/промаха на поле игрока (своем)
            if (currentFieldMy === null) {
                currentFieldMy = status['fieldMy'];
            }
            else {
                for (var i = 0; i < currentFieldMy.length; i++)
                {
                    for (var j = 0; j < currentFieldMy[i].length; j++)
                    {
                        var currentMyCell = currentFieldMy[i][j];
                        var myCell = status['fieldMy'][i][j];

                        // если в клетку выстрелили и мы это еще не обрабатывали
                        if (myCell[1] && currentMyCell[1] !== myCell[1]) {
                            var $targetCell = $(tablePlayer.getCellByCoordinate(j, i).getDomCell());

                            // противник промахнулся
                            if (myCell[0] === 'empty') {
                                shotGlobalEvent(false, tablePlayer, $targetCell, j, i);
                            }
                            // попал
                            else {
                                shotGlobalEvent(true, tablePlayer, $targetCell, j, i);
                            }
                        }
                    }
                }
                currentFieldMy = status['fieldMy'];
            }

            //console.log(status['fieldMy']);

        }, 2000);

    }


    function initButtonStart() {
        $page.find('.js-wait-for-your-enemy-block').eq(0).hide(1);
        var $startGame = $page.find('.js-start-game');
        $startGame.removeClass('not-active');
        $startGame.on('click', function () {
            if (confirm('Вы уверены в своем выборе?\nПосле принятия готовности положение кораблей нельзя будет изменить.')) {
                $page.find('.js-wait-for-your-enemy-block').show(500);
                $startGame.hide(500);

                setTimeout(function () {
                    setPlayerReady();
                }, 2000);


                var clear = setInterval(function run() {
                    var check = checkPlayerReady();
                    console.log(check);
                    if (check['isEnemyReady']) {
                        clearInterval(clear);
                        alert('Ура! Второй игрок готов!');
                        initActionGameScreen();
                        tablePlayer = startGame(check['fieldMy'], keysTwoDim, $page);
                        gameStarted();
                    }
                }, 3000);

            }
        });

        function setPlayerReady() {
            $.ajax({
                method: 'POST',
                async: false,
                url: API_METHODS.apiPlayerReady(idGame, codeGame),
                dataType: 'json',
                data: {code: codeGame},

                success: function (data) {
                    console.log(data);
                },

                error: function (data, textStatus, thrown) {
                    alert('Error setPlayerReady. Check console');
                    console.log('------ Error setPlayerReady -------');
                    console.log(data);
                    console.log(textStatus);
                    console.log(thrown);
                    console.log('--------------------')
                }

            });
        }

        function checkPlayerReady() {
            var isEnemyReady;
            var fieldMy;
            var fieldEnemy;
            $.ajax({
                method: 'POST',
                async: false,
                url: API_METHODS.apiGetStatus(idGame, codeGame),
                dataType: 'json',
                data: {code: codeGame},

                success: function (data) {
                    isEnemyReady = +data.game.status === +gameStatus()['STATUS_GAMING'];
                    console.log('isEnemyReady = ' + isEnemyReady);
                    fieldMy = data.fieldMy;
                    fieldEnemy = data.fieldEnemy;
                },

                error: function (data, textStatus, thrown) {
                    alert('Error checkPlayerReady. Check console');
                    console.log('------ Error checkPlayerReady -------');
                    console.log(data);
                    console.log(textStatus);
                    console.log(thrown);
                    console.log('--------------------')
                }

            });

            return {
                isEnemyReady: isEnemyReady,
                fieldMy: fieldMy,
                fieldEnemy: fieldEnemy
            };
        }

    }


    function loadGame(fieldMy) {
        initStartGameScreen();
        // в случае загрузки кораблей с сервера убираем кнопку "начать игру"
        $page.find('.js-place-your-ships-block').eq(0).hide(1);
        initTable();
        initShips();
        initButtonStart();
        // сначала загрузим данные о кораблях в инстансы классов Ship и TableCell
        for (var i = fieldMy.length - 1; i >= 0; i--) {
            for (var j = fieldMy[i].length - 1; j >= 0; j--) {
                var cellShip = fieldMy[i][j][0];
                var ship;
                if (cellShip !== 'empty') {

                    var cell = cells[keysTwoDim[j][i]];    // таблица на сервере транспонирована по отношению к таблице на клиенте
                    for (var k = 0; k < ships.length; k++) {
                        if (ships[k].shipName === cellShip) {
                            ship = ships[k];
                            ship.addCell(cell);
                            break;
                        }
                    }
                    cell.setShipOnCell(ship);
                }
            }
        }


        var shipsPlaced = [];
        // теперь расположим картинки кораблей на поле
        for (i = 0; i < keysTwoDim.length; i++) {

            for (j = 0; j < keysTwoDim[i].length; j++) {

                try {
                    ship = cells[keysTwoDim[i][j]].getShipOnCell();
                    if (ship !== false && shipsPlaced.indexOf(ship) === -1) {
                        shipsPlaced.push(ship);
                        placeShip(ship, i, j);
                    }
                }
                catch (err) {
                    console.log(err);
                    console.log(cells);
                    console.log(fieldMy);
                    throw 'stop';
                }


            }
        }

        function placeShip(ship, i, j) {
            // сначала проверим, на какой оси находится корабль
            // из названия корабля узнаем его размер
            var size = ship.shipName.split('-')[0];
            console.log(size);

            var rotate_angle = 'horizontal';
            for (var k = 0; k < size; k++) {

                if (k + j >= keysTwoDim.length || cells[keysTwoDim[i][j + k]].getShipOnCell() !== ship) {
                    rotate_angle = 'vertical';
                    break;
                }

            }
            ship.setShipOnCurrentCells(rotate_angle);
        }


        self.isPlaced();
    }

    function regexGameUrlCheck(gameUrl) {
        var regex = [/placement/, /\d+/, /\w+/];

        if (gameUrl.length !== 3) {
            return false
        }

        for (var i = 0; i < gameUrl.length; i++) {
            if (!regex[i].test(gameUrl[i])) {
                return false
            }
        }
        return true;
    }

    function initClipboard(destination) {
        new Clipboard('.js-invite-image');
        $page.find('.js-invite-friend')
            .attr('href', destination)
            .html(destination);
        $page.find('.js-invite-image').attr('data-clipboard-text', destination);
    }

    this.isPlaced = function () {
        var isAllShipsArePlaced = true;
        for (var i = 0; i < ships.length; i++) {
            if (!ships[i].ajaxIsShipPlaced()) {
                isAllShipsArePlaced = false;
                break;
            }
        }

        if (isAllShipsArePlaced) {
            $page.find('.js-start-game').removeClass('not-ready');
        }
        else {
            $page.find('.js-start-game').addClass('not-ready');
        }
    };


    function start() {
        // старт игры
        $.ajax({
            url: API_METHODS.apiStart(),
            dataType: 'json',
            method: 'POST',
            success: function (data) {
                idGame = data['id'];
                codeGame = data['code'];
                inviteCodeGame = data['invite'];

                var currUrl = window.location['href'];
                history.replaceState({}, 'title', currUrl + 'placement/' + idGame + '/' + codeGame);
                var destination = window.location['href'].slice(0, window.location['href'].length - codeGame.toString().length) + inviteCodeGame;
                initClipboard(destination);
            }
        });

    }


    function initTable() {
        // инициализация таблицы-поля
        table = new Table($page.find(".js-table-grid"), $page.find(".js-row-grid-letters"), $page.find(".js-row-grid-nums"));
        table.initCells();

        // объекты TableCells таблицы Table
        cells = table.getCells();

        var keys = Object.keys(cells);

        // для удобства разделим ключи ячеек на двумерный массив 10 x 10 (10 строк, в каждой по 10 ячеек)
        keysTwoDim = [];

        for (var u = 0; u < 10; u++) {
            keysTwoDim.push(keys.slice(10 * u, 10 * (u + 1)));
        }


    }

    function initShips() {
        // инициализация кораблей
        var $ships = $page.find('.js-ship');
        ships = [];
        for (var i = 0; i < $ships.length; i++) {
            var ship = new Ship($ships.eq(i), table, self);
            ship.makeShipDraggable();
            ships.push(ship);
        }
    }

    // вернуть все корабли в исходную позицию
    function getShipsBack() {
        for (var i = 0; i < ships.length; i++) {
            ships[i].rotateToNormalAndGetBack();
        }
        ships[0].ajaxClearField();
    }

    // расставить корабли в случайном порядке
    function setShipsRandomPositions() {
        getShipsBack();
        var shipsAjaxPlacement = [];
        for (var i = 0; i < ships.length; i++) {
            shipsAjaxPlacement.push(ships[i].setRandomPosition());
        }
        ships[0].ajaxPlaceAllShips(shipsAjaxPlacement);
    }


    $page.find('.js-get-ships-back').on('click', function () {
        if (confirm('Вы уверены, что хотите вернуть все корабли в начальное положение?')) {
            getShipsBack();
        }
    });


    $page.find('.js-set-ships-random-position').on('click', function () {
        setShipsRandomPositions();
    });


    /*$("#checkShips").click(function () {
            var cells = table.getCells();
            var keys = Object.keys(cells);
            for (var i = 0; i < keys.length; i++) {
                var ship = cells[keys[i]].getShipOnCell();
                var isNearByShip = cells[keys[i]].getShipsNearBy();
                var coord = cells[keys[i]].getCellCoordinates();

                var x = +coord['x'] + 1;
                var y = +coord['y'] + 1;

                if (ship) {
                    console.log(ship);
                    console.log('x, y = (' + x + ', ' + y + ')');
                }

                if (isNearByShip) {
                    console.log('Рядом корабль');
                    console.log('x, y = (' + x + ', ' + y + ')');
                }

            }
        });*/

});


