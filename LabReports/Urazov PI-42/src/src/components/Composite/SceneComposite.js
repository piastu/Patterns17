import React from 'react';
import PropTypes from 'prop-types';
import ISceneComponent from "./ISceneComponent";
import ColorBlocks from "../Iterator/ColorBlocks";

export default class SceneComposite extends ISceneComponent {
    constructor(props) {
        super(props);
        this.content = [(this.props.children || <ColorBlocks colorsNumber={this.props.colorsNumber} type={this.props.type}/>)];
    }

    getChildNodes() {
        return this.content;
    }

    add(Node) {
        if (typeof Node.length === 'undefined') {
            this.content.push(Node);
        } else {
            this.content.push(...Node);
        }
    }

    render() {
        return this.content;
    }
}

SceneComposite.propTypes = {
    colorsNumber: PropTypes.number,
    type: PropTypes.oneOf(['color', 'transparent']),
};