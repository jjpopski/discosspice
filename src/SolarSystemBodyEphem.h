#ifndef _SOLARSYSTEMBODY
#define _SOLARSYSTEMBODY

#include <string>
// #include <string.h>
#include <iostream>
#include "SpiceUsr.h"
#include <sstream>



class SolarSystemBodyEphem {

public:

    SolarSystemBodyEphem (); 
    ~SolarSystemBodyEphem();
    

  bool setBodyById (int id);
  bool setBodyByName (  std::string bodyName);
  void setObserverLocation(const std::string site);
  
  void getPosititionRange (double jd,double& et, double& ra, double& dec, double& range);
  std::string getObserverLocation();
  std::string getBodyName();
  int getBodyId(){return m_bodyid;};
  int initializeKernel (std::string, int&);
  

/*
   

*/
 std::string spiceToolkitVersion();


  
private: 
 
   int m_bodyid;
   std::string m_bodyname;
   
       
   std::string m_observerLocation;
   std::string m_ref;
};

#endif


