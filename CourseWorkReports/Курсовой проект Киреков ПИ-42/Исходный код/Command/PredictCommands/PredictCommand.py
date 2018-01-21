from Chain.AbstractChainElement import AbstractChainElement
from State.ViewStates.BaseState import BaseState
from ..CommandsKeys import CommandsKeys
from ..ICommand import ICommand


class PredictCommand(AbstractChainElement, ICommand):
    """ Команда перехода в состояние PredictState """

    def __init__(self, state):
        self.__key = CommandsKeys.predict()
        super().__init__(self.__key, None)
        assert isinstance(state, BaseState), \
            "Ошибка в PredictCommand.__init__():\n" \
            "state должен наследовать/быть объектом класса BaseState"
        self.__state = state

    def execute(self):
        self.__state.to_predict_state()

    def do(self, action_type):
        # если тип действия относится к элементу цепочки
        if self._action_type == action_type:
            # выполним команду
            self.execute()
        else:
            # иначе, обратимся к следующему
            self._do_next(action_type)

    def get_info(self):
        return {'command': self.__key, 'text': 'Классифицировать объект'}
