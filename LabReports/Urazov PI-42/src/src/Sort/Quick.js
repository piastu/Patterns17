export default class Quick {
    constructor(scene, eventSorted, updateProgress, updateTimestamp) {
        this.scene = scene;
        this.eventSorted = eventSorted;
        this.updateProgress = updateProgress;
        this.updateTimestamp = updateTimestamp;

    }

    doSort = (shuffle = false) => {
        let colorBlocks = this.scene.childNodes;
        const timestamp = new Date();

        const swap = (scene, items, firstIndex, secondIndex) => {
            const temp = items[firstIndex].cloneNode(true);
            scene.replaceChild(items[secondIndex], items[firstIndex]);
            scene.insertBefore(temp, items[secondIndex]);
        };

        // const partition = (scene, items, left, right) => {
        //     let pivot = parseInt(items[Math.floor((right + left) / 2)].dataset.hsv, 10),
        //         i = left,
        //         j = right;
        //
        //     while (i <= j) {
        //         while (parseInt(items[i].dataset.hsv, 10) > pivot) {
        //             i++;
        //         }
        //         while (parseInt(items[j].dataset.hsv, 10) < pivot) {
        //             j--;
        //         }
        //         if (i <= j) {
        //             swap(scene, items, i, j);
        //             i++;
        //             j--;
        //         }
        //     }
        //     return i;
        // };

        const quickSort = (scene, items, left = 0, right = items.length - 1) => {
            let index, timerIteration;
            if (items.length > 1) {
                let pivot = parseInt(items[Math.floor((right + left) / 2)].dataset.hsv, 10),
                    i = left,
                    j = right;
                const nextStep = () => {
                    if (left < index - 1) {
                        quickSort(scene, items, left, index - 1);
                    }
                    if (index < right) {
                        quickSort(scene, items, index, right);
                    }
                    clearTimeout(timerNextStep);
                    console.log('set event "sorted" with ' + (((new Date() - timestamp) / 1000) / 60) + 'minutes');
                    scene.dispatchEvent(this.eventSorted);
                };
                const iteration = () => {
                    if (shuffle) {
                        while ((Math.random() - 0.5) > 0) {
                            i++;
                            j--;
                        }
                    }
                    while (parseInt(items[i].dataset.hsv, 10) > pivot) {
                        i++;
                    }
                    while (parseInt(items[j].dataset.hsv, 10) < pivot) {
                        j--;
                    }
                    if (i <= j) {
                        if (i !== j) {
                            swap(scene, items, i, j);
                        }
                        i++;
                        j--;
                    }
                    if (i <= j) {
                        this.updateTimestamp((new Date() - timestamp) / 1000);
                        timerIteration = setTimeout(iteration, 100);
                    } else {
                        clearTimeout(timerIteration);
                        index = i;
                        this.updateTimestamp((new Date() - timestamp) / 1000);
                        timerNextStep = setTimeout(nextStep, 100);
                    }
                };
                if (i <= j) {
                    this.updateTimestamp((new Date() - timestamp) / 1000);
                    timerIteration = setTimeout(iteration, 100);
                }
            }
        };
        let timerNextStep;
        // first call
        quickSort(this.scene, colorBlocks);
    }
}