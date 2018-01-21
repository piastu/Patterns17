from Chain.Chain import Chain
from Chain.NoElementException import NoElementException
from View.IView import IView


class BaseState:
    """ Базовый класс состояния View """

    def __init__(self, view):
        assert isinstance(view, IView), \
            "Ошибка в BaseState.__init__(view):\n" \
            "view должен реализовывать интерфейс IView"
        self.__view = view
        self.__chain = Chain()

    @property
    def chain(self):
        return self.__chain

    @property
    def view(self):
        return self.__view

    def to_init_state(self):
        """ Начальное состояние """
        raise NotImplementedError()

    def to_predict_state(self):
        """ состояние классификации объекта """
        raise NotImplementedError()

    def to_close_state(self):
        """ состояние закрытия приложения """
        raise NotImplementedError()

    def to_current_state(self):
        raise NotImplementedError()

    def to_previous_state(self):
        raise NotImplementedError()

    def to_concrete_classifier_state(self, classifier_type):
        raise NotImplementedError()

    def classify_object(self, code):
        raise NotImplementedError()

    def send_action(self, action):
        """ Отрпавить сообщение в цепочку обязанностей """
        try:
            self.__chain.do_action(action)
            return True
        except NoElementException:
            return None

    def state_info(self):
        return self.__chain.get_info()