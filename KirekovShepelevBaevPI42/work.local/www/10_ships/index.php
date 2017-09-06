<?php
    $siteRoot = "http://{$_SERVER['HTTP_HOST']}".mb_strcut(__DIR__, mb_strlen(realpath($_SERVER['DOCUMENT_ROOT']))).'/';
?>

<!DOCTYPE html>
<html lang="ru">
<head>
    <meta charset="UTF-8">
    <title>Морской бой</title>
    <link rel="stylesheet" href="<?= $siteRoot ?>css/styles.css">
    <link rel="stylesheet" href="<?= $siteRoot ?>css/styles-game.css">
    <link rel="stylesheet" href="https://ajax.googleapis.com/ajax/libs/jqueryui/1.12.1/themes/smoothness/jquery-ui.css">

    <script src="<?= $siteRoot ?>js/libs/jquery-3.2.1.min.js"></script>
    <script src="<?= $siteRoot ?>js/helpers.js"></script>
    <script src="https://cdn.rawgit.com/zenorocha/clipboard.js/master/dist/clipboard.min.js"></script>
    <script src="https://ajax.googleapis.com/ajax/libs/jqueryui/1.12.1/jquery-ui.min.js"></script>
    <script src="<?= $siteRoot ?>js/ajax_requests_names.js"></script>
    <script src="<?= $siteRoot ?>js/classes.js"></script>
    <script defer src="<?= $siteRoot ?>js/index.js"></script>
    <script src="<?= $siteRoot ?>js/game.js"></script>
</head>

<body class="battle-ships">

