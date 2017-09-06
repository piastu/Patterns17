<?php

namespace Application\Controller;

use Application\Entity\Game;
use Zend\Mvc\Controller\AbstractActionController;
use Zend\View\Model\ViewModel;

class IndexController extends AbstractActionController {

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
    }

    public function indexAction() {
        global $pageType;
        $pageType = 'main';

        return new ViewModel();
    }

    public function placementAction() {
        global $pageType;
        $pageType = 'placement';

        /*
        $game = $this->getGame();
        if ($game->getStatus() != Game::STATUS_NEW) {
            $params = $this->params()->fromRoute();
            $this->redirect()->toRoute('game', $params);
        }
        */

        return new ViewModel([]);
    }

    public function gameAction() {
        global $pageType;
        $pageType = 'game';

        /*
        $game = $this->getGame();

        if ($game->getStatus() == Game::STATUS_NEW) {
            $params = $this->params()->fromRoute();
            $this->redirect()->toRoute('placement', $params);
        }
        */

        return new ViewModel([]);
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
        if ($game->getCode1() != $code && $game->getCode2() != $code) {
            $this->getResponse()->setStatusCode(\Zend\Http\PhpEnvironment\Response::STATUS_CODE_403);
            throw new \Exception('Forbidden', 403);
        }

        $this->game = $game;

        return $game;
    }
}
