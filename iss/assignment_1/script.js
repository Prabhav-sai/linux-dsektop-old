let mouseX = 0;
let mouseY = 0;
let light = document.getElementById("light");

//Detect touch device
const isTouchDevice = () => {
  try {
    //We try to create TouchEvent(it would fail for desktops and throw error)
    document.createEvent("TouchEvent");
    return true;
  } catch (e) {
    return false;
  }
};

function getMousePosition(e) {
  mouseX = !isTouchDevice() ? e.pageX : e.touches[0].pageX;
  mouseY = !isTouchDevice() ? e.pageY : e.touches[0].pageY;

  light.style.setProperty("--x", mouseX + "px");
  light.style.setProperty("--y", mouseY + "px");
}

document.addEventListener("mousemove", getMousePosition);
document.addEventListener("touchmove", getMousePosition);
// document.addEventListener("scroll", getMousePosition);

// var moon = document.getElementById("moon") ;
function toggle(){
  // alert(check);
  document.body.classList.toggle("darktheme");
  if(document.body.classList.contains("darktheme")){
    document.getElementById("moon").src="moon.png";
  }
  else{
    document.getElementById("moon").src="sun.png";
  }
}
