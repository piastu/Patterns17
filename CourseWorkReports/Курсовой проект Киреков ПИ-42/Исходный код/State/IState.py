from abc import abstractmethod, ABCMeta


class IState:
    __metaclass__ = ABCMeta

    @abstractmethod
    def execute(self, sender):
        """ Выполнить операцию """
