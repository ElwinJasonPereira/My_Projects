import React from 'react'
import "../App.css"
export default function Loader() {
  return (
    <div className='container d-flex justify-content-center align-items-center' style={{height : '70vh'}}>
        <button className="btn btn-light" type="button" disabled>
        <span className="spinner-border custom-spinner me-4" role="status" aria-hidden="true"></span>
        <span className="custom-loading-text">Loading...</span>
        </button>
    </div>
  )
}
