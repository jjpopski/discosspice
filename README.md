DISCOS SPICE
============


Wrapper of the [NASA NAIF](https://naif.jpl.nasa.gov/naif/)  CSpice library to get topocentric coordinates of solar system bodies
Contains kernels to be used.


Requirements
-------------

* [Cspice toolkit]( https://naif.jpl.nasa.gov/naif/toolkit.html).
* [Google testing suite]( https://github.com/google/googletest) 
* [JPL DE430](https://naif.jpl.nasa.gov/pub/naif/generic_kernels/spk/planets/de430.bsp)

Optional kernels:
*  [Solar System satellites kernels](https://naif.jpl.nasa.gov/pub/naif/generic_kernels/spk/satellites/)


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


