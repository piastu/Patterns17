import Snowflake from "./Snowflake";
import Log from "../ChainOfResponsibility/Log";

export default class Pool {
    constructor(count = 50) {
        if (Pool.instance) {
            // console.log('Pool already exists!');
            //Вместо обычного лога используем наш логгер
            Log.log("Pool already exists!", 'Error');
            throw (new Error('Pool already exists!'));
        }
        this.Instance(count);
        this.getSnowflake = this.getSnowflake.bind(this);
        this.delSnowflakes = this.delSnowflakes.bind(this);
        this.letItSnow = this.letItSnow.bind(this);
    }

    static set instance(val) {
        this._instance = val;
    }

    static get instance() {
        return this._instance;
    }

    Instance(count = 50) {
        this.used = [];
        this.unused = [];
        // for (let i = 0; i < count; i++) {
        //     this.getSnowflake();
        // }
        let i = 0;
        const getOneSnowflake = () => {
            this.getSnowflake();
            if (i++ < count) {
                timer = setTimeout(getOneSnowflake, 500);
            } else {
                clearTimeout(timer);
            }
        };
        let timer = setTimeout(getOneSnowflake, 500);
        Pool.instance = this;
    }

    getSnowflake(params = {}) {
        let ret = this.unused.pop() || (new Snowflake()).htmlNode;
        this.used.push(ret);
        document.body.appendChild(ret);
        return ret;
    }

    delSnowflakes(snowflakes) {
        let idx = this.used.indexOf(snowflakes),
            ret = this.used.splice(idx, 1)[0];
        ret.style.top = '0px';
        ret.style.left = rand(0, document.documentElement.clientWidth - 30) + 'px';
        this.unused.push(ret);
        document.body.removeChild(ret);
        return ret;
    }

    letItSnow() {
        const tick = () => {
            try {
                this.used.forEach((curr) => {
                    curr.style.top = (parseInt(curr.style.top, 10) + rand(-1, 10)) + 'px';
                    curr.style.left = ((parseInt(curr.style.left, 10) || 0) + rand(-10, 10)) + 'px';
                    if (parseInt(curr.style.top, 10) > document.documentElement.clientHeight - 30 || parseInt(curr.style.left, 10) > document.documentElement.clientWidth - 30 || parseInt(curr.style.left, 10) < 0) {
                        this.delSnowflakes(curr);
                        this.getSnowflake();
                    }
                });
            } catch (e) {
                console.log(e);
                debugger;
                // clearTimeout(timer);
            }
            timer = setTimeout(tick, 100);
        };

        //start
        // eslint-disable-next-line
        let timer = setTimeout(tick, 100);
    }
}

const rand = (min = 0, max = 1) => {
    return min + Math.random() * (max - min);
};
