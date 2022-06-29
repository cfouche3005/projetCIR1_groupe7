import {PlanetParams} from "../data/extractData.js";
let time = 0;
let TrajPlanet = 0;

const OgScale =0.90
let Scale = 0
const OgScaling = 1e+13
let Scaling = OgScaling*(1-OgScale)
const OgSunRadius = 20
let SunRadius =OgSunRadius*OgScale
const OgPlanetRadius =5
let PlanetRadius =OgPlanetRadius*OgScale


function DrawInit(TrajectData){
    time = 0
    TrajPlanet = TrajectData
    console.log(TrajPlanet)
    for (const Name in TrajPlanet){

        const checkbox = document.getElementById(`${Name}check`);
        checkbox.addEventListener("change",function(e) {
            PlanetParams[e.target.id].visible = e.target.checked;
        })

        const colorselect = document.getElementById(`${Name}color`);
        colorselect.addEventListener("input", function(e) {
        PlanetParams[`${Name}color`].color = e.target.value;
        })
    }

    const range = document.getElementById("scale");
    range.addEventListener("input", function(e){
        Scale = e.target.value/100;
        if(Scale<=0.5){
            SunRadius = OgSunRadius*Scale
            PlanetRadius = OgPlanetRadius*(1-Scale)
        }else{
            SunRadius = OgSunRadius*Scale
            PlanetRadius = OgPlanetRadius*Scale
        }
        Scaling = OgScaling*(1-Scale)
    })
    DrawAll();

}

function DrawAll() {
    const canvas = document.getElementById("solar");
    const context = canvas.getContext("2d");
    context.save()
    time ++;
    ClearAll(context,canvas);
    context.translate(canvas.height / 2,canvas.height / 2)
    context.scale(1,-1)
    drawTrajectory(context,TrajPlanet,canvas);
    DrawnPlanet(context, TrajPlanet,canvas,PlanetRadius,time);
    DrawnSun(context,SunRadius);
    context.restore();
    requestAnimationFrame(DrawAll)
}

function drawTrajectory(context,TrajPlanet,canvas) {
    for (const Name in TrajPlanet){
        if (PlanetParams[`${Name}check`].visible === true){
            context.save()
            context.beginPath();
            context.strokeStyle = "white";
            context.moveTo((TrajPlanet[Name][0][0][0] / Scaling) * canvas.height, (TrajPlanet[Name][0][0][1] / Scaling) * canvas.height);
            for (let i = 0; i <= time; i++) {
                let cord = TrajPlanet[Name][i][0];
                context.lineTo((cord[0] / Scaling) * canvas.height, (cord[1] / Scaling) * canvas.height);
            }
            context.stroke();
            context.restore();
        }
    }
}

function DrawnSun(context,SunRadius){
    context.save()
    context.strokeStyle = "black";
    context.fillStyle = "yellow";
    context.beginPath();
    context.arc(0, 0, SunRadius, 0, Math.PI*2);
    context.stroke();
    context.fill();
    context.restore();
}

function DrawnPlanet(context,TrajPlanet,canvas,PlanetRadius,time){
    for (const Name in TrajPlanet){
        if(PlanetParams[`${Name}check`].visible === true){
            context.save()
            context.strokeStyle = "black";
            context.fillStyle = PlanetParams[`${Name}color`].color;
            context.beginPath()
            context.arc(((TrajPlanet[Name][time][0][0] / Scaling) * canvas.height), ((TrajPlanet[Name][time][0][1] / Scaling) * canvas.height), PlanetRadius, 0, Math.PI * 2)
            context.stroke();
            context.fill();
            context.restore();
        }
    }
}

function ClearAll(context,canvas) {
    context.save()
    context.beginPath()
    context.clearRect(0,0,canvas.width,canvas.height);
    context.closePath();
    context.restore();

}

export {DrawInit}