import AbstractFactoryBlock18 from "../AbstractFactory/AbstractFactoryBlock18";
import AbstractFactoryBlock3 from "../AbstractFactory/AbstractFactoryBlock3";

export default class FactoryMethodScene {
    getColorBlocks(colorsNumber = 360, type = 'color') {
        function getColorSet(colorsNumber = 360) {
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
        }

        let colors = getColorSet(colorsNumber),
            colorBlocks = [],
            fact18 = new AbstractFactoryBlock18(),
            fact3 = new AbstractFactoryBlock3();
        let colorsNumberAndType = colorsNumber + type;
        switch (colorsNumberAndType) {
            case '60color':
                for (let i = 0; i < 60; i++) {
                    colorBlocks.push(fact18.createColorBlock(colors[i][0], colors[i][1]));
                }
                break;
            case '60transparent':
                for (let i = 0; i < 60; i++) {
                    colorBlocks.push(fact18.createGradientToTransparentBlock(colors[i][0], colors[i][1]));
                }
                break;
            case '360transparent':
                for (let i = 0; i < 360; i++) {
                    colorBlocks.push(fact3.createColorBlock(colors[i][0], colors[i][1]));
                }
                break;
            case '360color':
            default:
                for (let i = 0; i < 360; i++) {
                    colorBlocks.push(fact3.createColorBlock(colors[i][0], colors[i][1]));
                }
                break;
        }
        return colorBlocks;
    };
}