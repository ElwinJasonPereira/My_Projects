import { useState } from 'react';
import './App.css';

function App() {
  const [tracks, setTracks] = useState([]);
  const [inval, setInval] = useState("");
  const getTracks = async () =>{
    let data = await fetch(`https://v1.nocodeapi.com/josediego/spotify/emYfRHAltZnTuRWu/search?q=${inval}&type=track`);
    let convdata = await data.json();
    console.log(convdata.tracks.items);
    setTracks(convdata.tracks.items);
  }
  const mstomin = (value) => {
    const val = value / 60000;
    const s = val.toString().split(".")
    return Math.ceil(s[0]) +":"+ (s[1]*60).toString().slice(0,2) + " mins";
  }
  return (
    <>
      <nav className="navbar navbar-expand-lg bg-body-tertiary">
        <div className="container-fluid">
          <a className="navbar-brand" href="/">
            MUSIC APP
          </a>
          <div className="collapse navbar-collapse d-flex justify-content-center" id="navbarSupportedContent">
              <input
                value={inval}
                onChange={event=>{setInval(event.target.value)}}
                className="form-control me-2  my-2 w-75"
                type="search"
                placeholder="Search"
                aria-label="Search"
              />
              <button onClick={getTracks} className="btn btn-outline-success" type="submit">
                Search
              </button>
          </div>
        </div>
      </nav>

      <div className="container">
        <div className="row">
          {tracks.map((element) => {
            return(
              <div key = {element.id} className="col-lg-3 col-md-6 py-2">
                <div className="card" style={{ width: "15rem" }}>
                <img src={element.album.images[0].url} className="card-img-top" alt="..." />
                <div className="card-body">
                  <h5 className="card-title">{element.name}</h5>
                  <p className="card-text">
                    <strong>Artist: </strong>{element.artists[0].name}
                  </p>
                  <p className="card-text">
                    <strong>Duration: </strong>{mstomin(element.duration_ms)}
                  </p>
                  <p className="card-text">
                    <strong>Release date: </strong>{element.album.release_date}
                  </p>
                  <audio src={element.preview_url} controls className='w-100'></audio>
                </div>
              </div>

              </div>
            );
          })}
        </div>
      </div>  
    </>
  );
}

export default App;
