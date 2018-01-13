import Logger from "./Logger";

export default class WarningLogger extends Logger {
    _writeMessage() {
        console.warn(...arguments);
    }
}