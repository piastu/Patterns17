import React, { Component } from 'react';
import PropTypes from 'prop-types';

export default class ColorBlock extends Component {

    render() {
        let block;
        block = <div
            style={{
                display: 'inline-block',
                width: this.props.width,
                height: '100%',
                background: this.props.color[0],
            }}
            // eslint-disable-next-line
            data-hsv={String(this.props.color[1] + ', 100' + ', 100')}
        />;
        return block;
    }
}

ColorBlock.propTypes = {
    color: PropTypes.array.isRequired,
    width: PropTypes.number.isRequired
};