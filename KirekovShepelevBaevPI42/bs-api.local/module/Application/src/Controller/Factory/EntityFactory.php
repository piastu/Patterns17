<?php
namespace Application\Controller\Factory;

use Interop\Container\ContainerInterface;
use Zend\ServiceManager\Factory\FactoryInterface;
use Application\Controller\IndexController;

/**
 * Это фабрика для IndexController. Ее целью является инстанцирование
 * контроллера.
 */
class EntityFactory implements FactoryInterface
{
    public function __invoke(ContainerInterface $container, $requestedName, array $options = null)
    {
        $entityManager = $container->get('doctrine.entitymanager.orm_default');

        // Инстанцируем контроллер и внедряем зависимости.
        return new $requestedName($entityManager);
    }
}