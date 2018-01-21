# команды
from Command.CloseAppCommand import CloseAppCommand
from Command.PredictCommands.PredictCommand import PredictCommand
from Command.ShowHelpCommand import ShowHelpCommand
from State.ViewStates.BaseState import BaseState
# стейты
from State.ViewStates.PredictState import PredictState


class InitState(BaseState):

    def __init__(self, view):
        super().__init__(view)
        self.__make_chain()

    def __make_chain(self):
        self.chain.add_element(ShowHelpCommand(self))
        self.chain.add_element(CloseAppCommand(self))
        self.chain.add_element(PredictCommand(self))

    def to_current_state(self):
        self.view.show_help()

    def to_close_state(self):
        self.view.close_app()

    def to_predict_state(self):
        self.view.current_state = PredictState(self.view)
