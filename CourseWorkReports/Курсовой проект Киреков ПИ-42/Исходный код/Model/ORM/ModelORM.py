from orator import Model
from orator.orm import has_many, belongs_to


class ClassifierType(Model):
    """ Таблица в бд 'сlassifiertype' """
    __table__ = 'classifiertype'

    @has_many('IDClassifierType', 'ID')
    def classifiers_info(self):
        """ связь 1 -> * (classifiertype (1) -> classifierinfo (*)) """
        return ClassifierInfo


class ClassifierInfo(Model):
    """ Таблица в бд 'сlassifierinfo' """
    __table__ = 'classifierinfo'

    @has_many('IDClassifierInfo', 'ID')
    def classifier_aliases(self):
        """ связь 1 -> * (classifierinfo (1) -> classifieraliases (*)) """
        return ClassifierAliases

    @belongs_to('IDClassifierType', 'ID')
    def classifier_type(self):
        """ связь 1 -> * (classifiertype (1) -> classifierinfo (*)) """
        return ClassifierType


class ClassifierAliases(Model):
    """ Таблица в бд 'сlassifieraliases' """
    __table__ = 'classifieraliases'

    @belongs_to('IDClassifierInfo', 'ID')
    def classifier_info(self):
        """ связь 1 -> * (classifierinfo (1) -> classifieraliases (*)) """
        return ClassifierInfo
