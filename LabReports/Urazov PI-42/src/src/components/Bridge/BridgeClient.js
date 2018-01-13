import React, { Component } from "react";
import PropTypes from 'prop-types';
import Abstraction from "./Abstraction";
import ConcreteImplementorA from "./ConcreteImplementorA";
import ConcreteImplementorB from "./ConcreteImplementorB";
import { Grid, Row, Col, FormGroup, Button, ButtonGroup } from 'react-bootstrap';

export default class BridgeClient extends Component {
    constructor(props) {
        super(props);
        this.abstr = new Abstraction();
        this.withoutConsole = this.withoutConsole.bind(this);
        this.withConsole = this.withConsole.bind(this);
    }

    withoutConsole() {
        this.abstr.setImplementor(new ConcreteImplementorA(this.scene));
        this.abstr.doSort(); // "ConcreteImplementorA.operation"
    }

    withConsole() {
        this.abstr.setImplementor(new ConcreteImplementorB(this.scene));
        this.abstr.doReverse(); // "ConcreteImplementorB.operation"
    }

    render() {
        return (
            <Grid fluid={true} style={{ marginBottom: '30px' }}>
                <Row>
                    <Col xs={12} style={{ marginLeft: '15px' }}>
                        <FormGroup>
                            <ButtonGroup>
                                <Button bsStyle={'success'} onClick={() => this.withoutConsole()}>Bubble Sort withoutConsole</Button>
                                <Button bsStyle={'danger'} onClick={() => this.withConsole()}>Bubble Reverse withConsole</Button>
                            </ButtonGroup>
                        </FormGroup>
                    </Col>
                </Row>
                <Row>
                    <Col xs={12}>
                        <div style={{height: '50px'}} ref={(element) => this.scene = element}>
                            {this.props.scene}
                        </div>
                    </Col>
                </Row>
            </Grid>

        );
    }
}

BridgeClient.propTypes = {
    scene: PropTypes.any.isRequired,
};