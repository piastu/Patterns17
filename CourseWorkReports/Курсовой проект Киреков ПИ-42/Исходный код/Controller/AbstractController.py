from abc import ABCMeta, abstractmethod


class AbstractController:
    __metaclass__ = ABCMeta

    @abstractmethod
    def run_app(self):
        """ Запустить приложение. Вызывается при старте программы """

    @abstractmethod
    def close_app(self):
        """ Завершить работу приложения """

    @abstractmethod
    def get_predict_types(self):
        """ получить типы предсказываемых объектов """

    @abstractmethod
    def get_concrete_classifiers_by_command_type(self, command):
        """ получить список конкретных классификаторов по выбранной ранее команде """

    @abstractmethod
    def classify_object(self, code_classifier_type, code_classifier, object_path):
        """ классифицировать объект """
