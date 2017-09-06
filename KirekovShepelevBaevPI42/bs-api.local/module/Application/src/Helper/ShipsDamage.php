<?

namespace Application\Helper;

class ShipsDamage extends \Zend\View\Helper\AbstractHelper {

    public function __invoke() {
        return $this;
    }

    public function render() {
        $result = $this->getView()->render('helper/ships-damage.phtml', []);
        return $result;
    }
}