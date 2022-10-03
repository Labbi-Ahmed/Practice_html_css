
document.getElementById("removbtn").addEventListener('click', () => {
    document.getElementById("remov").style.display="none";
})
document.getElementById("hidebtn").addEventListener('click', () => {
   document.getElementById("hide").style.visibility="hidden";
})


document.getElementById("resetbtn").addEventListener('click', () => {
     document.getElementById("remov").style.display="block";
    document.getElementById("hide").style.visibility="visible";
})

