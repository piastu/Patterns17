import Logger from "./Logger";

export default class InfoLogger extends Logger {
    _writeMessage() {
        console.info(...arguments);
    }
}