import ISort from "../interfaces/ISort";

export default class MergeSort extends ISort {
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
        let colorBlocks = this.scene.childNodes,
            timerID,
            baseCoefficient = 1,
            ratio = 1;

        let BlockSizeIterator = 1, BlockIterator = 0, LeftBlockIterator, RightBlockIterator, MergeIterator;

        let LeftBorder, MidBorder, RightBorder;

        const iteration = () => {
            //Производим слияние с сортировкой пары блоков начинающуюся с элемента BlockIterator
            //левый размером BlockSizeIterator, правый размером BlockSizeIterator или меньше
            LeftBlockIterator = 0;
            RightBlockIterator = 0;
            LeftBorder = BlockIterator;
            MidBorder = BlockIterator + BlockSizeIterator;
            RightBorder = BlockIterator + 2 * BlockSizeIterator;
            RightBorder = (RightBorder < colorBlocks.length) ? RightBorder : colorBlocks.length;
            let SortedBlock = [];

            //Пока в обоих массивах есть элементы выбираем меньший из них и заносим в отсортированный блок
            while (LeftBorder + LeftBlockIterator < MidBorder && MidBorder + RightBlockIterator < RightBorder) {
                let condition;
                switch (direction) {
                    case 'reverse':
                        condition = parseInt(colorBlocks[LeftBorder + LeftBlockIterator].dataset.hsv, 10) > parseInt(colorBlocks[MidBorder + RightBlockIterator].dataset.hsv, 10);
                        break;
                    case 'shuffle':
                    case 'random':
                    case 'rand':
                        condition = (Math.random() - 0.5) > 0;
                        break;
                    default:
                        condition = parseInt(colorBlocks[LeftBorder + LeftBlockIterator].dataset.hsv, 10) < parseInt(colorBlocks[MidBorder + RightBlockIterator].dataset.hsv, 10);
                }
                if (condition) {
                    SortedBlock[LeftBlockIterator + RightBlockIterator] = colorBlocks[LeftBorder + LeftBlockIterator];
                    LeftBlockIterator += 1;
                }
                else {
                    SortedBlock[LeftBlockIterator + RightBlockIterator] = colorBlocks[MidBorder + RightBlockIterator];
                    RightBlockIterator += 1;
                }
            }
            //После этого заносим оставшиеся элементы из левого или правого блока
            while (LeftBorder + LeftBlockIterator < MidBorder) {
                SortedBlock[LeftBlockIterator + RightBlockIterator] = colorBlocks[LeftBorder + LeftBlockIterator];
                LeftBlockIterator += 1;
            }
            while (MidBorder + RightBlockIterator < RightBorder) {
                SortedBlock[LeftBlockIterator + RightBlockIterator] = colorBlocks[MidBorder + RightBlockIterator];
                RightBlockIterator += 1;
            }

            for (MergeIterator = 0; MergeIterator < LeftBlockIterator + RightBlockIterator; MergeIterator++) {
                // colorBlocks[LeftBorder + MergeIterator] = SortedBlock[MergeIterator];
                this.scene.insertBefore(SortedBlock[MergeIterator], colorBlocks[LeftBorder + MergeIterator]);
            }
            BlockIterator += 2 * BlockSizeIterator;
            if (BlockIterator < colorBlocks.length - BlockSizeIterator) {
                timerID = setTimeout(iteration, baseCoefficient * ratio);
            } else {
                BlockSizeIterator *= 2;
                BlockIterator = 0;
                // ratio *= (ratio < 16 ? 2 : 1);
                // console.log(ratio);
                if (BlockSizeIterator < colorBlocks.length) {
                    timerID = setTimeout(iteration, baseCoefficient * ratio);
                } else {
                    clearTimeout(timerID);
                    console.log('set event "sorted" with ' + (((new Date() - timestamp) / 1000) / 60*60) + ' seconds');
                    this.scene.dispatchEvent(this.eventSorted);
                }
            }
        };
        // for (BlockSizeIterator = 1; BlockSizeIterator < array.length; BlockSizeIterator *= 2) {
        //     for (BlockIterator = 0; BlockIterator < array.length - BlockSizeIterator; BlockIterator += 2 * BlockSizeIterator) {
        //     }
        // }
        if ((BlockSizeIterator < colorBlocks.length) && (BlockIterator < colorBlocks.length - BlockSizeIterator)) {
            timerID = setTimeout(iteration, baseCoefficient * ratio);
        }
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