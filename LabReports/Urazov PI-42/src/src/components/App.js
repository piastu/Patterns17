import React, { Component } from 'react';
import { Grid, Row, Col, FormGroup, Button, ButtonGroup } from 'react-bootstrap';
import BubbleSort from "../Sort/BubbleSort";
import ColorBlocks from "./Iterator/ColorBlocks";
import Shaker from "../Sort/Shaker";
import MergeSort from "../Sort/MergeSort";
import SceneComposite from "./Composite/SceneComposite";
import BridgeClient from "./Bridge/BridgeClient";
// eslint-disable-next-line
import Pool from "./Pool/Pool";
import Log from "./ChainOfResponsibility/Log";

export default class App extends Component {
    constructor(props) {
        super(props);
        // this.algorithm = null;
        // this._resetSortFunctions();
        // this._changeAlgorithm = this._changeAlgorithm.bind(this);
        // this._resetSortFunctions = this._resetSortFunctions.bind(this);

        this.scenes =
            <SceneComposite>
                <ColorBlocks colorsNumber={60} type={'transparent'}/>
                <ColorBlocks colorsNumber={60} type={'color'}/>
                <SceneComposite>
                    <SceneComposite>
                        <SceneComposite>
                            <SceneComposite>
                                <SceneComposite>
                                    <ColorBlocks colorsNumber={360} type={'color'}/>
                                </SceneComposite>
                            </SceneComposite>
                        </SceneComposite>
                    </SceneComposite>
                </SceneComposite>
            </SceneComposite>;
        // console.log(this.scenes);
    }

    sort = () => {
        console.log(this.scene);
        this.scene.childNodes.forEach((curr) => {
            switch (curr.querySelector('.sorts').value) {
                case 'bubble':
                    (new BubbleSort(curr.querySelector('.col-xs-12>div'))).doSort();
                    break;
                case 'shaker':
                    (new Shaker(curr.querySelector('.col-xs-12>div'))).doSort();
                    break;
                case 'merge':
                    console.log(curr.querySelector('.col-xs-12>div'));
                    (new MergeSort(curr.querySelector('.col-xs-12>div'))).doSort();
                    break;
                default:
                    console.log(curr.querySelector('.sorts').value);
            }
        });
    };

    reverse = () => {
        this.scene.childNodes.forEach((curr) => {
            switch (curr.querySelector('.sorts').value) {
                case 'bubble':
                    (new BubbleSort(curr.querySelector('.col-xs-12>div'))).doReverse();
                    break;
                case 'shaker':
                    (new Shaker(curr.querySelector('.col-xs-12>div'))).doReverse();
                    break;
                case 'merge':
                    (new MergeSort(curr.querySelector('.col-xs-12>div'))).doReverse();
                    break;
                default:
                    console.log(curr.querySelector('.sorts').value);
            }
        });
    };

    shuffle = () => {
        this.scene.childNodes.forEach((curr) => {
            switch (curr.querySelector('.sorts').value) {
                case 'bubble':
                    (new BubbleSort(curr.querySelector('.col-xs-12>div'))).doShuffle();
                    break;
                case 'shaker':
                    (new Shaker(curr.querySelector('.col-xs-12>div'))).doShuffle();
                    break;
                case 'merge':
                    (new MergeSort(curr.querySelector('.col-xs-12>div'))).doShuffle();
                    break;
                default:
                    console.log(curr.querySelector('.sorts').value);
            }
        });
    };

    // _resetSortFunctions = () => {
    //     this.sort = () => {
    //         alert('Выберите алгоритм сортировки!');
    //     };
    //     this.reverse = () => {
    //         alert('Выберите алгоритм обратной сортировки!');
    //     };
    //     this.shuffle = () => {
    //         alert('Выберите алгоритм смешивания!');
    //     };
    // };

    // _changeAlgorithm = (e) => {
    //     console.log(e.target.value);
    //     this.selectAlg.className += 'disabled';
    //     this.btnSort.className += 'disabled';
    //     this.btnShuffle.className += 'disabled';
    //     switch (e.target.value) {
    //         case 'bubble':
    //             this.algorithm = new BubbleSort(this.scene);
    //             break;
    //         case 'shaker':
    //             this.algorithm = new Shaker(this.scene);
    //             break;
    //         case 'merge':
    //             this.algorithm = new MergeSort(this.scene);
    //             break;
    //         default:
    //             this.algorithm = null;
    //             this._resetSortFunctions();
    //     }
    //     if (this.algorithm !== null) {
    //         this.sort = this.algorithm.doSort;
    //         this.shuffle = this.algorithm.doShuffle;
    //         this.reverse = this.algorithm.doReverse;
    //     }
    // };

    // _onSorted = () => {
    //     console.log('event "sorted" did handled');
    // };

    componentDidMount() {
        //Снежинки - пул-синглтон
        // setTimeout(() => {
        //     (new Pool()).letItSnow();
        // }, 500);
        // setTimeout(() => {
        //     (new Pool()).letItSnow();
        // }, 3500);

        //Первая часть "наблюдателя"
        let buttons = document.body.querySelectorAll('.btn');
        buttons.forEach((curr) => {
            curr.addEventListener('click', () => {
                document.body.dispatchEvent(new Event('startAlgorithm', { bubbles: true, cancelable: true }));
            });
        });
        //Вторая часть "наблюдателя". Все кнопки изменятся, когда начнётся сортировка
        document.body.addEventListener('startAlgorithm', () => {
            buttons.forEach((curr) => {
                curr.classList.add('disabled');
            });
        });
        //Продолжение второй части "наблюдателя". Все кнопки вернуться в исходное состояние, когда закончится сортировка
        document.body.addEventListener('sorted', () => {
            console.log('event "sorted" did handled');
            buttons.forEach((curr) => {
                curr.classList.remove('disabled');
            });
        });

        //Chain of responsibility - Client
        Log.log("It's default message");
        Log.log("It's Info message", 'Info');
        Log.log("It's Warning message", 'Warning');
        Log.log("It's Error message", 'Error');
    }

    render() {
        //Iterator - Client
        this.clrBlocks = [];
        // console.log((new ColorBlocks()));
        // console.log(<ColorBlocks/>);
        for (let block of (new ColorBlocks()).iterator) {
            this.clrBlocks.push(block);
        }

        return (
            <div>
                <BridgeClient scene={this.clrBlocks}/>
                <Grid fluid={true}>
                    <Row>
                        <Col xs={12}>
                            <FormGroup>
                                <ButtonGroup>
                                    <Button bsStyle={'success'} onClick={() => this.sort()}>Sort</Button>
                                    <Button bsStyle={'danger'} onClick={() => this.reverse()}>Reverse</Button>
                                    <Button bsStyle={'primary'} onClick={() => this.shuffle()}>Shuffle</Button>
                                </ButtonGroup>
                            </FormGroup>
                        </Col>
                    </Row>
                    <Row>
                        <Col xs={12}>
                            <div ref={(element) => this.scene = element}>
                                {this.scenes}
                            </div>
                        </Col>
                    </Row>
                </Grid>
            </div>
        );
    }
}

// const styles = {
//     scene: {
//         display: 'inline-block',
//         border: '1px solid black',
//         height: '300px',
//     },
// };