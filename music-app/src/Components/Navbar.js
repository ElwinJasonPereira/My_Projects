import React, { useState } from 'react'
import "../App.css"
export default function Navbar(props) {
    const [inval, setInval] = useState("");
    const [place, setPlace] = useState("Search")
    const handleClick = () =>{
        if(inval.length > 0){
            props.send(inval);
            setPlace("Search")
        }
        else{
            props.send("trending");
            setPlace("Trending")
        }
    }
    const handleKeyPress = (event) =>{
        if (event.key === 'Enter'){
            if(inval.length > 0){
                props.send(inval);
                setPlace("Search")
            }
            else{
                props.send("trending");
                setPlace("Trending")
            }
        }
    }

  return (
    <div>
        <nav className="navbar navbar-expand-lg bg-body-tertiary">
            <div className="container-fluid">
                <a className="navbar-brand" href="/">
                    MUSIC APP
                </a>
                <div className="collapse navbar-collapse d-flex justify-content-center" id="navbarSupportedContent">
                    <input
                        value={inval}
                        onChange={(event)=>{setInval(event.target.value)}}
                        onKeyPress={handleKeyPress}
                        className="form-control me-2  my-2 w-80"
                        type="search"
                        placeholder={place}
                        aria-label="Search"
                    />
                    <button onClick={handleClick} className="btn btn-outline-success" type="submit">
                        Search
                    </button>
                </div>
            </div>
        </nav>
    </div>
  )
}
