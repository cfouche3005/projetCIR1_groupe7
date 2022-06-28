import jsonData from "./planet.json";
import {CreateSelect} from "../page/page.js";

const TrajectData = jsonData

let PlanetParams = {}

for (const prop in TrajectData){
    let defaultcolor = "#"+Math.floor(Math.random()*16777215).toString(16);
    CreateSelect(prop,"select",defaultcolor);
    PlanetParams[`${prop}check`] = {visible: true};
    PlanetParams[`${prop}color`]= {color :defaultcolor};
}

export {PlanetParams}
export {jsonData,TrajectData}

