<?php
/**
 * @link      http://github.com/zendframework/ZendSkeletonApplication for the canonical source repository
 * @copyright Copyright (c) 2005-2016 Zend Technologies USA Inc. (http://www.zend.com)
 * @license   http://framework.zend.com/license/new-bsd New BSD License
 */

namespace Application;

use Application\Controller;
use Zend\Router\Http;

return [
    // Главная
    'index' => [
        'type' => Http\Literal::class,
        'options' => [
            'route'    => '/',
            'defaults' => [
                'controller' => Controller\IndexController::class,
                'action'     => 'index',
            ],
        ],
    ],

    // Размещение кораблей
    'placement' => [
        'type' => Http\Segment::class,
        'options' => [
            'route'    => '/placement/:id/:code',
            'defaults' => [
                'controller' => Controller\IndexController::class,
                'action'     => 'placement',
            ],
        ],
    ],

    // Игра
    'game' => [
        'type' => Http\Segment::class,
        'options' => [
            'route'    => '/game/:id/:code',
            'defaults' => [
                'controller' => Controller\IndexController::class,
                'action'     => 'game',
            ],
        ],
    ],

    // API
    'api-start' => [
        'type' => Http\Literal::class,
        'options' => [
            'route'    => '/api/start/',
            'defaults' => [
                'controller' => Controller\ApiController::class,
                'action'     => 'start',
            ],
        ],
    ],

    'api-status' => [
        'type' => Http\Segment::class,
        'options' => [
            'route'    => '/api/status/:id/:code',
            'defaults' => [
                'controller' => Controller\ApiController::class,
                'action'     => 'status',
            ],
        ],
    ],

    'api-place-ship' => [
        'type' => Http\Segment::class,
        'options' => [
            'route'    => '/api/place-ship/:id/:code',
            'defaults' => [
                'controller' => Controller\ApiController::class,
                'action'     => 'place-ship',
            ],
        ],
    ],

    'api-clear-field' => [
        'type' => Http\Segment::class,
        'options' => [
            'route'    => '/api/clear-field/:id/:code',
            'defaults' => [
                'controller' => Controller\ApiController::class,
                'action'     => 'clear-field',
            ],
        ],
    ],

    'api-ready' => [
        'type' => Http\Segment::class,
        'options' => [
            'route'    => '/api/ready/:id/:code',
            'defaults' => [
                'controller' => Controller\ApiController::class,
                'action'     => 'ready',
            ],
        ],
    ],

    'api-shot' => [
        'type' => Http\Segment::class,
        'options' => [
            'route'    => '/api/shot/:id/:code',
            'defaults' => [
                'controller' => Controller\ApiController::class,
                'action'     => 'shot',
            ],
        ],
    ],

    'api-chat-load' => [
        'type' => Http\Segment::class,
        'options' => [
            'route'    => '/api/chat-load/:id/:code',
            'defaults' => [
                'controller' => Controller\ApiController::class,
                'action'     => 'chat-load',
            ],
        ],
    ],

    'api-chat-send' => [
        'type' => Http\Segment::class,
        'options' => [
            'route'    => '/api/chat-send/:id/:code',
            'defaults' => [
                'controller' => Controller\ApiController::class,
                'action'     => 'chat-send',
            ],
        ],
    ],
];
