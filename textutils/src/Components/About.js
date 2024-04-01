import React from 'react'
import './Navbar.css';

export default function About(props) {
    // const [mystyle , setmystyle] = useState({
    //     color : 'white',
    //     backgroundColor : '#232d32'
    // });

    // const [btnstyle , setbtnstyle] = useState({
    //     color : '#232d32',
    //     backgroundColor : 'white',
    //     border : '1px solid #232d32'
    // });

    // const [btntext , setbtntext] = useState("Enable Dark Mode");

    // const toggleStyle = ()=>{
    //     if(mystyle.color === 'white'){
    //         setmystyle({
    //             color : '#232d32',
    //             backgroundColor : 'white',
    //             border : '1px solid #232d32'
    //         })
    //         setbtntext("Enable Dark Mode");
    //         setbtnstyle({
    //             color : 'white',
    //             backgroundColor : '#232d32',
    //             border : '1px solid white'
    //         })
    //     }
    //     else{
    //         setmystyle({
    //             color : 'white',
    //             backgroundColor : '#232d32',
    //             border : '1px solid white'
    //         })
    //         setbtntext("Enable Light Mode");
    //         setbtnstyle({
    //             color : '#232d32',
    //             backgroundColor : 'white',
    //             border : '1px solid #232d32'
    //         });
    //     }
    // };
    // if(mystyle.color === 'white'){
    //     document.body.style.backgroundColor = '#232d32';
    // }
    // else{
    //     document.body.style.backgroundColor = 'white';
    // }
    return (
    <div className='container'>
    <h1 style={{color : props.mode==='dark'?'white':'#232d32'}} /* style={{ color: mystyle.color === 'white' ? 'white' : '#232d32' }} */>About Us</h1>
        <div className="accordion my-3" id="accordionExample" >
            <div className="accordion-item" style={{backgroundColor : props.mode==='dark'?'rgb(43 64 75)':'white' , color : props.mode==='dark'?'white':'#232d32'}}>
                <h2 className="accordion-header" id = {props.mode}>
                <button className="accordion-button collapsed" type="button" /* style = {mystyle} */ data-bs-toggle="collapse" data-bs-target="#collapseOne" aria-expanded="true" aria-controls="collapseOne" style={{backgroundColor : props.mode==='dark'?'rgb(43 64 75)':'white' , color : props.mode==='dark'?'white':'#232d32'}}>
                    <strong>Analyze Your text</strong>
                </button>
                </h2>
                <div id="collapseOne" className="accordion-collapse collapse" /* style = {mystyle} */ data-bs-parent="#accordionExample">
                <div className="accordion-body">
                TextUtils is a powerful tool designed to streamline text analysis tasks effortlessly. Whether you need to conduct word count, character count, or delve deeper into linguistic insights, TextUtils has got you covered. Our intuitive interface empowers users to swiftly analyze their text, enabling efficient content evaluation and optimization. Say goodbye to tedious manual counting and welcome a seamless text analysis experience with TextUtils.                </div>
                </div>
            </div>
            <div className="accordion-item" style={{backgroundColor : props.mode==='dark'?'rgb(43 64 75)':'white' , color : props.mode==='dark'?'white':'#232d32'}}>
                <h2 className="accordion-header" id = {props.mode}>
                <button className="accordion-button collapsed" type="button" /* style = {mystyle} */ data-bs-toggle="collapse" data-bs-target="#collapseTwo" aria-expanded="false" aria-controls="collapseTwo" style={{backgroundColor : props.mode==='dark'?'rgb(43 64 75)':'white' , color : props.mode==='dark'?'white':'#232d32'}}>
                    <strong>Free To Use</strong>
                </button>
                </h2>
                <div id="collapseTwo" className="accordion-collapse collapse" /* style = {mystyle} */ data-bs-parent="#accordionExample">
                <div className="accordion-body">
                TextUtils is your go-to solution for effortless text analysis. As a free character counter tool, TextUtils offers instantaneous character count and word count statistics, catering to your specific text-related needs. Whether you're crafting content for social media posts, essays, or business communications, TextUtils provides accurate insights into the number of words and characters, ensuring your content meets required limits. With TextUtils, you can seamlessly manage text with ease, making it ideal for individuals and professionals alike seeking efficiency and precision in their writing endeavors.                </div>
                </div>
            </div>
            <div className="accordion-item" style={{backgroundColor : props.mode==='dark'?'rgb(43 64 75)':'white' , color : props.mode==='dark'?'white':'#232d32'}}>
                <h2 className="accordion-header" id = {props.mode}>
                <button className="accordion-button collapsed" type="button" /* style = {mystyle} */ data-bs-toggle="collapse" data-bs-target="#collapseThree" aria-expanded="false" aria-controls="collapseThree" style={{backgroundColor : props.mode==='dark'?'rgb(43 64 75)':'white' , color : props.mode==='dark'?'white':'#232d32'}}>
                    <strong>Browser Compatible</strong>
                </button>
                </h2>
                <div id="collapseThree" className="accordion-collapse collapse" /* style = {mystyle} */    data-bs-parent="#accordionExample">
                <div className="accordion-body">
                TextUtils is a versatile word counter software that seamlessly integrates with all major web browsers, including Chrome, Firefox, Internet Explorer, Safari, and Opera. Whether you're composing content for Facebook, blogging, writing books, managing Excel documents, analyzing PDF files, or crafting essays, TextUtils is your reliable companion for accurate character counting. With its compatibility across various platforms and formats, TextUtils ensures convenience and efficiency in your text analysis tasks, empowering you to effortlessly meet word or character limits across a wide range of applications.                </div>
                </div>
            </div>
        </div>
        {/* <div className="container">
        <button className="btn " style={btnstyle} onClick = {toggleStyle} type="submit">{btntext}</button>
        </div> */}
    </div>
  )
}
