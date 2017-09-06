<?php

namespace Application\Controller;

use Application\Entity\Cell;
use Application\Entity\Field;
use Application\Entity\Game;
use Application\Entity\Message;
use Zend\Http\PhpEnvironment\Response;
use Zend\Mvc\Controller\AbstractActionController;

class ApiController extends AbstractActionController {

    /**
     * Менеджер сущностей.
     * @var \Doctrine\ORM\EntityManager
     */
    private $entityManager;

    /**
     * @var Game $game
     */
    protected $game;

    public function __construct($entityManager) {
        $this->entityManager = $entityManager;
        $headers = $this->getResponse()->getHeaders();
        $headers->addHeaderLine("Access-Control-Allow-Origin: *");
    }

    protected function checkPost() {
        if (!$this->getRequest()->isPost()) {
            $this->returnError(101, "Разрешено обращение только методом POST");
        }
    }

    /**
     * @return Game
     * @throws \Exception
     */
    protected function getGame() {
        if ($this->game) return $this->game;

        $params = $this->params()->fromRoute();
        $code = $params['code'];
        $game = $this->entityManager->getRepository(Game::class)->findOneById($params['id']);
        if (!$game || ($game->getCode1() != $code && $game->getCode2() != $code)) {
            $this->returnError(102, 'Игра не найдена');
        }

        $this->game = $game;

        return $game;
    }

    protected function returnError($code = 0, $message = 'Не переданы обязательные параметры') {
        $this->getResponse()->setStatusCode(Response::STATUS_CODE_400);
        die(json_encode([
            'success' => false,
            'error'   => $code,
            'message' => $message,
        ]));
    }

    protected function returnSuccess($data = []) {
        $data['success'] = true;
        die(json_encode($data));
    }

    public function startAction() {
        $this->checkPost();

        $game = new Game();
        $game->setCode1(Game::getRandomCode());
        $game->setCode2(Game::getRandomCode());
        $game->setStatus(Game::STATUS_NEW);

        $this->entityManager->persist($game);
        $this->entityManager->flush();

        $this->returnSuccess([
            'id'      => $game->getId(),
            'code'    => $game->getCode1(),
            'invite'  => $game->getCode2(),
        ]);
    }

    public function statusAction() {
        $game = $this->getGame();
        $params = $this->params()->fromPost();
        $player = $game->getCode1() == $this->params()->fromRoute('code') ? 1 : 2;

        $status = [
            'game' => [
                'id' => $game->getId(),
                'invite' => $game->getCode2(),
                'status' => $game->getStatus(),
                'myTurn' => $game->getCurrentPlayer() == $player
            ]
        ];

        if ($game->getStatus() == Game::STATUS_NEW) {
            $playerReady = [
                1 => $game->getPlayer1ready(),
                2 => $game->getPlayer2ready()
            ];

            $status['game']['meReady'] = !empty($playerReady[$player]);
        }

        if (!isset($params['short']) || ($params['short'] != 1)) {
            $fieldMy = new Field($this->entityManager);
            $fieldMy->load($game, $player);

            $fieldEnemy = new Field($this->entityManager);
            $fieldEnemy->load($game, $player == 1 ? 2 : 1);
            $fieldEnemy->setVisibilityType(false);

            $status['fieldMy'] = $fieldMy->asArray();
            $status['fieldEnemy'] = $fieldEnemy->asArray();

            if ($game->getStatus() == Game::STATUS_NEW) {
                $usedPlaces = $fieldMy->getUsedPlaces();
                $status['usedPlaces'] = $usedPlaces;
            }
        }

        $this->returnSuccess($status);
    }

    public function placeShipAction() {
        $this->checkPost();
        $game = $this->getGame();
        $params = $this->params()->fromPost();
        $player = $game->getCode1() == $this->params()->fromRoute('code') ? 1 : 2;

        if ($game->getStatus() != Game::STATUS_NEW) {
            $this->returnError(108, 'Игра уже идёт');
        } else {
            $playerReady = [
                1 => $game->getPlayer1ready(),
                2 => $game->getPlayer2ready()
            ];
            if (!empty($playerReady[$player])) {
                $this->returnError(109, 'Вы уже объявили о своей готовности');
            }
        }

        $field = new Field($this->entityManager);
        $field->load($game, $player);

        // validation
        if (!isset($params['ships'])) {
            if (!isset($params['ship'])) {
                $this->returnError(103, 'Не переданы обязательные параметры');
            }

            if (isset($params['x']) || isset($params['y']) || isset($params['orientation'])) {
                // Если передана либо какая-то кордината, либо ориентация, но не передано всё это вместе - не хватает параметров
                if (!isset($params['x']) || !isset($params['y']) || !isset($params['orientation'])) {
                    $this->returnError(103, 'Не переданы обязательные параметры');
                }
            }
        }

        // placement
        if (is_array($params['ships'])) {
            $result = [];
            foreach ($params['ships'] as $ship) {
                $result[] = $field->placeShip(
                    $ship['ship'],
                    $ship['x'],
                    $ship['y'],
                    $ship['orientation']
                );
            }

            $result = array_filter($result, function($obj) { return $obj !== true; });
            if (empty($result)) $result = true;

        } else {
            $result = $field->placeShip(
                $params['ship'],
                $params['x'],
                $params['y'],
                $params['orientation']
            );
        }

        if ($result === true) {
            $field->save();
        }

        if ($result === true) {
            $this->returnSuccess();
        } else {
            $this->returnError(104, is_array($result) ? implode("\n", $result) : $result);
        }
    }

