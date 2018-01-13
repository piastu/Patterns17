//IImplementor ("интерфейс")
export default class IImplementor {
    constructor(scene) {
        this.scene = scene;
        this.eventSorted = new Event('sorted', { bubbles: true, cancelable: true });
        this.algorithm = this.algorithm.bind(this);
    }

    algorithm(direction = '') {
        const timestamp = new Date();
        let colorBlocks = this.scene.childNodes,
            i = 0, j = 0;
        const iteration = () => {
            let color1 = parseInt(colorBlocks[j].dataset.hsv, 10),
                color2 = parseInt(colorBlocks[j + 1].dataset.hsv, 10),
                condition;
            switch (direction) {
                case 'reverse':
                    condition = color1 < color2;
                    break;
                case 'shuffle':
                case 'random':
                case 'rand':
                    condition = (Math.random() - 0.5) > 0;
                    break;
                default:
                    condition = color1 > color2;
            }
            if (condition) {
                this.swap(colorBlocks, j);
            }
            if (j < colorBlocks.length - 2 - i) {
                j++;
                timerID = setTimeout(iteration, 1, direction);
            } else {
                if (i < colorBlocks.length - 2) {
                    i++;
                    j = 0;
                    timerID = setTimeout(iteration, 1, direction);
                } else {
                    clearTimeout(timerID);
                    this.finish(colorBlocks);
                    console.log('set event "sorted" with ' + (((new Date() - timestamp) / 1000) / 60 * 60) + ' seconds');
                    this.scene.dispatchEvent(this.eventSorted);
                }
            }
        };
        let timerID = setTimeout(iteration, 1, direction);
    }

    swap(array, firstIndex) {
    }

    finish(array) {
    }
}