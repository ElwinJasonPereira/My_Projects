import { useState } from 'react';
import Navbar from './Components/Navbar';
import Cards from './Components/Cards'
import Loader from './Components/Loader';

function App() {
  const [tracks, setTracks] = useState([]);
  const [load, setLoad] = useState(1)
  // const [check, setCheck] = useState()

  const getTracks = async (inval) =>{
    setLoad(0)
    let data = await fetch(`https://v1.nocodeapi.com/josediego/spotify/emYfRHAltZnTuRWu/search?q=${inval}&type=track`);
    let convdata = await data.json();
    console.log(convdata.tracks.items);
    setTracks(convdata.tracks.items);
    setLoad(1)
  }

  return (
    <>
    <Navbar send = {getTracks}/>
    {load === 1?<Cards tracks = {tracks}/>:<Loader/>}
    </>
  );
}

export default App;
