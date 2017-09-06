'use strict';
var tableEnemy;

function startGame(fieldMy, keysTwoDim, $page) {

    // инициализация игрока
    var tablePlayer = initTableGame(getTableJQuery('player', $page));
    var shipsPlayer = initShips(getShipsJQuery('player', $page), tablePlayer);
    placeShipsGame(shipsPlayer, fieldMy, tablePlayer.getCells());


    // инициализация противника
    tableEnemy = initTableGame(getTableJQuery('enemy', $page));
    var shipsEnemy = initShips(getShipsJQuery('enemy', $page), tableEnemy);


    prepareCells(tablePlayer.getCells());
    prepareCells(tableEnemy.getCells(), true);

    return tablePlayer;


    function initTableGame(tableLettersNums) {
        var tablePlayer = new Table(tableLettersNums['$grid'], tableLettersNums['$letters'], tableLettersNums['$nums']);
        tablePlayer.initCells();
        return tablePlayer;
    }

    function initShips($ships, table) {
        var ships = [];
        for (var i = 0; i < $ships.length; i++) {
            ships.push(new Ship($ships.eq(i), table));
        }
        return ships;
    }


    function placeShipsGame(ships, field, cells) {
        for (var i = field.length - 1; i >= 0; i--) {
            for (var j = field[i].length - 1; j >= 0; j--) {
                var cellShip = field[i][j][0];
                var ship;
                if (cellShip !== 'empty') {

                    var cell = cells[keysTwoDim[j][i]];            // таблица на сервере транспонирована по отношению к таблице на клиенте
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
                ship = cells[keysTwoDim[i][j]].getShipOnCell();
                if (ship !== false && shipsPlaced.indexOf(ship) === -1) {
                    shipsPlaced.push(ship);
                    placeOneShip(ship, i, j);
                }
            }
        }

        function placeOneShip(ship, i, j) {
            // сначала проверим, на какой оси находится корабль
            // из названия корабля узнаем его размер
            console.log('ship = ' + ship);
            var size = ship.shipName.split('-')[0];

            var rotate_angle = 'horizontal';
            for (var k = 0; k < size; k++) {

                if (k + j >= keysTwoDim.length || cells[keysTwoDim[i][j + k]].getShipOnCell() !== ship) {
                    rotate_angle = 'vertical';
                    break;
                }

            }
            ship.setShipOnCurrentCells(rotate_angle);
        }
    }


    function getTableJQuery(playerOrEnemy, $page) {
        var $tableGrid = $page.find('.js-grid-' + playerOrEnemy);
        var $tableRowLetters = $page.find('.js-row-grid-letters-' + playerOrEnemy);
        var $tableRowNums = $page.find('.js-row-grid-nums-' + playerOrEnemy);

        return {
            $grid: $tableGrid,
            $letters: $tableRowLetters,
            $nums: $tableRowNums
        };
    }

    function getShipsJQuery(playerOrEnemy, $page) {
        return $page.find('.js-ship-game-' + playerOrEnemy);
    }


    // зададим клеткам свойство relative, чтобы было
    // удобнее позиционировать эффекты (взрыв, промах и.т.д.)
    // если клетки вражеские, добавим a cell-enemy для добавления
    // target.png при наведении
    function prepareCells(cells, enemyCells) {
        for (var key in cells) {
            var $cell = $(cells[key].getDomCell());
            $cell.css('position', 'relative');
            if (enemyCells) {
                $cell.on('click', shotAction);
                $cell.addClass('cell-enemy');
            }
        }
    }
}

function getGameStatus(id, code) {
    var status = {};
    $.ajax({
        method: 'POST',
        dataType: 'json',
        url: API_METHODS.apiGetStatus(id, code),
        data: {code: code},
        async: false,

        success: function (data) {
            status['myTurn'] = data['game']['myTurn'];
            status['fieldMy'] = data.fieldMy;
        },

        error: function (data, textStatus, thrown) {
            alert('Error gameStatus. Check console');
            console.log('------ Error gameStatus -------');
            console.log(data);
            console.log(textStatus);
            console.log(thrown);
            console.log('--------------------')
        }
    });
    return status;
}


function shotAction(e) {

    var $target = $(e.target);
    var x = +$target.attr('data-x');
    var y = +$target.attr('data-y');

    $.ajax({
        method: 'POST',
        async: false,
        url: API_METHODS.apiShot(idGame, codeGame),
        data: {x: y, y: x},

        success: function (data) {

            var result = JSON.parse(data);
            if (!result.success) {
                alert(result.message);
                //console.log(result);
                return null;
            }

            shotGlobalEvent(result['hit'], tableEnemy, $target, x, y, result['kill']);

            console.log(result);
        },
        error: function (data, textStatus, thrown) {
            alert('Error shotAction. Check console');
            console.log('------ Error shotAction -------');
            console.log(data);
            console.log(textStatus);
            console.log(thrown);
            console.log('--------------------')
        }
    });
}

// объединяет функции накладывания эффекта выстрела/промаха
// и появления круглых точек вокруг корабля
function shotGlobalEvent(hit, tablePlayerOrEnemy, $targetCell, x, y, isKill) {
    var cellMarkedOrKilled;

    var hitOrMiss;
    if (hit) {
        cellMarkedOrKilled = function () {
            killEffect($targetCell);
        };
        hitOrMiss = 'hit';
        tablePlayerOrEnemy.getCellByCoordinate(x, y).setDestroyed();
    }
    else {
        cellMarkedOrKilled = function () {
            setCellMarked($targetCell);
        };
        hitOrMiss = 'miss';
    }


    shotActionEffect($targetCell, function () {
        cellMarkedOrKilled();
        if (isKill) {
            var $nearByCells = tablePlayerOrEnemy.getNearByCells(detectKillCells(x, y, tablePlayerOrEnemy));
            for (var i = 0; i < $nearByCells.length; i++) {
                setCellMarked($nearByCells[i]);
            }
        }
    }, hitOrMiss);


    // точка на клетке (сюда уже стреляли)
    function setCellMarked($target, fadeTime) {
        fadeTime = fadeTime || 700;

        var $mark = $('<div>', {class: 'marked-cell'});
        $mark.appendTo($target);

        $mark.fadeOut(1, function () {
            $mark.fadeIn(fadeTime);
        });

    }


    // взрыв при попадании или всплеск при промахе
    function shotActionEffect($target, callback, hitOrMiss, fadetime) {
        fadetime = fadetime || 1500;

        var $hitOrMissObj = $('<div>', {class: 'fire ' + hitOrMiss});
        $hitOrMissObj.appendTo($target);

        // при клике убираем метку, которая появляется при наведении на клетку,
        // чтобы не закрывала эффект взрыва/промаха
        $target.removeClass('cell-enemy');

        $hitOrMissObj.fadeOut(1, function () {
            $hitOrMissObj.fadeIn(fadetime / 2, function () {
                $hitOrMissObj.fadeOut(fadetime, function () {
                    if (callback) {
                        callback();
                    }
                    // после добавляем обратно
                    $target.addClass('cell-enemy');
                });
            });
        });
    }

    // закрашиваем клетки в черный при уничтожении корабля
    function killEffect($target, fadetime) {
        fadetime = fadetime || 500;
        $target.animate(
            {backgroundColor: 'black'},
            fadetime
        );
    }

    // вовзращает координаты клеток уничтоженного корабля
    // x, y - координаты клетки, где свойсвтво kill в событии от сервера равно true
    function detectKillCells(x, y, tablePlayerOrEnemy) {
        var killCells = [];
        var temp = [];
        temp.push(getKillCellsThroughAxis(x, 'x', 1));
        temp.push(getKillCellsThroughAxis(y + 1, 'y', 1));
        temp.push(getKillCellsThroughAxis(y - 1, 'y', -1));
        temp.push(getKillCellsThroughAxis(x - 1, 'x', -1));

        for (var i = 0; i < temp.length; i++) {
            if (temp[i].length) {
                for (var j = 0; j < temp[i].length; j++) {
                    killCells.push(temp[i][j]);
                }
            }
        }
        return killCells.sort();

        function getKillCellsThroughAxis(start, axis, increment) {
            var result = [];
            var isGood = true;
            for (var k = start; ; k += increment) {
                if (k >= 0 && k < 10) {
                    var axisX;
                    var axisY;
                    switch (axis) {
                        case 'x':
                            axisX = k;
                            axisY = y;
                            break;
                        case 'y':
                            axisX = x;
                            axisY = k;
                            break;
                        default:
                            throw "Ошибка getKillCells(): axis может быть 'x' или 'y',\n" +
                            "передано: " + axis;
                            break;
                    }
                    if (isCellDestroyed(axisX, axisY)) {
                        result.push([axisX, axisY]);
                    }
                    else {
                        isGood = false;
                    }
                }
                else {
                    isGood = false;
                }
                if (!isGood) {
                    break;
                }
            }
            return result;
        }
        function isCellDestroyed(x, y) {
            return tablePlayerOrEnemy.getCellByCoordinate(x, y).isDestroyed();
        }
    }
}


// конвертировать многомерный массив в одномерный
function convertToSimpleArray(array) {
    var res = [];
    for (var i = 0; i < array.length; i++) {
        if (!Array.isArray(array[i])) {
            res.push(array[i]);
        }
        else {
            res = res.concat(convertToSimpleArray(array[i]));
        }
    }
    return res;
}



