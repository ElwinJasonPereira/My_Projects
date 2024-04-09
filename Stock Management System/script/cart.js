let container = document.getElementById('container');
let parent = document.getElementById('left_view_cart');
console.log(parent);

function showProduct(){
    
        container.innerHTML = null
        container.style.flexDirection = 'column';

        let h1 = document.createElement('h1');
        h1.id = 'heading';
        h1.textContent = 'Uh-oh! Your Cart is Empty'


        let img = document.createElement('img');
        img.src = '//assets-netstorage.groww.in/web-assets/billion_groww_desktop/prod/build/client/images/cart-empty.5f55a0d3.svg';
         
        let btnFund = document.createElement('button');
        btnFund.id = 'explore_fund';

        
        btnFund.innerHTML = `Explore Funds`
        btnFund.onclick = () => {
         window.location.href ='../html/home.html';
        }

        container.append(h1,img,btnFund);

}


showProduct();
