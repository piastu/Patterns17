import json
import os.path

from Model.Model import Model
from View.ConsoleView import ConsoleView
from .AbstractController import AbstractController


class Controller(AbstractController):

    def __init__(self):
        self.__view = ConsoleView(self)
        self.__config_db = None
        self.__classifier_types = None
        self.__init_configs()
        self.__model = Model(self.__config_db)

    def __init_configs(self):
        """ загрузить конфиги в переменные для последующего обращения к ним """
        # инициализация конфига для базы данных
        with open('Data/configs/configDatabase.json') as file:
            config_temp = json.load(file)
            self.__config_db = dict()
            self.__config_db['default'] = config_temp['driver']
            self.__config_db[self.__config_db['default']] = config_temp

    def run_app(self):
        self.__view.start_view()

    def close_app(self):
        exit(0)

    def get_predict_types(self):
        """ получить список типов предсказываемых объектов """
        # получим запрос из бд
        types = self.__model.get_object_types()
        target = []
        # преобразуем к нужной форме
        for i, record in enumerate(types):
            target.append({
                'name': record.Name,
                'command': '-' + str(i + 1),
                'code': record.Code
            })
        return tuple(target)

    def get_concrete_classifiers_by_command_type(self, classifier_type_code):
        """ получить список конкретных классификаторов по выбранному типу """
        classifiers = self.__model.get_classifiers_by_type(classifier_type_code)
        target = []
        for i, record in enumerate(classifiers):
            target.append({
                'name': record.Name,
                'code': record.Code,
                'command': '-' + str(i + 1)
            })
        return tuple(target)

    def classify_object(self, code_classifier_type, code_classifier, object_path):
        if not os.path.isfile(object_path):
            return {
                'ok': False,
                'message': 'Файла по такому пути не существует'
            }
        return self.__model.classify_object(code_classifier_type, code_classifier, object_path)