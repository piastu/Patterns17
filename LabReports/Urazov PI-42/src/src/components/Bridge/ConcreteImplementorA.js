// ConcreteImplementorA (реализация Implementor)
import IImplementor from "./IImplementor";

export default class ConcreteImplementorA extends IImplementor {
    swap(array, firstIndex) {
        this.scene.insertBefore(array[firstIndex + 1], array[firstIndex]);
    }
}