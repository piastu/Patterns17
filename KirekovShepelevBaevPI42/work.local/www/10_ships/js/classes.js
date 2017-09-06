// класс корабля
function Ship($ship, table, indexPage) {

    this.shipName = $ship.data('id');

    var index = indexPage;

    var self = this;
    // количество клеток, которое занимаем корабль на поле
    var size = $ship.data('size');

    // начальная позиция корабля
    var position = {'top': $ship.css('top'), 'left': $ship.css('left')};

    // объекты TableCells таблицы Table
    var cells = table.getCells();

    var keys = Object.keys(cells);

    // для удобства разделим ключи ячеек на двумерный массив 10 x 10 (10 строк, в каждой по 10 ячеек)
    var keysTwoDim = [];

    for (var u = 0; u < 10; u++) {
        keysTwoDim.push(keys.slice(10 * u, 10 * (u + 1)));
    }

    // клетки на которых находится корабль
    var cellsForShip = [];

    // соседние клетки (в них установлено свойста isShipNearBy = true)
    var nearByCells = [];

    // 'horizontal' - корабль повернут стандартно (как на картинке)
    // 'rotated' - в противоположную.
    var rotate_angle = 'horizontal';

    this.makeShipDraggable = function () {
        // сделать корабль перемещаемым
        $ship.draggable({
            drag: debounce(onDrag, 10),
            stop: onStopDragging
        });
    };

    this.makeShipNotDraggable = function () {
        $ship.draggable = null;
    };

    this.getCellsForShip = function () {
        return cellsForShip;
    };

    function setRotateAngle(rotate) {
        if (rotate === 'horizontal') {
            if (rotate_angle === 'vertical') {
                $ship.removeClass('rotate');
            }
        }
        else if (rotate === 'vertical') {
            if (rotate_angle === 'horizontal') {
                $ship.addClass('rotate');
            }
        }

    }

    // поворот корабля на даблклик
    // при каждом повороте вызываем функцию onStopDragging
    $ship.dblclick(onDblClick);


    // вызвывается при дабл клике
    function onDblClick() {
        rotateShip();
        returnShipBack();
    }

    function rotateShip() {
        if (rotate_angle === 'horizontal') {
            $ship.addClass('rotate');
            rotate_angle = 'vertical';
        }

        else {
            $ship.removeClass('rotate');
            rotate_angle = 'horizontal';
        }
    }

    // вернуть корабль назад и убрать о нем информацию из всех клеток
    function returnShipBack() {
        clearCellsFromShip();
        $ship.animate(position, 500);
    }

    // повернуть корабль в исходное положение и вернуть назад
    this.rotateToNormalAndGetBack = function () {
        if (rotate_angle !== 'horizontal') {
            $ship.removeClass('rotate');
            rotate_angle = 'horizontal';
        }
        returnShipBack();
        index.isPlaced();
    };

    // убрать информацию о корабле из клеток
    function clearCellsFromShip() {

        for (var i = 0; i < cellsForShip.length; i++) {
            cellsForShip[i].onDragOut();
            cellsForShip[i].setShipOnCell(false);
        }
        cellsForShip = [];
        nearByCells = [];
    }

    this.addCell = function (cell) {
        cellsForShip.push(cell);
    };

    // зафиксировать корабль в данном наборе клеток
    function setShipOnCells(centerPositionInCell, speed, alreadySetted) {

        if (!speed) {
            speed = 100;
        }

        // запомним инстанс корабля в данном наборе
        for (var i = 0; i < cellsForShip.length; i++) {
            if (!alreadySetted) {
                cellsForShip[i].setShipOnCell(self);
            }
            cellsForShip[i].onDragOver();
        }

        // в соседние клетки ставим свойства isShipNearBy в true
        nearByCells = getNearByCells();

        // прилипания корабля к клеткам
        $ship.animate(centerPositionInCell, speed);
    }

    function shipPlaced() {
        index.isPlaced();
    }

    this.ajaxIsShipPlaced = function () {
        return cellsForShip.length > 0 ? 1 : 0;
    };

    // получить соседние клетки
    function getNearByCells() {

        var nearCells = [];

        // берем последнюю клетку в массиве, так как добавляются они в обратном порядке
        var cellStartCoordinates = cellsForShip[cellsForShip.length - 1].getCellCoordinates();
        var x = cellStartCoordinates['x'];
        var y = cellStartCoordinates['y'];


        if (rotate_angle === 'horizontal') {

            var cell;

            for (var i = -1; i <= 1; i += 2) {
                for (var j = y - 1; j < y + size + 1; j++) {
                    if (x + i >= 0 && x + i < 10 && j >= 0 && j < 10) {
                        cell = cells[keysTwoDim[x + i][j]];
                        cell.addShipNearBy();
                        nearCells.push(cell);
                    }
                }
            }

            if (y - 1 >= 0) {
                cell = cells[keysTwoDim[x][y - 1]];
                cell.addShipNearBy();
                nearCells.push(cells[keysTwoDim[x][y - 1]]);
            }

            if (y + size >= 0 && y + size < 10) {
                nearCells.push(cells[keysTwoDim[x][y + size]])
            }
        }

        else {
            for (j = -1; j <= 1; j += 2) {
                for (i = x - 1; i < x + size + 1; i++) {
                    if (i >= 0 && i < 10 && y + j >= 0 && y + j < 10) {
                        cell = cells[keysTwoDim[i][y + j]];
                        cell.addShipNearBy();
                        nearCells.push(cell);
                    }
                }
            }

            if (x - 1 >= 0) {
                cell = cells[keysTwoDim[x - 1][y]];
                cell.addShipNearBy();
                nearCells.push(cells[keysTwoDim[x - 1][y]]);
            }

            if (x + size >= 0 && x + size < 10) {
                cell = cells[keysTwoDim[x + size][y]];
                cell.addShipNearBy();
                nearCells.push(cells[keysTwoDim[x + size][y]])
            }
        }

        return nearCells;
    }

    // поставить корабль в случайное место на поле
    this.setRandomPosition = function () {

        // перед использованием необходимо вызвать функцию rotateToNormal,
        // чтобы сбросить текущее положение корабля

        // сначала выберем случайный поворот корабля
        var rotate = ['horizontal', 'vertical'];
        rotate_angle = rotate[Math.floor(0.5 + Math.random())];
        // повернем изображение
        onDblClick();

        var isPlaced = false;

        var centerPositionInCell;

        var shipAjaxObj = {};

        do {
            var i = Math.floor(Math.random() * (9 + 1));
            var j = Math.floor(Math.random() * (9 + 1));

            var cell = cells[keysTwoDim[i][j]];

            var currPos = getShipPosition();              // текущая позиция корабля
            var cellPos = cell.getHoverBlock();           // hoverBlock клетки

            var isGood = checkCells(keysTwoDim, i, j);

            // если набор клеток подходит, запоминаем его
            // иначе, стираем

            if (isGood) {
                centerPositionInCell = getCenterPositionInCell(currPos, cellPos);
                setShipOnCells(centerPositionInCell, 500);
                isPlaced = true;

                var x = rotate_angle === 'horizontal' ? i : i - size + 1;
                var y = rotate_angle === 'vertical' ? j : j - size + 1;

                // отправим данные о корабле на сервер
                //ajaxShipPlacemenToServer(y, x);
                shipAjaxObj = {ship: self.shipName, orientation: rotate_angle, x: y, y: x, code: codeGame};
                shipPlaced();
            }
        } while (!isPlaced);

        return shipAjaxObj;
    };

    this.setShipOnCurrentCells = function (rotate) {
        while (rotate_angle !== rotate) {
            rotateShip();
        }
        $ship.animate(position, 1);
        var centerPositionInCell = getCenterPositionInCell(getShipPosition(), cellsForShip[0].getHoverBlock());
        setShipOnCells(centerPositionInCell, 1, true);

        /*for (var i = 0; i < cellsForShip.length; i++) {
            console.log(cellsForShip[i].getCellCoordinates());
        }
        console.log(t);*/
    };

    // вызывается при движении мышки
    function onDrag() {
        for (var i = 0; i < keysTwoDim.length; i++) {
            for (var j = 0; j < keysTwoDim[i].length; j++) {
                var currPos = getShipPosition();    // текущая позиция корабля
                var cellPos = cells[keysTwoDim[i][j]].getHoverBlock();           // hoverBlock клетки

                if (isShipInCellHoverBlock(currPos, cellPos)) {
                    onHoverCells(i, j);
                    continue;
                }

                if (!cells[keysTwoDim[i][j]].getShipOnCell())
                    cells[keysTwoDim[i][j]].onDragOut();
            }
        }
    }

    // подсветить клетки при наведении
    function onHoverCells(i, j) {
        for (var k = 0; k < size; k++) {

            if (rotate_angle === 'horizontal') {
                if (j - k >= 0) {
                    cells[keysTwoDim[i][j - k]].onDragOver();
                }
                else {
                    break;
                }
            }
            else {
                if (i - k >= 0) {
                    cells[keysTwoDim[i - k][j]].onDragOver();
                }
                else {
                    break;
                }

            }
        }
    }

    // возврашает true, если корабль находится в hoverblock'е клетки
    function isShipInCellHoverBlock(currPos, cellPos) {
        return currPos['top'] >= cellPos['top'] && currPos['top'] <= cellPos['top'] + cellPos['height'] &&
            currPos['left'] >= cellPos['left'] && currPos['left'] <= cellPos['left'] + cellPos['width'];
    }


    // вызывается в момент отпускания мыши при перетаскивании корабля
    function onStopDragging() {
        // сначала очищаем информацию из клеток, в которых до этого стоял корабль
        clearCellsFromShip();
        var centerPositionInCell;
        var isPlaced = false;
        for (var i = 0; i < keysTwoDim.length; i++) {
            for (var j = 0; j < keysTwoDim[i].length; j++) {
                var currPos = getShipPosition();    // текущая позиция корабля
                var cellPos = cells[keysTwoDim[i][j]].getHoverBlock();           // hoverBlock клетки


                // если корабль находится в ховерблоке вдоль оси X и оси Y
                if (isShipInCellHoverBlock(currPos, cellPos)) {

                    var isGood = checkCells(keysTwoDim, i, j);

                    // если набор клеток подходит ставим туда корабль
                    if (isGood) {
                        centerPositionInCell = getCenterPositionInCell(currPos, cellPos);
                        setShipOnCells(centerPositionInCell);
                        isPlaced = true;


                        var x = rotate_angle === 'horizontal' ? i : i - size + 1;
                        var y = rotate_angle === 'vertical' ? j : j - size + 1;

                        // отправим данные о корабле на сервер
                        ajaxShipPlacemenToServer(y, x);
                        shipPlaced();
                    }

                }
                else {
                    // если в клетке, над который в данный момент корабль не находится
                    // лежит инстанс класса этого корабля, убираем его
                    if (cells[keysTwoDim[i][j]].getShipOnCell() === this) {
                        // если данная клетка не занесена в список клеток корабля
                        // или этого списка просто нет
                        if (!cellsForShip.length || cellsForShip.indexOf(cells[keysTwoDim[i][j]]) === -1) {
                            cells[keysTwoDim[i][j]].setShipOnCell(false);
                        }
                    }

                    // возвращаем клетке исходный цвет в том случае, если там нет корабля
                    if (!cells[keysTwoDim[i][j]].getShipOnCell()) {
                        cells[keysTwoDim[i][j]].onDragOut();
                    }

                }

            }
        }

        // если корабль не уставновлен ни в одну клетку,
        // вернем его на исходную позицию
        if (!isPlaced) {
            $ship.animate(position, 450);
            shipPlaced();
        }


    }

    this.ajaxClearField = function () {
        $.ajax({
            method: 'POST',
            url: API_METHODS.apiClearField(idGame, codeGame),
            dataType: 'json',

            success: function (data) {
                //console.log(data);
            },

            error: function (data, textStatus, thrown) {
                console.log('------ Error ClearField -------');
                console.log(data);
                console.log(textStatus);
                console.log(thrown);
                console.log('--------------------')
            }

        });
    };

    function ajaxShipPlacemenToServer(x, y) {
        $.ajax({
            method: 'POST',
            url: API_METHODS.apiPlaceShip(idGame, codeGame),
            dataType: 'json',
            data: {ship: self.shipName, orientation: rotate_angle, x: x, y: y, code: codeGame},

            success: function (data) {
                /*console.log(data);
                console.log('Корабль: ' + +(x + 1) + ', ' + +(y + 1));
                console.log('Rotate: ' + rotate_angle);*/
            },

            error: function (data, textStatus, thrown) {
                console.log('------ Error ShipPlacement -------');
                console.log(data);
                console.log(textStatus);
                console.log(thrown);
                console.log('--------------------')
            }
        });
    }

    this.ajaxPlaceAllShips = function (ships) {
        $.ajax({
            method: 'POST',
            url: API_METHODS.apiPlaceShip(idGame, codeGame),
            dataType: 'json',
            data: {ships: ships},

            success: function (data) {
                //console.log(data);
            },

            error: function (data, textStatus, thrown) {
                console.log('------ Error ShipPlacement -------');
                console.log(data);
                console.log(textStatus);
                console.log(thrown);
                console.log('--------------------')
            }
        });
    };

    // возвращает true, если хотя бы одна клетка занята кораблем
    function isAnotherShipInCell() {
        for (var i = 0; i < cellsForShip.length; i++) {
            if (cellsForShip[i].getShipOnCell()) {
                return true;
            }
        }
        return false;
    }


    // проверить клетку (набор клеток) на то, можно ли там расположить корабль
    function checkCells(keysTwoDim, i, j) {
        // проверим этот набор клеток на то, можно ли там физически разместить корабль
        // то есть клеток хватает и они не выходят за пределы таблицы
        var isGood = true;
        for (var k = 0; k < size; k++) {

            // если угол поворота стандартный, проверяем строки таблицы по горизонтали
            // (т.е. теги <td>, лежащие внутри <tr>)
            if (rotate_angle === 'horizontal') {
                // если нужна клетка для корабля выходит за рамки таблицы
                // или клетки лежат не на одной строке,
                // этот набор клеток не подходит
                if (j - k < 0) {
                    isGood = false;
                    cellsForShip = [];
                    break
                }

                cellsForShip.push(cells[keysTwoDim[i][j - k]]);
            }

            // иначе - по вертикали
            else {

                if (i - k < 0) {
                    isGood = false;
                    cellsForShip = [];
                    break
                }

                cellsForShip.push(cells[keysTwoDim[i - k][j]]);
            }
        }


        // теперь на то, если ли в клетках другой корабль или
        // или в соседних
        if (isGood) {
            nearByCells = getNearByCells();
            if (!cellsForShip.length || isAnotherShipInCell() || !isNearByCellsAllowed()) {
                cellsForShip = [];
                nearByCells = [];
                isGood = false;
            }
        }
        return isGood;
    }

    function isNearByCellsAllowed() {
        for (var i = 0; i < nearByCells.length; i++) {
            if (!!nearByCells[i].getShipOnCell()) {
                return false;
            }
        }
        return true;
    }

    // возвращает реальные координаты корабля как html-элемента
    function getRealShipPosition() {
        return {
            'top': parseInt($ship.css('top')),
            'left': parseInt($ship.css('left'))
        };
    }


    // получить текущие координаты корабля относительно точки центрирования
    function getShipPosition() {
        var pos = $ship.position();
        switch (size) {
            // если однопалубник, возвращаем координаты центра картинки
            case 1:
                return {
                    'top': parseInt($ship.css('top')) + $ship.height() * 0.6,
                    'left': parseInt($ship.css('left')) + $ship.width() / 2
                };
            // если двухпалубник
            case 2:
                // если угол поворота нормальный, возвращаем координаты правого нижнего угла
                if (rotate_angle === 'horizontal') {
                    return {
                        'top': parseInt($ship.css('top')) + $ship.height() * 0.78,
                        'left': parseInt($ship.css('left')) + $ship.width() * 0.75
                    }
                }
                // иначе - левого нижнего
                else {
                    return {
                        'top': parseInt($ship.css('top')) + $ship.height() * 0.78,
                        'left': parseInt($ship.css('left')) + $ship.width() * 0.25
                    }
                }
            // трехпалубник
            case 3:
                // если угол поворота нормальный, возвращаем координаты правого нижнего угла
                if (rotate_angle === 'horizontal') {
                    return {
                        'top': parseInt($ship.css('top')) + $ship.height() * 0.85,
                        'left': parseInt($ship.css('left')) + $ship.width() * 0.85
                    }
                }
                // иначе - левого нижнего
                else {
                    return {
                        'top': parseInt($ship.css('top')) + $ship.height() * 0.88,
                        'left': parseInt($ship.css('left')) + $ship.width() * 0.17
                    }
                }
            case 4:
                // если угол поворота нормальный, возвращаем координаты правого нижнего угла
                if (rotate_angle === 'horizontal') {
                    return {
                        'top': parseInt($ship.css('top')) + $ship.height() * 0.88,
                        'left': parseInt($ship.css('left')) + $ship.width() * 0.78
                    }
                }
                // иначе - левого нижнего
                else {
                    return {
                        'top': parseInt($ship.css('top')) + $ship.height() * 0.90,
                        'left': parseInt($ship.css('left')) + $ship.width() * 0.20
                    }
                }
        }
    }

    // возвращает реальные координаты корабля, при которых он бы находился в середине клетки
    // (функция нужна для прилипания)
    function getCenterPositionInCell(currpos, cellpos) {
        var currposReal = getRealShipPosition();

        // сначала расчитаем координаты в центре клетки, относительно точки центрирования корабля
        var currposTarget = {
            'top': cellpos['top'] + cellpos['height'] / 2,
            'left': cellpos['left'] + cellpos['width'] / 2
        };


        // теперь на основании этого посчитаем необходимые реальные координаты
        return {
            'top': currposReal['top'] + (currposTarget['top'] - currpos['top']),
            'left': currposReal['left'] + (currposTarget['left'] - currpos['left'])
        };

    }
}