    public function clearFieldAction() {
        $this->checkPost();
        $game = $this->getGame();
        $player = $game->getCode1() == $this->params()->fromRoute('code') ? 1 : 2;

        if ($game->getStatus() != Game::STATUS_NEW) {
            $this->returnError(108, 'Игра уже идёт');
        } else {
            $playerReady = [
                1 => $game->getPlayer1ready(),
                2 => $game->getPlayer2ready()
            ];
            if (!empty($playerReady[$player])) {
                $this->returnError(109, 'Вы уже объявили о своей готовности');
            }
        }

        $field = new Field($this->entityManager);
        $field->load($game, $player);
        $result = $field->clear();

        if ($result === true) {
            $field->save();
        }

        if ($result === true) {
            $this->returnSuccess();
        } else {
            $this->returnError(104, $result);
        }
    }

    public function readyAction() {
        $this->checkPost();
        $game = $this->getGame();
        $player = $game->getCode1() == $this->params()->fromRoute('code') ? 1 : 2;

        if ($game->getStatus() != Game::STATUS_NEW) {
            $this->returnError(102, 'Игра не найдена');
        }

        $field = new Field($this->entityManager);
        $field->load($game, $player);
        $usedPlaces = $field->getUsedPlaces();

        if ($player == 1) {
            $game->setPlayer1ready(1);
        } else {
            $game->setPlayer2ready(1);
        }

        $result = [];
        if (count($usedPlaces) == count(Cell::$shipTypes)) {
            if (($player == 1 && !$game->getPlayer2ready()) || ($player == 2 && !$game->getPlayer1ready())) {
                $result = ['enemyReady' => false];
            } else {
                $game->setStatus(Game::STATUS_GAMING);
                $game->setCurrentPlayer(rand(1, 2));
                $result = ['enemyReady' => true];
            }

        } else {
            $this->returnError(105, 'Не все корабли размещены');
        }

        $this->entityManager->persist($game);
        $this->entityManager->flush();
        $this->returnSuccess($result);
    }

    public function shotAction() {
        $this->checkPost();
        $game = $this->getGame();
        $params = $this->params()->fromPost();
        $player = $game->getCode1() == $this->params()->fromRoute('code') ? 1 : 2;

        if ($game->getCurrentPlayer() != $player) {
            $this->returnError(106, 'Не ваш ход');
        }

        $fieldEnemy = new Field($this->entityManager);
        $fieldEnemy->load($game, $player == 1 ? 2 : 1);

        // validation
        if (!isset($params['x']) || !isset($params['y'])) {
            $this->returnError(103, 'Не переданы обязательные параметры');
        }

        // placement
        $result = $fieldEnemy->shot(
            $params['x'],
            $params['y']
        );

        if ($result['error']) {
            $this->returnError(107, $result['message']);

        } else {
            if ($result['hit']) {
                if ($result['kill']) {
                    if ($result['victory']) {
                        $game->setStatus(Game::STATUS_FINISHED);
                    }
                }
            } else {
                $game->setCurrentPlayer($player == 1 ? 2 : 1);
            }

            $fieldEnemy->save();

            $this->entityManager->persist($game);
            $this->entityManager->flush();
        }

        $this->returnSuccess($result);
    }

    public function chatLoadAction() {
        $game = $this->getGame();
        $lastTime = (int)$this->params()->fromQuery('lastTime');
        $player = $game->getCode1() == $this->params()->fromRoute('code') ? 1 : 2;

        $queryBuilder = $this->entityManager->createQueryBuilder();
        $queryBuilder->select('m')
            ->from(Message::class, 'm')
            ->where('m.game_id = :gameId')
            ->orderBy('m.date', 'asc')
            ->setParameter('gameId', $this->game->getId());

        if ($lastTime) {
            $queryBuilder->andWhere(
                $queryBuilder->expr()->gt('m.date', $lastTime)
            );
        }

        $messages = $queryBuilder->getQuery()->getResult();
        $messages = array_map(function($obj) use ($player) {
            return [
                'my'      => $obj->getPlayer() == $player,
                'time'    => $obj->getDate(),
                'message' => $obj->getMessage()
            ];
        }, $messages);

        $this->returnSuccess([
            'messages' => $messages,
            'lastTime' => time()
        ]);
    }

    public function chatSendAction() {
        $this->checkPost();
        $game = $this->getGame();
        $player = $game->getCode1() == $this->params()->fromRoute('code') ? 1 : 2;

        $messageText = $this->params()->fromPost('message');
        $messageText = trim(strip_tags($messageText));
        if (empty($messageText)) {
            $this->returnError(103, 'Не переданы обязательные параметры');
        }

        $message = new Message();
        $message->setGameId($game->getId());
        $message->setPlayer($player);
        $message->setMessage($messageText);
        $message->setDate(time());

        $this->entityManager->persist($message);
        $this->entityManager->flush();

        $this->returnSuccess();
    }
}
