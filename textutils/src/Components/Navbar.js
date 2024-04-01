import React from 'react'
import PropTypes from 'prop-types'
import './Navbar.css'
import {Link} from 'react-router-dom'
export default function Navbar(props) {
    const cap = (word) =>{
        return word.charAt(0).toUpperCase() + word.slice(1);
    }
  return (
    <nav className={`navbar navbar-expand-lg navbar-${props.mode} bg-${props.mode}`} style={{padding:'25px'}}>
        <div className="container-fluid">
            <Link className="navbar-brand" to="/">{props.title}</Link>
            <button className="navbar-toggler" type="button" data-bs-toggle="collapse" data-bs-target="#navbarSupportedContent" aria-controls="navbarSupportedContent" aria-expanded="false" aria-label="Toggle navigation">
            <span className="navbar-toggler-icon"></span>
            </button>
            <div className="collapse navbar-collapse" id="navbarSupportedContent">
            <ul className="navbar-nav me-auto mb-2 mb-lg-0">
                <li className="nav-item">
                <Link className="nav-link active" aria-current="page" to="/">Home</Link>
                </li>
                <li className="nav-item">
                <Link className="nav-link active" aria-current="page" to="/about">{props.abouttext}</Link>
                </li>
            </ul>
            <form style={{position : "absolute", top : 30, right : 10}} className="d-flex my-2" role="search">
                <input className="form-control me-2 " id={props.mode} type="search" placeholder='Search' style={{backgroundColor : props.mode==='dark'?'rgb(43 64 75)':'white', color : props.mode==='dark'?'white':'#232d32'}} aria-label="Search"/>
                <button className="btn btn-outline-danger" style={{color : props.mode==='dark'?'white':'#232d32'}}  type="submit">Search</button>
            </form>
            <div style = {{position : "absolute", top : 5, right : 20}} className={`form-check form-switch text-${props.mode === 'light'?'dark':'light'}`}>
                <input className="form-check-input" onClick = {props.toggleMode} type="checkbox" style={{backgroundColor: props.mode==='light'?'#232d32':'white', backgroundImage : props.mode === 'light'?'url("data:image/svg+xml,%3csvg xmlns=\'http://www.w3.org/2000/svg\' viewBox=\'-4 -4 8 8\'%3e%3ccircle r=\'3\' fill=\'%23fff\'/%3e%3c/svg%3e")':'url("data:image/svg+xml,%3csvg xmlns=\'http://www.w3.org/2000/svg\' viewBox=\'-4 -4 8 8\'%3e%3ccircle r=\'3\' fill=\'rgba(0, 0, 0, 0.25)\'/%3e%3c/svg%3e")', borderColor : 'red'}} role="switch" id="flexSwitchCheckDefault" defaultChecked={props.mode === 'dark'}/>
            <label className="form-check-label" htmlFor="flexSwitchCheckDefault">Enable {props.mode === 'dark'?cap('light'):cap('dark')} Mode</label>
            </div>
            </div>
        </div>
    </nav>
  )
}

Navbar.propTypes = {
                    // title : PropTypes.string.isRequired,
                    title : PropTypes.string,
                    abouttext : PropTypes.string,
}
Navbar.defaultProps = {
    title : 'TextUtils',
    abouttext : 'About'
}