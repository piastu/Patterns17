<?php
namespace Application\Entity;

use Doctrine\ORM\Mapping as ORM;

/**
 * @ORM\Entity
 * @ORM\Table(name="messages")
 */
class Message
{

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
     * @ORM\Column(name="player")
     */
    protected $player;

    /**
     * @ORM\Column(name="message")
     */
    protected $message;

    /**
     * @ORM\Column(name="date")
     */
    protected $date;

    /**
     * @return mixed
     */
    public function getDate() {
        return $this->date;
    }

    /**
     * @param mixed $date
     */
    public function setDate($date) {
        $this->date = $date;
    }

    /**
     * @return mixed
     */
    public function getId() {
        return $this->id;
    }

    /**
     * @param mixed $id
     */
    public function setId($id) {
        $this->id = $id;
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
    public function getMessage() {
        return $this->message;
    }

    /**
     * @param mixed $message
     */
    public function setMessage($message) {
        $this->message = $message;
    }
}