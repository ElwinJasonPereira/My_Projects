let check = JSON.parse(localStorage.getItem('login'));
let user = document.getElementById("user");
let logout = document.getElementByIdClassName('logout');
let count = 0;
user.onclick = () => {
    if(count == 0){
        logout.setAttribute("class", "displayDropDown");
        logout.onclick = () => {
            alert("logout")
            logout.setAttribute("class", "noDropDownDisplay");
            // location.reload();
            window.location.href='.html';
        }
        count++;
    }
    else if(count == 1){
        logout.setAttribute("class", "noDropDownDisplay");
        count = 0;
    }
}

