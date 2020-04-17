DISCOS SPICE
============


Wrapper of the [NASA NAIF](https://naif.jpl.nasa.gov/naif/)  CSpice library to get topocentric coordinates of solar system bodies
Contains kernels to be used.


Requirements
-------------

* [Cspice toolkit]( https://naif.jpl.nasa.gov/naif/toolkit.html).
* [Google testing suite]( https://github.com/google/googletest) 

Required kernels can be dowoloaded [NASA NAIF Spacecrapts and Planets Kernels page](https://naif.jpl.nasa.gov/pub/naif/generic_kernels/spk/)

*  [JPL DE432](https://naif.jpl.nasa.gov/pub/naif/generic_kernels/spk/planets/de432s.bsp)  
*  [Mars](https://naif.jpl.nasa.gov/pub/naif/generic_kernels/spk/satellites/mar097.bsp)
*  [Jupiter](https://naif.jpl.nasa.gov/pub/naif/generic_kernels/spk/satellites/jup343.bsp)
*  [Saturn](https://naif.jpl.nasa.gov/pub/naif/generic_kernels/spk/satellites/sat427.bsp)
*  [Uranus](https://naif.jpl.nasa.gov/pub/naif/generic_kernels/spk/satellites/ura111.bsp)
*  [Neptune](https://naif.jpl.nasa.gov/pub/naif/generic_kernels/spk/satellites/nep086.bsp)
*  [Pluto](https://naif.jpl.nasa.gov/pub/naif/generic_kernels/spk/satellites/plu055.bsp)



## Test installation


Export evnvironment variable to locate cspice library:
```console
export CSPICELIBPATH=/mnt/d/Work/Cspice_2014/cspice/lib/
export CSPICEINCLUDE=/mnt/d/Work/Cspice_2014/cspice/include/

```
Combile and build the library:

```console
make lib 

```

Testing:


```console
make test
./TestSolSysEphem
```

## Usage

```cpp

      double ra,dec,range,et;
      SolarSystemBodyEphem solsys= SolarSystemBodyEphem();
      solsys.setObserverLocation("SRT");
      solsys.setBodyByName("Saturn");
       
      solsys.getPosititionRange(2457836.500000000,et,ra,dec,range); 
// getPosititionRange(juliand_day,&et,&ra,&dec,&range)
// juliand day as input, ra & dec are right ascensione and declination in radians (output)
```


