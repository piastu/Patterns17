import React from 'react';
import PropTypes from 'prop-types';
import ColorBlock from "./ColorBlock";

export default class TransparentBlock extends ColorBlock {

    render() {
        //Декорирование. Изменение цвета фона у блока.
        let gradient = 'linear-gradient(to top, rgba(' + this.props.color[0].slice(4, -1) + ', 1), rgba(' + this.props.color[0].slice(4, -1) + ', 0), rgba(' + this.props.color[0].slice(4, -1) + ', 1))',
            colorSet = [gradient,this.props.color[1]];
        // Вызов функции render() у экземпляра класса ColorBlock:
        return <ColorBlock color={colorSet} width={this.props.width} ref={(el) => this.block = el}/>;
    }
}

ColorBlock.propTypes = {
    color: PropTypes.array.isRequired,
    width: PropTypes.number.isRequired,
};