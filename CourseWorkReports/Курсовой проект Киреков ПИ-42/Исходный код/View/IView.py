from abc import ABCMeta, abstractmethod


class IView:
    __metaclass__ = ABCMeta

    @property
    @abstractmethod
    def controller(self):
        """ получить указатель на контроллер """

    @abstractmethod
    def start_view(self):
        """ Вывести View на экран """

    @abstractmethod
    def show_help(self):
        """ показать помощь """

    @abstractmethod
    def close_app(self):
        """ Завершить работу приложения """

    @abstractmethod
    def predict(self, classifier_type_code, classifier_code):
        """ подать объект на вход обученнной нейросети и получить результат """

    @property
    @abstractmethod
    def current_state(self):
        """ getter текущего состояние view """

    @current_state.setter
    def current_state(self, state):
        """ setter текущего состояние """
