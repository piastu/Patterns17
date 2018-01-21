from orator import DatabaseManager, Model as mod

from Model.Classifiers.FactoryClassifiers import FactoryClassifiers
from Model.Log import Log
from Model.ORM.ModelORM import ClassifierType, ClassifierInfo


class Model:

    def __init__(self, config_database):
        try:
            self.__db = DatabaseManager(config_database)
            mod.set_connection_resolver(self.__db)
        except Exception as err:
            print('Ошибка соединения с базой данных. Информация сохранена в логи')
            print(err)
            Log.log_error('Соединение с базой данных не установлено: {0}'.format(err))
            exit(1)

    def get_object_types(self):
        return ClassifierType.all()

    def get_classifiers_by_type(self, classifier_type_code):
        """ вернуть все классификаторы выбранного типа """
        row = self.__db.table('classifiertype').where('Code', classifier_type_code).first()
        return ClassifierType.find(row['ID']).classifiers_info

    def classify_object(self, code_classifier_type, code_classifier, object_path):
        """ классифицировать объект """

        # в зависимости от типа классификатора с помощью фабрики
        # вернем соответствующий класс-классификатор
        classifier = FactoryClassifiers.get_classifier(code_classifier_type)
        if classifier is None:
            return {'ok': False, 'message': 'Классификатор с таким кодом отсутствует'}

        # получим информацию о классификаторе
        classifier_info = self.__db.table('classifierinfo').where('Code', code_classifier).first()
        # и об алиасах
        classifier_aliases = ClassifierInfo.find(classifier_info['ID']).classifier_aliases

        # преобразуем в необходимый вид
        aliases = {}
        for alias in classifier_aliases:
            aliases[alias.Index] = alias.Name

        # формат входных данных (в бд размерности хранятся в виде строки чисел через пробел)
        input_shape = tuple([int(x) for x in classifier_info['InputFormat'].split()])

        classifier.init_classifier(classifier_info['ClassifierFile'], input_shape, aliases)

        return classifier.classify(object_path)
