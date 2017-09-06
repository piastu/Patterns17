<?

namespace Application\Helper;

use Application\Entity\Field;

class BattleCube extends \Zend\View\Helper\AbstractHelper {

    public function __invoke() {
        return $this;
    }

    public function render($classes, $showOverlay = false) {
        $result = $this->getView()->render('helper/battle-cube.phtml', [
            'size' => Field::SIZE,
            'classes' => $classes,
            'showOverlay' => $showOverlay
        ]);
        return $result;
    }
}