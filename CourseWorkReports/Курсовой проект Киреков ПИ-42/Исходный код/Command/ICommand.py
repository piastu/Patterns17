from abc import ABCMeta, abstractmethod


class ICommand:
    """ Интерфейс для команды """
    __metaclass__ = ABCMeta

    @abstractmethod
    def execute(self):
        """ Выполнить команду """
