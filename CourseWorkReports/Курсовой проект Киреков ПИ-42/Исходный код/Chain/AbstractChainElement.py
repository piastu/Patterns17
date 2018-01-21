from abc import abstractmethod, ABCMeta
from .NoElementException import NoElementException


class AbstractChainElement:
    """ Абстрактный класс для элементов цепочки обязанностей """
    __metaclass__ = ABCMeta

    def __init__(self, action_type, next_element=None):
        self._action_type = action_type
        self._next_element = next_element

    def _do_next(self, action_type):
        next_el = self.next
        # если цепочка закончилась, вызовем исключение
        if next_el is None:
            raise NoElementException()
        next_el.do(action_type)

    @abstractmethod
    def do(self, action_type):
        """ Выполнить действие для этого элемента """

    @abstractmethod
    def get_info(self):
        """ Получить информацию об элементе цепочки """

    @property
    def next(self):
        return self._next_element

    @next.setter
    def next(self, other):
        self._next_element = other


