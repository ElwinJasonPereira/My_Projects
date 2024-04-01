import React, { useState } from 'react';
import './App.css';
import About from './Components/About';
import Navbar from './Components/Navbar';
import TextForm from './Components/TextForm';
import Alerts from './Components/Alerts';
import {
  BrowserRouter as Router,
  Routes,
  Route
} from "react-router-dom";

function App() {
  const[mode , setmode] = useState('dark');
  const[alert , setAlert] = useState(null);
  const [a, seta] = useState(0)
  if(a === 0){
  document.body.style.backgroundColor = '#232d32'
  }
  const showAlert = (message , type)=>{
    setAlert({
      msg : message,
      type : type
    })
    setTimeout(() => {
      setAlert(null);
    }, 2000);
  }
  
  const toggleMode = ()=>{
    if(mode === 'light'){
      setmode('dark');
      document.body.style.backgroundColor = '#232d32'
      showAlert("Dark Mode has been enabled","success");
      seta(a => a + 1);
      // document.title = "TextUtils - Dark Mode"
    }
    else{
      setmode('light');
      document.body.style.backgroundColor = 'white'
      showAlert("Light Mode has been enabled","success");
      seta(a => a + 1);
      // document.title = "TextUtils - Light Mode"
    }
    
  }
  return (
    <>
    <Router>
    <Navbar mode = {mode} toggleMode = {toggleMode}/>
    <Alerts alert = {alert}/>
    <Routes>
          <Route exact path="/about" element = {<About mode = {mode} toggleMode = {toggleMode}/>}/>
          <Route exact path="/" element = { <div className="container"> <TextForm heading = "Enter the text to analyze below: "  mode = {mode} showAlert = {showAlert} toggleMode = {toggleMode}/> </div>} />
    </Routes>
    </Router>
    </>
  );
}

export default App;
