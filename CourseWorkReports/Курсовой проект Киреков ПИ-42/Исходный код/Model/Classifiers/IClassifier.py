from abc import ABCMeta, abstractmethod


class IClassifier:
    __metaclass__ = ABCMeta

    @abstractmethod
    def init_classifier(self, h5file_path, input_shape, aliases):
        """ инициализация классификатора """

    @abstractmethod
    def classify(self, object_path):
        """ классифицировать объект """
