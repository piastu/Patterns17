// Abstraction
export default class Abstraction {
    constructor() {
        this.implementor = null;
    }

    getImplementor() {
        return this.implementor;
    }

    setImplementor(val) {
        this.implementor = val;
    }

    doSort() {
        this.implementor.algorithm();
    }

    doShuffle() {
        this.implementor.algorithm('shuffle');
    }

    doReverse() {
        this.implementor.algorithm('reverse');
    }
}