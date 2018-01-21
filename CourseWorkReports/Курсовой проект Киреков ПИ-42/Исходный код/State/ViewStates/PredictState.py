# команды
import State.ViewStates.InitState
from Command.PredictCommands.ClassifierTypeCommand import ClassifierTypeCommand
from Command.PreviousStateCommand import PreviousStateCommand
from Command.ShowHelpCommand import ShowHelpCommand
# состояния
from State.ViewStates.BaseState import BaseState
from State.ViewStates.ConcreteClassifierState import ConcreteClassifierState


class PredictState(BaseState):

    def __init__(self, view):
        super().__init__(view)
        self.__make_chain()

    def __make_chain(self):
        self.chain.add_element(ShowHelpCommand(self))
        self.chain.add_element(PreviousStateCommand(self))
        # получим список типов предсказываемых объетов,
        # добавим их как команды в цепочку обязанностей
        for record in self.view.controller.get_predict_types():
            self.chain.add_element(ClassifierTypeCommand(self, record['command'], record['code'], record['name']))

    def to_current_state(self):
        self.view.show_help()

    def to_previous_state(self):
        """ вернуться в предыдущее состояние (InitState) """
        self.view.current_state = State.ViewStates.InitState.InitState(self.view)

    def to_concrete_classifier_state(self, classifier_type_code):
        self.view.current_state = ConcreteClassifierState(self.view, classifier_type_code)