<div class="layout" id="startGameScreen">

    <!-- расставь корабли -->
    <div class="place-your-ships-block js-place-your-ships-block">
        <div class="place-your-ships button-style-hover js-place-your-ships">
            —Для начала расставь корабли, каналья!
        </div>
    </div>

    <div class="wait-for-your-enemy-block js-wait-for-your-enemy-block">
        <div class="wait-for-your-enemy">
            —Ждем, когда противник будет готов.
        </div>
    </div>


    <div class="start-game not-ready not-active button-style-hover js-start-game">
        —Все готово, адмирал! Начать игру!
    </div>

    <!-- картинка облаков -->
    <div class="clouds"></div>

    <div class="cube"></div>

    <div class="grid-block">
        <table class="grid js-table-grid" id="tableGrid">
            <tr>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
            </tr>
            <tr>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
            </tr>
            <tr>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
            </tr>
            <tr>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
            </tr>
            <tr>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
            </tr>
            <tr>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
            </tr>
            <tr>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
            </tr>
            <tr>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
            </tr>
            <tr>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
            </tr>
            <tr>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
            </tr>
        </table>
    </div>
    <!-- буквы -->
    <div class="row-grid letters js-row-grid-letters">
        <div class="cell cell-letter">А</div>
        <div class="cell cell-letter">Б</div>
        <div class="cell cell-letter">В</div>
        <div class="cell cell-letter">Г</div>
        <div class="cell cell-letter">Д</div>
        <div class="cell cell-letter">Е</div>
        <div class="cell cell-letter">Ж</div>
        <div class="cell cell-letter">З</div>
        <div class="cell cell-letter">И</div>
        <div class="cell cell-letter">К</div>
    </div>

    <!-- числа -->
    <div class="row-grid nums js-row-grid-nums">
        <div class="cell cell-num">10</div>
        <div class="cell cell-num">9</div>
        <div class="cell cell-num">8</div>
        <div class="cell cell-num">7</div>
        <div class="cell cell-num">6</div>
        <div class="cell cell-num">5</div>
        <div class="cell cell-num">4</div>
        <div class="cell cell-num">3</div>
        <div class="cell cell-num">2</div>
        <div class="cell cell-num">1</div>
    </div>


    <div class="row">
        <div class="title"></div>
        <div class="invite-block">
            <div class="invite-space">
                Пригласить к битве
            </div>
            <button class="invite-image js-invite-image" title="Копировать ссылку"></button>
            <div class="invite-block-a">
                <a class="invite-a js-invite-friend" href="http://sibirix.ru/seabattle/783468" target="_blank">http://sibirix.ru/seabattle/783468</a>
            </div>
        </div>
    </div>

    <!-- блок кораблей -->
    <div class="ship-block">

        <!-- четырехпалубник -->
        <img data-size="4" src="<?= $siteRoot ?>images/big-ship.png" width="143" height="106" data-id="4-1" class="ship ship0 js-ship">

        <!-- трехпалубники -->
        <img data-size="3" src="<?= $siteRoot ?>images/medium-ship.png" width="98" height="61" data-id="3-1" class="ship ship1 js-ship">

        <img data-size="3" src="<?= $siteRoot ?>images/medium-ship.png" width="98" height="61" data-id="3-2" class="ship ship2 js-ship">

        <!-- двухпалубники -->
        <img data-size="2" src="<?= $siteRoot ?>images/small-ship.png" width="73" height="47" data-id="2-1" class="ship ship3 js-ship">

        <img data-size="2" src="<?= $siteRoot ?>images/small-ship.png" width="73" height="47" data-id="2-2" class="ship ship4 js-ship">

        <img data-size="2" src="<?= $siteRoot ?>images/small-ship.png" width="73" height="47" data-id="2-3" class="ship ship5 js-ship">

        <!-- однопалубники -->
        <img data-size="1" src="<?= $siteRoot ?>images/very-small-ship.png" width="39" height="24" data-id="1-1"
             class="ship ship6 js-ship">

        <img data-size="1" src="<?= $siteRoot ?>images/very-small-ship.png" width="39" height="24" data-id="1-2"
             class="ship ship7 js-ship">

        <img data-size="1" src="<?= $siteRoot ?>images/very-small-ship.png" width="39" height="24" data-id="1-3"
             class="ship ship8 js-ship">

        <img data-size="1" src="<?= $siteRoot ?>images/very-small-ship.png" width="39" height="24" data-id="1-4"
             class="ship ship9 js-ship">

    </div>

    <!-- блок действий -->
    <div class="action-row">

        <div class="action-block" id="checkShips">
            <div class="action-image drag"></div>
            <div class="action-text">Мышью перетаскивай корабли на поле</div>
        </div>

        <div class="action-block">
            <div class="action-image rotate"></div>
            <div class="action-text">Кликай для поворота корабля</div>
        </div>

        <div class="action-block js-set-ships-random-position">
            <div class="action-image random"></div>
            <div class="action-text text-underline">Расставить в случайном порядке</div>
        </div>

        <div class="action-block js-get-ships-back">
            <div class="action-image clear"></div>
            <div class="action-text text-underline">С глаз долой</div>
        </div>

    </div>


</div>