// класс таблицы
function Table($table, $rowGridLetters, $rowGridNums) {

    $table.droppable({
        activate: function () {
            $table.find('td').addClass('activate');
        },
        deactivate: function () {
            $table.find('td').removeClass('activate');
        }
    });

    var letters = $rowGridLetters.find('.cell');
    var numbers = $rowGridNums.find('.cell').get().reverse();
    var cells = {};


    this.initCells = function () {

        var $rows = $table.find('tr');
        for (var i = 0; i < $rows.length; i++) {

            var $tdsInRow = $rows.eq(i).find('td');
            for (var j = 0; j < $tdsInRow.length; j++) {
                cells[i + '_' + j] = new TableCell($tdsInRow[j], i, j, this);
            }
        }
    };

    this.getCells = function () {
        return cells;
    };

    this.getCellByCoordinate = function (x, y) {
        return cells[x + '_' + y];
    };

    // возвращает список JQuery-объектов соседних клеток к заданным
    this.getNearByCells = function (killCellsCoordinates) {
        var startX = killCellsCoordinates[0][0] - 1;
        var endX = killCellsCoordinates[killCellsCoordinates.length - 1][0] + 1;
        var startY = killCellsCoordinates[0][1] - 1;
        var endY = killCellsCoordinates[killCellsCoordinates.length - 1][1] + 1;

        var $nearByCells = [];
        for (var i = startX; i <= endX; i++)
        {
            for (var j = startY; j <= endY; j++)
            {
                var cell = cells[i + '_' + j];
                if (cell === undefined)
                {
                    continue;
                }
                $nearByCells.push($(cell.getDomCell()));
            }
        }

        return $nearByCells;
    };

    this.getJQueryTable = function () {
        return $table;
    };

    this.activateHover = function () {
        for (var key in cells) {
            cells[key].activateHover();
        }

    };


    this.onCellHover = function (x, y, onlyOne) {

        // если надо подсветить только одну клетку
        if (onlyOne) {
            $(cells[x + '_' + y].getDomCell()).addClass('selected-grid-cell');
            return;
        }

        var cell;

        for (var i = 0; i <= x; i++) {
            $(cells[i + '_' + y].getDomCell()).addClass('selected-grid-cell');
        }

        for (var j = 0; j <= y; j++) {
            $(cells[x + '_' + j].getDomCell()).addClass('selected-grid-cell');
        }


        $(numbers[x]).addClass('selected-row');
        $(letters[y]).addClass('selected-row');
    };

    this.onCellOut = function (x, y, onlyOne) {

        if (onlyOne) {
            $(cells[x + '_' + y].getDomCell()).removeClass('selected-grid-cell');
            return;
        }

        var cell;

        for (var i = 0; i <= x; i++) {

            cell = cells[i + '_' + y];
            // если в клетке установлен корабль, убирать цвет не нужно
            if (cell.getShipOnCell()) {
                continue;
            }

            $(cell.getDomCell()).removeClass('selected-grid-cell');
        }

        for (var j = 0; j <= y; j++) {

            cell = cells[x + '_' + j];
            // если в клетке установлен корабль, убирать цвет не нужно
            if (cell.getShipOnCell()) {
                continue;
            }
            $(cell.getDomCell()).removeClass('selected-grid-cell');
        }

        $(numbers[x]).removeClass('selected-row');
        $(letters[y]).removeClass('selected-row');
    };

}


