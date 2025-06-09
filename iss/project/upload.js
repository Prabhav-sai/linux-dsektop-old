let queued_img_array = [];
queuedform = document.querySelector(".queued-form");
queue = document.querySelector(".queue");
input = document.querySelector(".input-box input");
inputbox = document.querySelector(".input-box");

input.addEventListener("change", () =>{
    const files = input.files
    for(let i=0;i<files.length;i++){
        queued_img_array.push(files[i])
    }
    queuedform.reset()
    displayQueuedImages()
})

inputbox.addEventListener("dragover",(e)=>{
    e.preventDefault()
})

inputbox.addEventListener("drop",(e)=>{
    e.preventDefault()
    const files = e.dataTransfer.files
    for(let i=0;i<files.length;i++){
        if(!files[i].type.match("image")) continue

        if(queued_img_array.every(image => image.name !== files[i].name))
        queued_img_array.push(files[i])
    }
    displayQueuedImages()
})

function displayQueuedImages(){
    let images = ""
    queued_img_array.forEach((image,index) => {
        images+= `<div class="image">
                    <img src="${URL.createObjectURL(image)}" alt="image">
                    <span onclick="deleteQueuedImage(${index})">&times;</span>
                  </div>`
    })
    queue.innerHTML = images
}

function deleteQueuedImage(index){
    queued_img_array.splice(index,1)
    displayQueuedImages()
}
