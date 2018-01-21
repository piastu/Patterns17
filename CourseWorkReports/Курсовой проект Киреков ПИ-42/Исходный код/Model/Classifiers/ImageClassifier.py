import keras
import numpy as np
from keras.preprocessing import image

from .IClassifier import IClassifier


class ImageClassifier(IClassifier):
    """ классификатор изображений """

    def __init__(self):
        self.__input_shape = None
        self.__aliases = None
        self.__model = None

    def init_classifier(self, h5file_path, input_shape, aliases):
        self.__input_shape = input_shape
        self.__aliases = aliases
        self.__model = keras.models.load_model(h5file_path)

    def classify(self, img_path):
        try:
            img = image.load_img(img_path, target_size=self.__input_shape)
            img = image.img_to_array(img)
            x = np.expand_dims(img, axis=0) / 255
            a = self.__model.predict(x)[0]
        except:
            return {'ok': False, 'message': 'На вход не было подано изображение'}
        res = []
        for i in range(len(a)):
            res.append('С вероятностью {0}% это {1}'.format(a[i] * 100, self.__aliases[i]))
        return {'ok': True, 'result': res}
