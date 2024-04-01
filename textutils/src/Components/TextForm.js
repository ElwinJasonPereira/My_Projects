import React, {useState} from 'react'
import './Navbar.css';
export default function TextForm(props) {
  const [text , setText] = useState("");

  const handleUpClick = ()=>{
    // console.log("Convert To Uppercase button was clicked:    "+text);
    let newText = text.toUpperCase();
    setText(newText);
    props.showAlert("Text converted to Upper Case","success")
  }

  const handleLowClick = ()=>{
    // console.log("Convert To Lowercase button was clicked:    "+text);
    let newText = text.toLowerCase();
    setText(newText);
    props.showAlert("Text converted to Lower Case","success")
  }  

  const handleCopy = ()=>{
    navigator.clipboard.writeText(text);
    props.showAlert("Copied Text to Clipboard","success");
  }

  const handleExtraSpaces = ()=>{
    let newText = text.split(/[ ]+/);
    setText(newText.join(" "));
    props.showAlert("Removed Extra Spaces from the Given Text","success")
  }

  const handleClearText = ()=>{
    // console.log("Clear Text button was clicked:");
    setText('');
    props.showAlert("Text Area has been  Cleared","success")
  } 

  const handleChange = (event)=>{
    // console.log("On Change");
    setText(event.target.value);    
  }

  return (
    <>
    <div className='container' style={{color : props.mode==='dark'?'white':'#232d32'}}>
        <h1>{props.heading}</h1>
        <textarea className="form-control my-4" value= {text} placeholder = "Enter Text here:" onChange = {handleChange} style={{backgroundColor : props.mode==='dark'?'rgb(43 64 75)':'white' , color : props.mode==='dark'?'white':'#232d32'}} id={props.mode} rows="3"></textarea>
        </div>
        <button disabled = {text.length === 0} className="btn btn-outline-primary mx-1 my-1" style={{color : props.mode==='dark'?'white':'#232d32'}} onClick={handleUpClick}>Convert To Uppercase</button>
        <button disabled = {text.length === 0} className="btn btn-outline-primary mx-1 my-1" style={{color : props.mode==='dark'?'white':'#232d32'}} onClick={handleLowClick}>Convert To Lowercase</button>
        <button disabled = {text.length === 0} className="btn btn-outline-primary mx-1 my-1" style={{color : props.mode==='dark'?'white':'#232d32'}} onClick={handleExtraSpaces}>Remove Extra Spaces</button>
        <button disabled = {text.length === 0} className="btn btn-outline-primary mx-1 my-1" style={{color : props.mode==='dark'?'white':'#232d32'}} onClick={handleCopy}>Copy Text</button>
        <button disabled = {text.length === 0} className="btn btn-outline-primary mx-1 my-1" style={{color : props.mode==='dark'?'white':'#232d32'}} onClick={handleClearText}>Clear Text</button>


    <div className='container my-3' style={{color : props.mode==='dark'?'white':'#232d32'}}>
      <h1>
        Text Summary
      </h1>
      <p>{text.split(/\s+/).filter(text => text !== "").length} words and {text.length} characters</p>
      <p>{1/300 * text.split(" ").filter(text => text !== "").length} Minutes to read</p>
      <h2>
        Preview:
      </h2>
      <p>{text.length>0?text:'Nothing To Prieview Yet!'}</p>
    </div>
    </>
  )
}
TextForm.defaultProps = {
    heading : "Enter The Text"
}