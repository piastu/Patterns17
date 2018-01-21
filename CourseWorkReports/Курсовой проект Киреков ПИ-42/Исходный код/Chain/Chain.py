from .AbstractChainElement import AbstractChainElement
from .NoElementException import NoElementException


class Chain:
    """ Класс цепочки обязанностей """

    def __init__(self):
        self.__start_element = None

    def add_element(self, element):
        """ добавить элемент в цепочку """
        assert isinstance(element, AbstractChainElement), \
            "Ошибка в Chain.add_element(element):" \
            "element должен наследовать от абстрактного класса AbstractChainElement"

        # если цепочка пустая, то ее началом будет элемент
        if self.__start_element is None:
            self.__start_element = element
        # иначе вставлем элемент в самый конец
        else:
            el = self.__start_element
            while el.next is not None:
                el = el.next
            el.next = element

    def do_action(self, action_type):
        if self.__start_element is None:
            raise NoElementException()
        self.__start_element.do(action_type)

    def get_info(self):
        """ Получить информацию в виде кортежа обо всех элементах цепочки """
        info = []
        element = self.__start_element
        while element is not None:
            info.append(element.get_info())
            element = element.next
        return tuple(info)
