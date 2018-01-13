export default class Snowflake {
    constructor(params = {}) {
        this.htmlNode = document.createElement('div');
        this.htmlNode.style.backgroundImage = 'url("/snowflake.png")';
        this.htmlNode.style.backgroundSize = 'contain';
        this.htmlNode.style.width = params.width || '30px';
        this.htmlNode.style.height = params.height || '30px';
        this.htmlNode.style.display = 'block';
        this.htmlNode.style.position = 'absolute';
        this.htmlNode.style.top = '0px';
        this.htmlNode.style.left = rand(0, document.documentElement.clientWidth - (params.width || 30)) + 'px';
        console.log('Snowflake did created');
    }
}

const rand = (min = 0, max = 1) => {
    return min + Math.random() * (max - min);
};