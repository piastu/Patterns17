import React, { Component } from 'react';
import ColorBlocks from "../components/ColorBlocks";
import Bubble from "./Bubble";
import Quick from "../Sort/Quick";

// App_old.js
export default class App extends Component {
    constructor(props) {
        super(props);
        this.selectedSort = null;
        this.selectedShuffle = null;
        this.eventSorted = new Event('sorted', { bubbles: true, cancelable: true });
        this.state = {
            sortType: ' ',
            shuffleType: '',
            progress: 0,
            timestamp: 0,
        };
    }

    _setProgress = (value) => {
        this.setState({
            progress: value
        });
    };

    _setTimestamp = (value) => {
        this.setState({
            timestamp: value
        });
    };

    _changeSort = (e) => {
        console.log(e.target.value);
        this.setState({ sortType: e.target.value });
        this.selectShuffle.setAttribute('disabled', 'true');
        this.selectSort.setAttribute('disabled', 'true');
        //так как setState выполняется не сразу, делаем свич по e.target.value
        switch (e.target.value) {
            case 'bubble':
                this.selectedSort = new Bubble(this.scene, this.eventSorted, this._setProgress, this._setTimestamp);
                this.selectedSort.doSort();
                break;
            case 'quick':
                this.selectedSort = new Quick(this.scene, this.eventSorted, this._setProgress, this._setTimestamp);
                console.log(this.selectedSort.doSort());
                break;
            default:
                this.selectedSort = null;
                this.scene.dispatchEvent(this.eventSorted);
        }
    };

    _changeShuffle = (e) => {
        console.log(e.target.value);
        this.setState({ shuffleType: e.target.value });
        this.selectShuffle.setAttribute('disabled', 'true');
        this.selectSort.setAttribute('disabled', 'true');
        //так как setState выполняется не сразу, делаем свич по e.target.value
        switch (e.target.value) {
            case 'bubble':
                this.selectedShuffle = new Bubble(this.scene, this.eventSorted, this._setProgress, this._setTimestamp);
                this.selectedShuffle.doSort(true);
                break;
            case 'quick':
                this.selectedSort = new Quick(this.scene, this.eventSorted, this._setProgress, this._setTimestamp);
                console.log(this.selectedSort.doSort(true));
                break;
            default:
                this.selectedShuffle = null;
                this.scene.dispatchEvent(this.eventSorted);
        }
    };

    _onSorted = (e) => {
        this.selectSort.removeAttribute('disabled');
        this.selectShuffle.removeAttribute('disabled');
        console.log('event "sorted" did handled');
    };

    componentDidMount() {
        this._refContainer.addEventListener('sorted', this._onSorted);

        function foo(items, accessToItem) {
            for (let index = 0; index < items.length; index++) {
                let current = eval(accessToItem);
                debugger;
                console.log(current);
            }
        }

        let blocks = (new ColorBlocks(6))._getColorBlocks();
        console.log('я тут');
        debugger;
        foo(blocks, 'parseInt(arguments[0][index].dataset.hsv, 10)');
    }

    render() {
        return (
            <div style={{ ...styles.flexContainer, ...styles.flexDirCol }} ref={(element) => this._refContainer = element}>
                <div style={{ ...styles.flexContainer, ...styles.flexDirRow }}>
                    <div style={{ flex: 1 }}>
                        <select name="sorts" id="sorts" defaultValue={'null'} onChange={this._changeSort} ref={(element) => this.selectSort = element}>
                            <option value="null">Выбрать метод сортировки</option>
                            <option value="bubble">Пузырёк</option>
                            <option value="shaker">Шейкер</option>
                            <option value="quick">Быстрая</option>
                            <option value="insert">Вставками</option>
                            <option value="gravity">Гравитационая</option>
                        </select>
                    </div>
                    <div style={{ flex: 2 }}>
                        <select name="shuffles" id="shuffles" defaultValue={'null'} onChange={this._changeShuffle} ref={(element) => this.selectShuffle = element}>
                            <option value="null">Выбрать метод смешивания</option>
                            <option value="bubble">Пузырёк</option>
                            <option value="shaker">Шейкер</option>
                            <option value="quick">Быстрая</option>
                            <option value="insert">Вставками</option>
                            <option value="gravity">Гравитационая</option>
                        </select>
                    </div>
                </div>
                <div>
                    <h2 style={{ marginTop: 200, height: 24 }}>{(this.state.sortType !== 'null') ? this.state.sortType : ''}</h2>
                    <h3>Progress: {this.state.progress}</h3>
                    <h3>Time: {this.state.timestamp}s</h3>
                    <div ref={(element) => this.scene = element} style={styles.scene}>
                        <ColorBlocks colorsNumber={60}/>
                    </div>
                </div>
            </div>
        );
    }
}

const styles = {
    scene: {
        display: 'inline-block',
        border: '1px solid black',
        height: '300px',
    },
    flexContainer: {
        display: 'flex',
    },
    inlineFlex: {
        display: 'inline-flex'
    },
    flexItem: {
        textAlign: 'center',
        fontSize: '1.1em',
        padding: '1.5em',
    },
    flexDirRow: {
        flexDirection: 'row',
    },
    flexDirCol: {
        flexDirection: 'column',
    },
};