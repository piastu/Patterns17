import React from 'react';
import PropTypes from 'prop-types';
import ColorBlock from "../ColorBlock";
import TransparentBlock from "../TransparentBlock";
import ISceneComponent from "../Composite/ISceneComponent";

export default class ColorBlocks extends ISceneComponent {
    constructor(props) {
        super(props);
        this.colors = this._getColorSet(this.props ? this.props.colorsNumber || 60 : 60);
        this.blocks = this._getColorBlocks();
        this.iterator = {
            blocks: this.blocks,
            from: 0,
            to: this.blocks.length - 1,
        };
        this.iterator[Symbol.iterator] = function () {
            let items = this.blocks,
                currIdx = this.from,
                lastIdx = this.to;
            return {
                next() {
                    if (currIdx <= lastIdx) {
                        return {
                            done: false,
                            value: items[currIdx++],
                        }
                    } else {
                        return {
                            done: true
                        }
                    }
                }
            }
        };
    }

    _getColorSet = (colorsNumber = 360) => {
        colorsNumber = (colorsNumber > 360) ? 360 : colorsNumber;
        let colors = [],
            H = 0,
            inc = Math.round(360 / colorsNumber);
        for (; H < 60; H += inc) {
            let _r = 100,
                _g = 100 * ((H % 60) / 60),
                _b = 0;
            let r = Math.round(_r * (255 / 100)),
                g = Math.round(_g * (255 / 100)),
                b = Math.round(_b * (255 / 100));
            colors.push(['rgb(' + r + ', ' + g + ', ' + b + ')', H]);
        }
        for (; H < 120; H += inc) {
            let _r = 100 - (100 * ((H % 60) / 60)),
                _g = 100,
                _b = 0;
            let r = Math.round(_r * (255 / 100)),
                g = Math.round(_g * (255 / 100)),
                b = Math.round(_b * (255 / 100));
            colors.push(['rgb(' + r + ', ' + g + ', ' + b + ')', H]);
        }
        for (; H < 180; H += inc) {
            let _r = 0,
                _g = 100,
                _b = 100 * (H % 60) / 60;
            let r = Math.round(_r * (255 / 100)),
                g = Math.round(_g * (255 / 100)),
                b = Math.round(_b * (255 / 100));
            colors.push(['rgb(' + r + ', ' + g + ', ' + b + ')', H]);
        }
        for (; H < 240; H += inc) {
            let _r = 0,
                _g = 100 - (100 * ((H % 60) / 60)),
                _b = 100;
            let r = Math.round(_r * (255 / 100)),
                g = Math.round(_g * (255 / 100)),
                b = Math.round(_b * (255 / 100));
            colors.push(['rgb(' + r + ', ' + g + ', ' + b + ')', H]);
        }
        for (; H < 300; H += inc) {
            let _r = 100 * ((H % 60) / 60),
                _g = 0,
                _b = 100;
            let r = Math.round(_r * (255 / 100)),
                g = Math.round(_g * (255 / 100)),
                b = Math.round(_b * (255 / 100));
            colors.push(['rgb(' + r + ', ' + g + ', ' + b + ')', H]);
        }
        for (; H < 360; H += inc) {
            let _r = 100,
                _g = 0,
                _b = 100 - (100 * ((H % 60) / 60));
            let r = Math.round(_r * (255 / 100)),
                g = Math.round(_g * (255 / 100)),
                b = Math.round(_b * (255 / 100));
            colors.push(['rgb(' + r + ', ' + g + ', ' + b + ')', H]);
        }
        return colors;
    };

    _getColorBlocks = () => {
        let colors = this.colors,
            colorBlocks = [];
        if (this.props ? this.props.type === 'transparent' : false) {
            for (let i = 0; i < colors.length; i++) {
                colorBlocks.push(<TransparentBlock key={i} color={colors[i]} width={Math.round(360 / colors.length) * 3}/>);
            }
        } else {
            for (let i = 0; i < colors.length; i++) {
                colorBlocks.push(<ColorBlock key={i} color={colors[i]} width={Math.round(360 / colors.length) * 3}/>);
            }
        }
        return colorBlocks;
    };

    getChildNodes() {
        return undefined;
    }

    add() {
        "";
    }

    render() {
        return super.render(this.blocks);
    }
}

// ColorBlocks[Symbol.iterator] = function () {
//     let items = this.blocks,
//         currIdx = 0,
//         lastIdx = items.length - 1;
//     return {
//         next() {
//             if (currIdx <= lastIdx) {
//                 return {
//                     done: false,
//                     value: items[currIdx++],
//                 }
//             } else {
//                 return {
//                     done: true
//                 }
//             }
//         }
//     }
// };

ColorBlocks.propTypes = {
    colorsNumber: PropTypes.number,
    type: PropTypes.oneOf(['color', 'transparent']),
};
