let queued_img_array = [];
const queue = document.querySelector(".queue");
const displayImages = document.querySelectorAll(".display-img .onclicks");

displayImages.forEach(image => {
    image.addEventListener("click", () => {
        addImageToQueue(image);
    });
});

function addImageToQueue(image) {
    const imgSrc = image.src;
    queued_img_array.push(imgSrc);
    displayQueuedImages();
}

function displayQueuedImages() {
    let images = "";
    queued_img_array.forEach((image, index) => {
        images += `<div class="image">
                    <img src="${image}" alt="image">
                    <span onclick="deleteQueuedImage(${index})">&times;</span>
                  </div>`;
    });
    queue.innerHTML = images;
}

function deleteQueuedImage(index) {
    queued_img_array.splice(index, 1);
    displayQueuedImages();
}

const queuedForm = document.querySelector(".queued-form");
queuedForm.addEventListener("submit", (event) => {
    event.preventDefault();
    console.log("Queued images:", queued_img_array);
    queued_img_array = [];
    displayQueuedImages();
});


function preview() {
    document.querySelector("#preview").style.display = "block";
}

function final() {
    document.querySelector("#final").style.display = "block";
}