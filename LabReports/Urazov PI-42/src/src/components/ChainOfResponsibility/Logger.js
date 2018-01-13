export default class Logger {
    static get INFO() {
        return 'Info';
    }

    static get WARNING() {
        return 'Warning';
    }

    static get ERROR() {
        return 'Error';
    }

    constructor(mask = 'Info') {
        switch (mask) {
            case 'Warning':
            case 'Error':
                this.mask = mask;
                break;
            case 'Info':
            default:
                this.mask = 'Info';
        }
    }

    get Next() {
        return this.next;
    }

    set Next(logger) {
        this.next = logger;
        return logger;
    }

    msg(message, mask = 'Info') {
        if (mask === this.mask) {
            this._writeMessage(message);
        } else {
            this.Next.msg(message, mask);
        }
    }

    _writeMessage() {
    }
}