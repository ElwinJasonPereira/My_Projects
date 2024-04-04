import React from 'react'

export default function Cards(props) {
    const mstomin = (value) => {
        const val = value / 60000;
        const s = val.toString().split(".")
        return Math.ceil(s[0]) +":"+ (s[1]*60).toString().slice(0,2) + " mins";
        }
  return (
<div className="container">
    <div className="row">
      {props.tracks.map((element) => {
        return(
          <div key = {element.id} className="col-lg-3 col-md-6 py-2">
            <div className="card" style={{ width: "19rem" , height : "35rem" , overflowY : "auto"}}>
            <img src={element.album.images[0].url} className="card-img-top" alt="..." />
            <div className="card-body">
              <h5 className="card-title">{element.name}</h5>
              <p className="card-text">
                <strong>Artist: </strong>
                {element.artists.map((artist,index) =>(
                  <span  key={index}>{artist.name}{index !== element.artists.length - 1 ? ', ' : ''}</span>
      ))}
              </p>
              <p className="card-text">
                <strong>Duration: </strong>{mstomin(element.duration_ms)}
              </p>
              <p className="card-text">
                <strong>Release date: </strong>{element.album.release_date}
              </p>
              <audio src={element.preview_url} controls={element.preview_url !== null} className='w-100'></audio>
              {element.preview_url===null?<p className="card-text d-flex justify-content-center">
                No preview link found
              </p>:""}
              <div className="button d-flex justify-content-center py-2">
                <a href="/" className="btn btn-outline-success fs-5 fw-bold">Listen Song</a>
              </div>
            </div>
          </div>
          </div>
        );
      })}
    </div>
  </div>  
  )
}
