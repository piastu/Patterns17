from Controller.AbstractController import AbstractController
from State.ViewStates.BaseState import BaseState
from State.ViewStates.InitState import InitState
from .IView import IView


class ConsoleView(IView):

    def __init__(self, controller):
        assert isinstance(controller, AbstractController), \
            "Ошибка в ConsoleView.__init__:\n" \
            "controller должен быть наследником AbstractController"
        self.__controller = controller
        self.__state = None

    def __wait_input(self):
        """ ожидание ввода """
        print()
        command = input()
        # если команда потерялась в цепочке обязанностей текущего состояния
        if self.current_state.send_action(command) is None:
            print('Неопознанная команда')

    @property
    def current_state(self):
        """ Получить текущее состояние """
        return self.__state

    @current_state.setter
    def current_state(self, state):
        """ Установить новое состояние """
        assert isinstance(state, BaseState), \
            "Ошибка в ConsoleView.current_state.setter:" \
            "state должен быть наследником/экземпляром класса BaseState"
        self.__state = state
        self.show_help()

    @property
    def controller(self):
        """ указатель на контроллер """
        return self.__controller

    def start_view(self):
        print('--- Классификатор объектов с помощью нейронных сетей ---')
        self.__state = InitState(self)
        self.show_help()
        while True:
            self.__wait_input()

    def show_help(self):
        info = self.current_state.state_info()
        for record in info:
            print('{0:10} - {1}'.format(record['command'], record['text']))

    def close_app(self):
        self.controller.close_app()

    def predict(self, classifier_type_code, classifier_code):
        print('Введите путь к объекту, который необходимо классифицировать.\n'
              'Нажмите Enter, чтобы вернуться в меню')
        while True:
            path = input()
            if path == "" or path == "\n":
                return False
            result = self.controller.classify_object(classifier_type_code, classifier_code, path)
            if not result['ok']:
                print('Ошибка: {0}'.format(result['message']))
            else:
                print('-------------Результат-----------')
                for row in result['result']:
                    print(row)
                print('---------------------------------')
                return True
