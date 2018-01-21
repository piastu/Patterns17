from .ImageClassifier import ImageClassifier


class FactoryClassifiers:
    """ простая фабрика классификаторов """

    @staticmethod
    def get_classifier(classifier_code):
        if classifier_code == 1:
            return ImageClassifier()
        else:
            return None
