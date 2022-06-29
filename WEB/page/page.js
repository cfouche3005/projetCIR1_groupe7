function CreateSelect(Name,element,defaultcolor){
    const select = document.getElementById(element);
    // Balise représentant un bouton sélecteur
    let html = `<label for="${Name}check"><div class="planetname" id="${Name}" >
                    <input type="checkbox" checked="checked" class="checkbox check" id="${Name}check" name="${Name}check"/>
                    ${Name} 
                    <input type="color" class="colorselect" value="${defaultcolor}" id="${Name}color" name="${Name}color"/>
                <div/><label/>`
    select.insertAdjacentHTML("beforeend", html);
}

export {CreateSelect}