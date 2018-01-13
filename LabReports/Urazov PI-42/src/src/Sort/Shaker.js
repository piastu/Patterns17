import ISort from "../interfaces/ISort";

export default class Shaker extends ISort {
    constructor(scene) {
        super();
        this.scene = scene;
        this.eventSorted = new Event('sorted', { bubbles: true, cancelable: true });
        this.algorithm = this.algorithm.bind(this);
        this.doSort = this.doSort.bind(this);
        this.doShuffle = this.doShuffle.bind(this);
        this.doReverse = this.doReverse.bind(this);
    }

    algorithm(direction = '') {
        const timestamp = new Date();
        let timerIterUp, timerIterDown;
        let colorBlocks = this.scene.childNodes,
            idx = 0,
            leftIndex = 0,
            rightIndex = colorBlocks.length - 1;

        //один проход вверх (первый внутренний цикл)
        const iterationUp = () => {
            if (idx < rightIndex) {
                let color1 = parseInt(colorBlocks[idx].dataset.hsv, 10),
                    color2 = parseInt(colorBlocks[idx + 1].dataset.hsv, 10),
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
                    this.scene.insertBefore(colorBlocks[idx + 1], colorBlocks[idx]);
                }
                idx++;
                timerIterUp = setTimeout(iterationUp, 1, direction);
            } else {
                clearTimeout(timerIterUp);
                rightIndex--;
                timerIterDown = setTimeout(iterationDown, 1, direction);
            }
        };

        //один проход вниз (второй внутренний цикл)
        const iterationDown = () => {
            if (idx > leftIndex) {
                let color1 = parseInt(colorBlocks[idx].dataset.hsv, 10),
                    color2 = parseInt(colorBlocks[idx - 1].dataset.hsv, 10),
                    condition;
                switch (direction) {
                    case 'reverse':
                        condition = color1 > color2;
                        break;
                    case 'shuffle':
                    case 'random':
                    case 'rand':
                        condition = (Math.random() - 0.5) > 0;
                        break;
                    default:
                        condition = color1 < color2;
                }
                if (condition) {
                    this.scene.insertBefore(colorBlocks[idx], colorBlocks[idx - 1]);
                }
                idx--;
                timerIterDown = setTimeout(iterationDown, 1, direction);
            } else {
                clearTimeout(timerIterDown);
                leftIndex++;
                if (leftIndex < rightIndex) {
                    timerIterUp = setTimeout(iterationUp, 1, direction);
                } else {
                    console.log('set event "sorted" with ' + (((new Date() - timestamp) / 1000) / 60*60) + ' seconds');
                    this.scene.dispatchEvent(this.eventSorted);
                }
            }
        };
        if (leftIndex < rightIndex) {
            timerIterUp = setTimeout(iterationUp, 1, direction);
        }
        // function shakerSort(array) {
        //     let leftIndex = 0;
        //     let rightIndex = array.length - 1;
        //
        //     while (leftIndex < rightIndex) {
        //         for (let idx = leftIndex; idx < rightIndex; idx++) {
        //             if (array[idx] > array[idx + 1]) {
        //                 swap(array, idx, idx + 1)
        //             }
        //         }
        //         rightIndex--;
        //
        //         for (let idx = rightIndex; idx > leftIndex; idx--) {
        //             if (array[idx] < array[idx - 1]) {
        //                 swap(array, idx, idx - 1)
        //             }
        //         }
        //         leftIndex++;
        //     }
        //
        //     return array
        // }
    }

    doSort() {
        this.algorithm();
    }

    doShuffle() {
        this.algorithm('shuffle');
    }

    doReverse() {
        this.algorithm('reverse');
    }
}