<div class="layout" id="actionGameScreen">


    <div class="row">
        <div class="title"></div>
    </div>

    <div class="clouds"></div>
    <div class="light-blue-back"></div>
    <div class="blue-back"></div>

    <div class="rocket left-rocket"></div>
    <div class="rocket right-rocket"></div>

    <div class="cube cube-player"></div>
    <div class="cube cube-enemy"></div>

    <div class="drowned-ship drowned-ship-left"></div>
    <div class="drowned-ship drowned-ship-right"></div>


    <!-- поле игрока -->
    <div class="grid-block grid-block-player">

        <!-- буквы -->
        <div class="row-grid letters js-row-grid-letters-player">
            <div class="cell cell-letter">А</div>
            <div class="cell cell-letter">Б</div>
            <div class="cell cell-letter">В</div>
            <div class="cell cell-letter">Г</div>
            <div class="cell cell-letter">Д</div>
            <div class="cell cell-letter">Е</div>
            <div class="cell cell-letter">Ж</div>
            <div class="cell cell-letter">З</div>
            <div class="cell cell-letter">И</div>
            <div class="cell cell-letter">К</div>
        </div>

        <!-- числа -->
        <div class="row-grid nums js-row-grid-nums-player">
            <div class="cell cell-num">10</div>
            <div class="cell cell-num">9</div>
            <div class="cell cell-num">8</div>
            <div class="cell cell-num">7</div>
            <div class="cell cell-num">6</div>
            <div class="cell cell-num">5</div>
            <div class="cell cell-num">4</div>
            <div class="cell cell-num">3</div>
            <div class="cell cell-num">2</div>
            <div class="cell cell-num">1</div>
        </div>

        <table class="grid js-grid-player">
            <!-- четырехпалубник -->
            <img data-size="4" src="<?= $siteRoot ?>images/big-ship.png" width="143" height="106" data-id="4-1" class="ship-game js-ship-game-player">
            <tr>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
            </tr>
            <tr>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
            </tr>
            <tr>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
            </tr>
            <tr>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
            </tr>
            <tr>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
            </tr>
            <tr>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
            </tr>
            <tr>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
            </tr>
            <tr>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
            </tr>
            <tr>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
            </tr>
            <tr>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
            </tr>
        </table>

        <!-- блок кораблей -->



            <!-- трехпалубники -->
            <img data-size="3" src="<?= $siteRoot ?>images/medium-ship.png" width="98" height="61" data-id="3-1" class="ship-game js-ship-game-player">
            <img data-size="3" src="<?= $siteRoot ?>images/medium-ship.png" width="98" height="61" data-id="3-2" class="ship-game js-ship-game-player">

            <!-- двухпалубники -->
            <img data-size="2" src="<?= $siteRoot ?>images/small-ship.png" width="73" height="47" data-id="2-1" class="ship-game js-ship-game-player">
            <img data-size="2" src="<?= $siteRoot ?>images/small-ship.png" width="73" height="47" data-id="2-2" class="ship-game js-ship-game-player">
            <img data-size="2" src="<?= $siteRoot ?>images/small-ship.png" width="73" height="47" data-id="2-3" class="ship-game js-ship-game-player">

            <!-- однопалубники -->
            <img data-size="1" src="<?= $siteRoot ?>images/very-small-ship.png" width="39" height="24" data-id="1-1"
                 class="ship-game js-ship-game-player">
            <img data-size="1" src="<?= $siteRoot ?>images/very-small-ship.png" width="39" height="24" data-id="1-2"
                 class="ship-game js-ship-game-player">
            <img data-size="1" src="<?= $siteRoot ?>images/very-small-ship.png" width="39" height="24" data-id="1-3"
                 class="ship-game js-ship-game-player">
            <img data-size="1" src="<?= $siteRoot ?>images/very-small-ship.png" width="39" height="24" data-id="1-4"
                 class="ship-game js-ship-game-player">


    </div>

    <!-- поле противника -->
    <div class="grid-block grid-block-enemy">

        <!-- буквы -->
        <div class="row-grid letters js-row-grid-letters-enemy">
            <div class="cell cell-letter">А</div>
            <div class="cell cell-letter">Б</div>
            <div class="cell cell-letter">В</div>
            <div class="cell cell-letter">Г</div>
            <div class="cell cell-letter">Д</div>
            <div class="cell cell-letter">Е</div>
            <div class="cell cell-letter">Ж</div>
            <div class="cell cell-letter">З</div>
            <div class="cell cell-letter">И</div>
            <div class="cell cell-letter">К</div>
        </div>

        <!-- числа -->
        <div class="row-grid nums js-row-grid-nums-enemy">
            <div class="cell cell-num">10</div>
            <div class="cell cell-num">9</div>
            <div class="cell cell-num">8</div>
            <div class="cell cell-num">7</div>
            <div class="cell cell-num">6</div>
            <div class="cell cell-num">5</div>
            <div class="cell cell-num">4</div>
            <div class="cell cell-num">3</div>
            <div class="cell cell-num">2</div>
            <div class="cell cell-num">1</div>
        </div>

        <table class="grid js-grid-enemy">
            <tr>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
            </tr>
            <tr>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
            </tr>
            <tr>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
            </tr>
            <tr>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
            </tr>
            <tr>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
            </tr>
            <tr>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
            </tr>
            <tr>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
            </tr>
            <tr>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
            </tr>
            <tr>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
            </tr>
            <tr>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
            </tr>
        </table>
    </div>

    <!-- здоровье игрока -->
    <div class="score-block score-block-player">
        <div class="score score-player">
            Твой флот <small>повреждения 0%</small>
        </div>
        <div class="health-block">

            <!-- четырехпалубник -->
            <div class="health-row">
                <div class="health-bar">
                    <div class="health-cell active"></div>
                    <div class="health-cell active"></div>
                    <div class="health-cell active"></div>
                    <div class="health-cell active"></div>
                </div>
            </div>

            <!-- трехпалубники -->
            <div class="health-row">
                <div class="health-bar">
                    <div class="health-cell active"></div>
                    <div class="health-cell active"></div>
                    <div class="health-cell active"></div>
                </div>

                <div class="health-bar">
                    <div class="health-cell active"></div>
                    <div class="health-cell active"></div>
                    <div class="health-cell active"></div>
                </div>
            </div>

            <!-- двухпалубники -->
            <div class="health-row">
                <div class="health-bar">
                    <div class="health-cell active"></div>
                    <div class="health-cell active"></div>
                </div>

                <div class="health-bar">
                    <div class="health-cell active"></div>
                    <div class="health-cell active"></div>
                </div>

                <div class="health-bar">
                    <div class="health-cell active"></div>
                    <div class="health-cell active"></div>
                </div>
            </div>

            <!-- однопалубники -->
            <div class="health-row">
                <div class="health-bar">
                    <div class="health-cell active"></div>
                </div>

                <div class="health-bar">
                    <div class="health-cell active"></div>
                </div>

                <div class="health-bar">
                    <div class="health-cell active"></div>
                </div>

                <div class="health-bar">
                    <div class="health-cell active"></div>
                </div>
            </div>

        </div>
    </div>

    <!-- здоровье противника -->
    <div class="score-block score-block-enemy">
        <div class="score">
            Флот врага
            <small>повреждения 0%</small>
        </div>
        <div class="health-block">

            <!-- четырехпалубник -->
            <div class="health-row">
                <div class="health-bar">
                    <div class="health-cell active"></div>
                    <div class="health-cell active"></div>
                    <div class="health-cell active"></div>
                    <div class="health-cell active"></div>
                </div>
            </div>

            <!-- трехпалубники -->
            <div class="health-row">
                <div class="health-bar">
                    <div class="health-cell active"></div>
                    <div class="health-cell active"></div>
                    <div class="health-cell active"></div>
                </div>

                <div class="health-bar">
                    <div class="health-cell active"></div>
                    <div class="health-cell active"></div>
                    <div class="health-cell active"></div>
                </div>
            </div>

            <!-- двухпалубники -->
            <div class="health-row">
                <div class="health-bar">
                    <div class="health-cell active"></div>
                    <div class="health-cell active"></div>
                </div>

                <div class="health-bar">
                    <div class="health-cell active"></div>
                    <div class="health-cell active"></div>
                </div>

                <div class="health-bar">
                    <div class="health-cell active"></div>
                    <div class="health-cell active"></div>
                </div>
            </div>

            <!-- однопалубники -->
            <div class="health-row">
                <div class="health-bar">
                    <div class="health-cell active"></div>
                </div>

                <div class="health-bar">
                    <div class="health-cell active"></div>
                </div>

                <div class="health-bar">
                    <div class="health-cell active"></div>
                </div>

                <div class="health-bar">
                    <div class="health-cell active"></div>
                </div>
            </div>

        </div>
    </div>

    <!-- твой ход -->
    <div class="turn">—Твой ход, тысяча чертей!</div>

    <!-- ход противника -->
    <div class="turn">—Ход противника!</div>


</div>

</body>

</html>