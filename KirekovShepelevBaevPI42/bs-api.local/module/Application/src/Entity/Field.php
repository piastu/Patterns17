<?

namespace Application\Entity;

class Field implements \JsonSerializable {

    /** @var Game $game */
    protected $game;
    protected $player;
    protected $cells = [];
    protected $isAllVisible = true;

    const SIZE = 10;
    const ORIENTATION_VERTICAL = 'vertical';
    const ORIENTATION_HORIZONTAL = 'horizontal';

    const DATA_HIDDEN = 'hidden';
    const DATA_EMPTY = 'empty';
    const DATA_SHIP = 'ship';
    const DATA_HIT = 'hit';

    /**
     * Менеджер сущностей.
     * @var \Doctrine\ORM\EntityManager
     */
    protected $entityManager;

    public function __construct(\Doctrine\ORM\EntityManager $entityManager) {
        $this->entityManager = $entityManager;
    }

    public function jsonSerialize() {
        return $this->asArray();
    }

    public function load(Game $game, $player) {
        $this->game = $game;
        $this->player = $player;

        $cells = $this->entityManager->getRepository(Cell::class)
            ->findBy([
                'game_id' => $this->game->getId(),
                'player' => $this->player
            ]);

        $this->cells = $cells;
    }

    public function clearShip($shipType) {
        /* @var Cell $cell */
        foreach ($this->cells as $ind => $cell) {
            if ($cell->getContent() == $shipType) {
                unset($this->cells[$ind]);
            }
        }
    }

    public function clear() {
        $this->cells = [];
        return true;
    }

    public function placeShip($shipType, $x, $y, $orientation) {
        $types = Cell::$shipTypes;
        $length = $types[$shipType];

        // Валидация
        if (!$length) return false;
        $x = (int)$x;
        $y = (int)$y;

        $lenX = ($orientation == static::ORIENTATION_HORIZONTAL) ? $length : 1;
        if ($x < 0 || $x > static::SIZE - $lenX) return 'Выход за границы поля';
        $lenY = ($orientation == static::ORIENTATION_VERTICAL) ? $length : 1;
        if ($y < 0 || $y > static::SIZE - $lenY) return 'Выход за границы поля';

        // Удалить упоминания про этот корабль
        $this->clearShip($shipType);

        if (isset($x) && isset($y) && isset($orientation)) {
            // валидация пересечения корабля
            $minX = $x > 0 ? $x - 1 : 0;
            $minY = $y > 0 ? $y - 1 : 0;
            $maxX = $x + $lenX < static::SIZE ? $x + $lenX + 1 : $x + $lenX;
            $maxY = $y + $lenY < static::SIZE ? $y + $lenY + 1 : $y + $lenY;

            for ($i = $minX; $i < $maxX; $i++) {
                for ($j = $minY; $j < $maxY; $j++) {
                    $current = $this->getCell($i, $j);
                    if ($current && !empty($current->getContent())) {
                        return 'Пересечение с другим кораблём';
                    }
                }
            }

            // добавление корабля на карту
            for ($i = $x; $i < $x + $lenX; $i++) {
                for ($j = $y; $j < $y + $lenY; $j++) {
                    $current = $this->getCell($i, $j);

                    if ($current) {
                        $current->setContent($shipType);
                    } else {
                        $cell = new Cell();
                        $cell->setGameId($this->game->getId());
                        $cell->setX($i);
                        $cell->setY($j);
                        $cell->setPlayer($this->player);
                        $cell->setVisible(0);
                        $cell->setContent($shipType);
                        $this->cells[] = $cell;
                    }
                }
            }
        }

        return true;
    }

    public function getCell($x, $y) {
        /* @var Cell $cell */
        foreach ($this->cells as $cell) {
            if ($cell->getX() == $x && $cell->getY() == $y) {
                return $cell;
            }
        }
        return false;
    }

    public function save() {
        $oldCells = $this->entityManager->getRepository(Cell::class)
            ->findBy(['game_id' => $this->game->getId(), 'player' => $this->player]);

        foreach ($oldCells as $oldCell) {
            $newCell = array_filter($this->cells, function($obj) use ($oldCell) { return $obj->getId() == $oldCell->getId(); });
            if (!$newCell) {
                $this->entityManager->remove($oldCell);
            }
        }

        foreach ($this->cells as $newCell) {
            $this->entityManager->persist($newCell);
        }

        $this->entityManager->flush();
    }

