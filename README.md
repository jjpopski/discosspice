DISCOS SPICE
============


Wrapper of the [NASA NAIF](https://naif.jpl.nasa.gov/naif/)  CSpice library to get topocentric coordinates of solar system bodies
Contains kernels to be used.


Requirements
-------------

* [Cspice toolkit]( https://naif.jpl.nasa.gov/naif/toolkit.html).
* [Google testing suite]( https://github.com/google/googletest) 

Kernels can be dowoloaded [NASA NAIF Spacecrapts and Planets Kernels page](https://naif.jpl.nasa.gov/pub/naif/generic_kernels/spk/)

Required:


*  [JPL DE432](https://naif.jpl.nasa.gov/pub/naif/generic_kernels/spk/planets/de432s.bsp)  

Optional:

*  [Mars](https://naif.jpl.nasa.gov/pub/naif/generic_kernels/spk/satellites/mar097.bsp)
*  [Jupiter](https://naif.jpl.nasa.gov/pub/naif/generic_kernels/spk/satellites/jup343.bsp)
*  [Saturn](https://naif.jpl.nasa.gov/pub/naif/generic_kernels/spk/satellites/sat427.bsp)
*  [Uranus](https://naif.jpl.nasa.gov/pub/naif/generic_kernels/spk/satellites/ura111.bsp)
*  [Neptune](https://naif.jpl.nasa.gov/pub/naif/generic_kernels/spk/satellites/nep086.bsp)
*  [Pluto](https://naif.jpl.nasa.gov/pub/naif/generic_kernels/spk/satellites/plu055.bsp)

Minor bodies kernels can be generated from [Advanced Horizons][https://ssd.jpl.nasa.gov/x/spk.html]



## Test installation


Export evnvironment variable to locate cspice library. Customize the example below according to your need

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


Jpl DE432  contains ephemeris data for planets barycenter and the Sun (NAIF ID condes from 1 to 10). Also, it contains mass centers of 
Earth (399) and Moon (301). There are also Mercury and Venus mass centers because have the same location of the respective barycenter.


```cpp

      double ra,dec,range,et;
      SolarSystemBodyEphem solsys= SolarSystemBodyEphem();
      solsys.setObserverLocation("SRT");
      solsys.setBodyByName("Saturn Barycenter");
       
      solsys.getPosititionRange(2457836.500000000,et,ra,dec,range); 
// getPosititionRange(juliand_day,&et,&ra,&dec,&range)
// juliand day as input, ra & dec are right ascensione and declination in radians (output)
```

Mass centers for outer planets are available through optional kernels


```cpp

      double ra,dec,range,et;
      SolarSystemBodyEphem solsys= SolarSystemBodyEphem();
      solsys.setObserverLocation("SRT");
      solsys.addKernel('kernels/sat427.bsp')
      solsys.setBodyByName("Saturn");
       solsys.getPosititionRange(2457836.500000000,et,ra,dec,range); 
// getPosititionRange(juliand_day,&et,&ra,&dec,&range)
// juliand day as input, ra & dec are right ascensione and declination in radians (output)

