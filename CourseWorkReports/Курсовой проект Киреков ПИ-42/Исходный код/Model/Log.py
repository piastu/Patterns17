import os
import time


class Log:
    """ статический класс для логирование информации """

    @staticmethod
    def __root_log_file_path():
        """ корневая папка для логов """
        return 'LogFiles'

    @staticmethod
    def norm_path(path):
        """ нормализация пути """
        return os.path.normpath(path)

    @staticmethod
    def __get_main_log_file_path():
        """ путь к главному логу """
        return Log.norm_path('{0}/main.log'.format(Log.__root_log_file_path()))

    @staticmethod
    def __get_errors_log_file_path():
        """ путь к логу ошибок """
        return Log.norm_path('{0}/errors.log'.format(Log.__root_log_file_path()))

    @staticmethod
    def __write_log(files, type_log, text):
        """ записать информацию в лог(и) """
        t = time.localtime()
        target = '[{0:2}.{1:2}.{2:4} {3:2}:{4:2}:{5:2}] {6:20}: {7}\n' \
            .format(
            t.tm_mday,  # день
            t.tm_mon,  # месяц
            t.tm_year,  # год
            t.tm_hour,  # час
            t.tm_min,  # минута
            t.tm_sec,  # секунда
            type_log,  # тип лога
            text  # текст ошибки
        )
        for file in files:
            with open(file, 'a') as file_thread:
                file_thread.write(target)

    @staticmethod
    def log_error(error_text):
        Log.__write_log((Log.__get_errors_log_file_path(), Log.__get_main_log_file_path()),
                        'Ошибка',
                        error_text)
