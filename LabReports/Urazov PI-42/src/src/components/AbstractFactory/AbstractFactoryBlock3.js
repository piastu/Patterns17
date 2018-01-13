import React from "react";
import IAbstractFactoryBlock from "./IAbstractFactoryBlock";
import ColorBlock from "../ColorBlock";
import TransparentBlock from "../TransparentBlock";

export default class AbstractFactoryBlock3 extends IAbstractFactoryBlock {
    createColorBlock(colorRGB, colorH) {
        return <ColorBlock color={[colorRGB,colorH]} width={3}/>
        // return <div
        //     style={{
        //         display: 'inline-block',
        //         width: 3,
        //         height: '100%',
        //         backgroundColor: colorRGB,
        //     }}
        //     // eslint-disable-next-line
        //     data-hsv={String(colorH + ', 100' + ', 100')}
        // />;
    }

    createGradientToTransparentBlock(colorRGB, colorH) {
        return <TransparentBlock  color={[colorRGB,colorH]} width={3}/>;
        // return <div
        //     style={{
        //         display: 'inline-block',
        //         width: 3,
        //         height: '100%',
        //         backgroundColor: 'linear-gradient(to top , rgba(' + colorRGB.slice(4, -1) + ', 1), rgba(' + colorRGB.slice(4, -1) + ', 0))',
        //     }}
        //     // eslint-disable-next-line
        //     data-hsv={String(colorH + ', 100' + ', 100')}
        // />;
    }
}