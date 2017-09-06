<?php
namespace Application\Entity;

use Doctrine\ORM\Mapping as ORM;

/**
 * Этот класс представляет собой пост в блоге.
 * @ORM\Entity
 * @ORM\Table(name="cells")
 */
class Cell
{

    public static $shipTypes = [
        '1-1' => 1,
        '1-2' => 1,
        '1-3' => 1,
        '1-4' => 1,
        '2-1' => 2,
        '2-2' => 2,
        '2-3' => 2,
        '3-1' => 3,
        '3-2' => 3,
        '4-1' => 4,
    ];

    /**
     * @ORM\Id
     * @ORM\GeneratedValue
     * @ORM\Column(name="id")
     */
    protected $id;

    /**
     * @ORM\Column(name="game_id")
     */
    protected $game_id;

    /**
     * @ORM\Column(name="x")
     */
    protected $x;

    /**
     * @ORM\Column(name="y")
     */
    protected $y;

    /**
     * @ORM\Column(name="player")
     */
    protected $player;

    /**
     * @ORM\Column(name="visible")
     */
    protected $visible;

    /**
     * @ORM\Column(name="content")
     */
    protected $content;

    // Возвращает ID данного поста.
    public function getId()
    {
        return $this->id;
    }

    /**
     * @return mixed
     */
    public function getGameId() {
        return $this->game_id;
    }

    /**
     * @param mixed $game_id
     */
    public function setGameId($game_id) {
        $this->game_id = $game_id;
    }

    /**
     * @return mixed
     */
    public function getX() {
        return $this->x;
    }

    /**
     * @param mixed $x
     */
    public function setX($x) {
        $this->x = $x;
    }

    /**
     * @return mixed
     */
    public function getY() {
        return $this->y;
    }

    /**
     * @param mixed $y
     */
    public function setY($y) {
        $this->y = $y;
    }

    /**
     * @return mixed
     */
    public function getPlayer() {
        return $this->player;
    }

    /**
     * @param mixed $player
     */
    public function setPlayer($player) {
        $this->player = $player;
    }

    /**
     * @return mixed
     */
    public function getVisible() {
        return (int)$this->visible;
    }

    /**
     * @param mixed $visible
     */
    public function setVisible($visible) {
        $this->visible = (int)$visible;
    }

    /**
     * @return mixed
     */
    public function getContent() {
        return $this->content ?: 'empty';
    }

    /**
     * @param mixed $content
     */
    public function setContent($content) {
        $this->content = $content;
    }
}