    public function setVisibilityType($isAllVisible) {
        $this->isAllVisible = $isAllVisible;
    }

    public function asArray() {
        $result = [];
        for ($x = 0; $x < static::SIZE; $x++) { // ряды, т.е. координата Y
            $result[$x] = [];
            for ($y = 0; $y < static::SIZE; $y++) { // строки, т.е. координата X
                $cell = $this->getCell($x, $y);

                if ($this->isAllVisible) {
                    // это моё поле, вижу всё
                    if (!$cell) {
                        $result[$x][$y] = [static::DATA_EMPTY, 0];
                    } else {
                        $result[$x][$y] = [$cell->getContent(), $cell->getVisible()];
                    }

                } else {
                    // вражеское поле
                    if (!$cell) {
                        $result[$x][$y] = [static::DATA_EMPTY, 0];
                    } else {
                        $result[$x][$y] = [
                            $cell->getVisible() ? $cell->getContent() : static::DATA_HIDDEN,
                            $cell->getVisible()
                        ];
                    }
                }
            }
        }

        return $result;
    }

    public function getUsedPlaces() {
        $used = [];
        foreach ($this->cells as $cell) {
            $content = $cell->getContent();
            if (!empty($content) && $content != 'empty') {
                $used[] = $cell->getContent();
            }
        }

        $used = array_unique($used);
        sort($used);
        return $used;
    }

    public function shot($x, $y) {
        if ($x < 0 || $x > static::SIZE - 1) return ['error' => true, 'message' => 'Выход за границы поля'];
        if ($y < 0 || $y > static::SIZE - 1) return ['error' => true, 'message' => 'Выход за границы поля'];

        $cell = $this->getCell($x, $y);
        if (!$cell) {
            // Такой ячейки ещё нет - значит тут пусто
            $cell = new Cell();
            $cell->setGameId($this->game->getId());
            $cell->setX($x);
            $cell->setY($y);
            $cell->setPlayer($this->player);
            $cell->setVisible(1);
            $cell->setContent('');
            $this->cells[] = $cell;
            return ['hit' => false];

        } elseif ($cell->getVisible()) {
            return ['error' => true, 'message' => 'Сюда уже стреляли'];

        } else {
            $ship = $cell->getContent();
            $cell->setVisible(1);
            if (!$ship) {
                return ['hit' => false];
            }

            $result = ['hit' => true];
            // проверить, что корабль убит
            $partsLeft = array_filter($this->cells, function($obj) use ($ship) { return $obj->getContent() == $ship && $obj->getVisible() == 0; });
            if (!$partsLeft) {
                $result['kill'] = true;

                // Убит, пометить клетки как пустые
                $this->setShipKilled($ship);
            }

            // проверить, что игра окончена
            $shipsLeft = array_filter($this->cells, function($obj) { return !empty($obj->getContent()) && $obj->getVisible() == 0; });
            if (empty($shipsLeft)) {
                $result['victory'] = true;
            }

            return $result;
        }
    }

    public function setShipKilled($ship) {
        /* @var Cell $cell */
        foreach ($this->cells as $cell) {
            if ($cell->getContent() != $ship)  continue;

            $x = $cell->getX();
            $y = $cell->getY();

            // Выставить всем окрестным клеткам видимость
            for ($i = $x - 1; $i <= $x + 1; $i++) {
                if ($i < 0 || $i > static::SIZE - 1) continue;

                for ($j = $y - 1; $j <= $y + 1; $j++) {
                    if ($j < 0 || $j > static::SIZE - 1) continue;

                    $neighbourCell = $this->getCell($i, $j);
                    if ($neighbourCell) {
                        $neighbourCell->setVisible(true);
                    } else {
                        $cell = new Cell();
                        $cell->setGameId($this->game->getId());
                        $cell->setX($i);
                        $cell->setY($j);
                        $cell->setPlayer($this->player);
                        $cell->setVisible(1);
                        $cell->setContent('');
                        $this->cells[] = $cell;
                    }
                }
            }
         }
    }
}