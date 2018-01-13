import Logger from "./Logger";

export default class ErrorLogger extends Logger {
    _writeMessage() {
        console.error(...arguments);
    }
}