// класс ячейки таблицы
function TableCell(cell, x, y, table) {

    var $cell = $(cell);

    var destroyed = false;


    $cell.attr('data-x', x);
    $cell.attr('data-y', y);

    // позиция и величина hoverBlock'а.
    // при попадании в него корабля подсвечивается
    var hoverBlock = {
        'left': $(cell).position()['left'] + 22,
        'top': $(cell).position()['top'] + 5,
        'width': 18,
        'height': 20
    };


    this.getHoverBlock = function () {
        return hoverBlock;
    };

    this.setDestroyed = function () {
        destroyed = true;
    };

    this.isDestroyed = function () {
        return destroyed;
    };

    // false - корабля в клетке нет
    var shipOnCell = false;

    // 1 и больше - корабля в клетке нет, но он есть в соседней
    // т.е в эту клетку корабль ставить нельзя
    var shipsNearBy = 0;

    this.getShipsNearBy = function () {
        return shipsNearBy;
    };

    this.addShipNearBy = function () {
        shipsNearBy++;
    };

    this.decreaseShipNearBy = function () {
        shipsNearBy--;
    };

    this.getShipOnCell = function () {
        return shipOnCell;
    };

    this.setShipOnCell = function (isOnSell) {
        shipOnCell = isOnSell;
    };

    $cell.mouseover(onMouseOver);
    $cell.mouseout(onMouseOut);

    // подсветить ячейку и линии их пересечения
    function onMouseOver() {
        table.onCellHover(x, y, false);
    }

    function onMouseOut() {
        table.onCellOut(x, y, false);
    }


    // подсветить только ячейку
    this.onDragOver = function () {

        table.onCellHover(x, y, true);
    };

    this.onDragOut = function () {

        table.onCellOut(x, y, true);
    };


    this.getDomCell = function () {
        return cell;
    };

    this.getCellCoordinates = function () {
        return {
            'x': x,
            'y': y
        }
    };
}

