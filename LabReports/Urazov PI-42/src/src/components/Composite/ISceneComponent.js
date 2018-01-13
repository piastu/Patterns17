import React, { Component } from 'react';
import PropTypes from 'prop-types';
import { Grid, Row, Col, FormGroup, FormControl, ControlLabel, Form } from 'react-bootstrap';

export default class ISceneComponent extends Component {
    // constructor(props) {
    //     super(props);
    //     this.algorithm = null;
    //     this._resetSortFunctions();
    //     this._changeAlgorithm = this._changeAlgorithm.bind(this);
    //     this._resetSortFunctions = this._resetSortFunctions.bind(this);
    //     console.log('ISceneComponent: constructor: this.scene ' + this.scene);
    // }

    // _resetSortFunctions = () => {
    //     this.sort = () => {
    //         alert('Выберите алгоритм сортировки!');
    //     };
    //     this.shuffle = () => {
    //         alert('Выберите алгоритм смешивания!');
    //     };
    //     this.reverse = () => {
    //         alert('Выберите алгоритм смешивания!');
    //     };
    // };

    // _changeAlgorithm = (e) => {
    //     console.log(e.target.value);
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

    getChildNodes() {
    }

    add(CompositeOrScene) {
    }

    render(content) {
        return (
            <Grid>
                <Row>
                    <Col xs={12}>
                        <Form inline={true}>
                            <FormGroup>
                                <ControlLabel>Выбор алгоритма</ControlLabel>
                                <FormControl
                                    componentClass="select"
                                    placeholder={"Выбор алгоритма"}
                                    name="sorts"
                                    className="sorts"
                                    defaultValue={'null'}
                                    // onChange={this._changeAlgorithm}
                                    // ref={(el) => this.selectAlg = el}
                                    style={{ margin: '10px' }}
                                >
                                    <option value="null" disabled={true}>Выбрать алгоритм</option>
                                    <option value="bubble">Пузырёк</option>
                                    <option value="shaker">Шейкер</option>
                                    <option value="merge">Слиянием (base 2)</option>
                                </FormControl>
                            </FormGroup>
                        </Form>
                    </Col>
                </Row>
                <Row>
                    <Col xs={12}>
                        <div
                            // ref={(element) => this.scene = element}
                            style={styles.scene}
                        >
                            {content}
                        </div>
                    </Col>
                </Row>
            </Grid>
        );
    }
}

ISceneComponent.propTypes = {
    colorsNumber: PropTypes.number,
    type: PropTypes.oneOf(['color', 'transparent']),
};

const styles = {
    scene: {
        display: 'inline-block',
        border: '1px solid black',
        height: '300px',
    },
};