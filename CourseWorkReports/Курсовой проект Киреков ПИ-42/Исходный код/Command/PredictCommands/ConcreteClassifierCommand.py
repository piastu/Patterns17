from Chain.AbstractChainElement import AbstractChainElement
from State.ViewStates.BaseState import BaseState
from ..CommandsKeys import CommandsKeys
from ..ICommand import ICommand


class ConcreteClassifierCommand(AbstractChainElement, ICommand):
    """ Команда выбора конкретного классификатора """

    def __init__(self, state, command, code, text_info):
        self.__key = command
        self.__text_info = text_info
        self.__code = code
        super().__init__(self.__key, None)
        assert isinstance(state, BaseState), \
            "Ошибка в ConcreteClassifierCommand.__init__():\n" \
            "state должен наследовать/быть объектом класса BaseState"
        self.__state = state

    def execute(self):
        self.__state.classify_object(self.__code)

    def do(self, action_type):
        # если тип действия относится к элементу цепочки
        if self._action_type == action_type:
            # выполним команду
            self.execute()
        else:
            # иначе, обратимся к следующему
            self._do_next(action_type)

    def get_info(self):
        return {'command': self.__key, 'text': self.__text_info}
