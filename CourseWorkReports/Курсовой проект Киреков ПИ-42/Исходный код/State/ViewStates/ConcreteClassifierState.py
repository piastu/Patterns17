# команды
import State.ViewStates.InitState
import State.ViewStates.PredictState
from Command.PredictCommands.ConcreteClassifierCommand import ConcreteClassifierCommand
from Command.PreviousStateCommand import PreviousStateCommand
from Command.ShowHelpCommand import ShowHelpCommand
# состояния
from State.ViewStates.BaseState import BaseState


class ConcreteClassifierState(BaseState):
    """ состояние выбора конкретного классификатора """

    def __init__(self, view, classifier_type_code):
        super().__init__(view)
        self.__classifier_type_code = classifier_type_code
        self.__make_chain()

    def __make_chain(self):
        self.chain.add_element(ShowHelpCommand(self))
        self.chain.add_element(PreviousStateCommand(self))
        # получим список классификаторов
        # в зависимости от выбранного типа в предыдущем состоянии.
        # Добавим их как команды в цепочку обязанностей
        for record in self.view.controller.get_concrete_classifiers_by_command_type(self.__classifier_type_code):
            self.chain.add_element(
                ConcreteClassifierCommand(self, record['command'], record['code'], record['name'])
            )

    def to_current_state(self):
        self.view.show_help()

    def to_previous_state(self):
        self.view.current_state = State.ViewStates.PredictState.PredictState(self.view)

    def to_init_state(self):
        self.view.current_state = State.ViewStates.InitState.InitState(self.view)

    def classify_object(self, code):
        # если пользователь выбрал объект для классификации
        # вернемся в начальное состояние
        if self.view.predict(self.__classifier_type_code, code) is True:
            self.to_init_state()
        # иначе - в предыдущее
        else:
            self.to_previous_state()