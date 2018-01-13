export default class Bubble {
    constructor(scene, eventSorted, updateProgress, updateTimestamp) {
        this.scene = scene;
        this.eventSorted = eventSorted;
        this.updateProgress = updateProgress;
        this.updateTimestamp = updateTimestamp;

    }

    doSort = (shuffle = false) => {
        const timestamp = new Date();
        let colorBlocks = this.scene.childNodes,
            i = 0, j = 0;
        const iteration = () => {
            let color1 = parseInt(colorBlocks[j].dataset.hsv, 10),
                color2 = parseInt(colorBlocks[j + 1].dataset.hsv, 10),
                condition = shuffle ? (Math.random() - 0.5) > 0 : color1 > color2;
            if (condition) {
                this.scene.insertBefore(colorBlocks[j + 1], colorBlocks[j]);
            }
            if (j < colorBlocks.length - 2 - i) {
                j++;
                timerID = setTimeout(iteration, 1, shuffle);
            } else {
                if (i < colorBlocks.length - 2) {
                    i++;
                    j = 0;
                    this.updateProgress(((100 / (colorBlocks.length - 2)) * i).toFixed(2) + '%');
                    this.updateTimestamp((new Date() - timestamp) / 1000);
                    timerID = setTimeout(iteration, 1, shuffle);
                } else {
                    clearTimeout(timerID);
                    console.log('set event "sorted" with ' + (((new Date() - timestamp) / 1000) / 60) + 'minutes');
                    this.scene.dispatchEvent(this.eventSorted);
                    this.updateProgress('Complete!');
                }
            }
        };
        let timerID = setTimeout(iteration, 1, shuffle);
    };

    shuffle = () => this.doSort(true);
}

// Bubble.propTypes = {
//     scene: PropTypes.element.isRequired,
//     eventSorted: PropTypes.shape({
//         isTrusted: PropTypes.bool.isRequired,
//         bubbles: PropTypes.bool.isRequired,
//         cancelBubble: PropTypes.bool.isRequired,
//         cancelable: PropTypes.bool.isRequired,
//         composed: PropTypes.bool.isRequired,
//         currentTarget: PropTypes.bool.isRequired,
//         defaultPrevented: PropTypes.bool.isRequired,
//         eventPhase: PropTypes.number.isRequired,
//         returnValue: PropTypes.bool.isRequired,
//         timeStamp: PropTypes.number.isRequired,
//         type: PropTypes.string.isRequired,
//     }),
//     updateProgress: PropTypes.func.isRequired,
//     updateTimestamp: PropTypes.func.isRequired,
// };