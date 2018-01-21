class CommandsKeys:
    """ перечисление возможных команд """

    @staticmethod
    def predict():
        """ PredictState """
        return '-predict'

    @staticmethod
    def show_help():
        """ Вызвать текущее состояние еще раз """
        return '-help'

    @staticmethod
    def close_app():
        return '-close'

    @staticmethod
    def main_menu():
        """ InitState """
        return '-main'

    @staticmethod
    def previous_state():
        """ предыдущий пункт меню """
        return '-previous'
