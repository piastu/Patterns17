<?php
namespace Application\Entity;

use Doctrine\ORM\Mapping as ORM;

/**
 * @ORM\Entity
 * @ORM\Table(name="games")
 */
class Game
{
    // Константы статуса игры.
    const STATUS_NEW      = 1;
    const STATUS_GAMING   = 2;
    const STATUS_FINISHED = 3;

    /**
     * @ORM\Id
     * @ORM\GeneratedValue
     * @ORM\Column(name="id")
     */
    protected $id;

    /**
     * @ORM\Column(name="code1")
     */
    protected $code1;

    /**
     * @ORM\Column(name="code2")
     */
    protected $code2;

    /**
     * @ORM\Column(name="status")
     */
    protected $status;

    /**
     * @ORM\Column(name="player1ready")
     */
    protected $player1ready;

    /**
     * @ORM\Column(name="player2ready")
     */
    protected $player2ready;

    /**
     * @ORM\Column(name="currentPlayer")
     */
    protected $currentPlayer;

    /**
     * @return mixed
     */
    public function getPlayer1ready() {
        return (int)$this->player1ready;
    }

    /**
     * @param mixed $player1ready
     */
    public function setPlayer1ready($player1ready) {
        $this->player1ready = (int)$player1ready;
    }

    /**
     * @return mixed
     */
    public function getPlayer2ready() {
        return (int)$this->player2ready;
    }

    /**
     * @param mixed $player2ready
     */
    public function setPlayer2ready($player2ready) {
        $this->player2ready = (int)$player2ready;
    }

    /**
     * @return mixed
     */
    public function getCurrentPlayer() {
        return $this->currentPlayer;
    }

    /**
     * @param mixed $currentPlayer
     */
    public function setCurrentPlayer($currentPlayer) {
        $this->currentPlayer = $currentPlayer;
    }

    public function getId()
    {
        return $this->id;
    }

    public function setId($id)
    {
        $this->id = $id;
    }

    public function getCode1()
    {
        return $this->code1;
    }

    public function setCode1($code1)
    {
        $this->code1 = $code1;
    }

    public function getCode2()
    {
        return $this->code2;
    }

    public function setCode2($code2)
    {
        $this->code2 = $code2;
    }

    public function getStatus()
    {
        return $this->status;
    }

    public function setStatus($status)
    {
        $this->status = $status;
    }

    public static function getRandomCode($length = 10) {
        $characters = '0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ';
        $charactersLength = strlen($characters);
        $randomString = '';
        for ($i = 0; $i < $length; $i++) {
            $randomString .= $characters[rand(0, $charactersLength - 1)];
        }
        return $randomString;
    }
}