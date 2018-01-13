// ConcreteImplementorB (реализация Implementor)
import IImplementor from "./IImplementor";

export default class ConcreteImplementorB extends IImplementor {
    ColorBlocksToNumericArray(ColorBlocks) {
        let numericArray = [];
        ColorBlocks.forEach((curr) => {
            numericArray.push(parseInt(curr.dataset.hsv, 10))
        });
        return numericArray;
    }
    swap(array, firstIndex) {
        let numericArray = this.ColorBlocksToNumericArray(array);

        let tmp = numericArray[firstIndex];
        numericArray[firstIndex] = numericArray[firstIndex + 1];
        numericArray[firstIndex + 1] = tmp;
        console.log(numericArray);
    }
    finish(array) {
        console.clear();
        console.log(this.ColorBlocksToNumericArray(array));
    }
}