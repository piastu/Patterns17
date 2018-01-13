import InfoLogger from "./InfoLogger";
import WarningLogger from "./WarningLogger";
import ErrorLogger from "./ErrorLogger";
import Logger from "./Logger";

export default class Log {
    static log(message, mask = 'Info') {
        Log.mainLogger = new InfoLogger(Logger.INFO);
        Log.warningLogger = Log.mainLogger.Next = new WarningLogger(Logger.WARNING);
        Log.errorLogger = Log.warningLogger.Next = new ErrorLogger(Logger.ERROR);

        Log.mainLogger.msg(message, mask);
    }
}