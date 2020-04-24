#include "SolarSystemBodyEphem.h"
#define LENOUT 32
#define  MSGLEN         1841
 #include "SpiceUsr.h"

#include <string.h> 
SolarSystemBodyEphem::SolarSystemBodyEphem()
{
  
    erract_c ( "SET", LENOUT, "RETURN" ); // set cpsice to return after error. 

   
}


SolarSystemBodyEphem::~SolarSystemBodyEphem()
{

   
}

int SolarSystemBodyEphem::initializeKernel (std::string kernel_file,int& total_kernel)
{
    
// Debug    

      #define  FILLEN   256
      #define  TYPLEN   33
      #define  SRCLEN   256

      SpiceInt        which;
      SpiceInt        count;
      SpiceInt        handle;

      SpiceChar       file  [FILLEN];
      SpiceChar       filtyp[TYPLEN];
      SpiceChar       source[SRCLEN];
            SpiceBoolean    found;

//end debug
      
    
    
    
    
    
    SpiceChar               msg [ MSGLEN ];
    SpiceChar               action[LENOUT];
    

    erract_c ( "get", LENOUT, action ); // get info about exit in case of errors. 
    std::cout << "Action err: "<< action << std::endl; 
    furnsh_c (kernel_file.c_str());   // load kernels from metakernel kernel_file
    ktotal_c ( "ALL", &total_kernel );    // counts all loaded kernels
    
    
    
    
     if ( total_kernel == 0 )
            {
            printf ( "No SPK files loaded at this time.\n" );
            }
         else
            {
            printf ( "The loaded SPK files are: \n\n" );
            }
    
         for (int  which = 0;  which < total_kernel;  which++ )
            {
                
            kdata_c ( which,  "ALL",    FILLEN,   TYPLEN, SRCLEN, 
                      file,   filtyp,  source,  &handle,  &found ); 
            printf ( "%s\n",  file   );
            }

 
    if ( failed_c() ) 
      {
         /*
         Get explanation text for the current short message 
         and print it: 
         */ 

         getmsg_c ( "SHORT", MSGLEN, msg );  // prints out error msg. 
         std::cout << msg << std::endl;

         
         return 1;  // if failed. 
         
      } else return 0;
   
}


bool  SolarSystemBodyEphem:: setBodyById(int id)
{
     
#define BODYNAMELEN 32
    
      SpiceBoolean found;
      
      SpiceChar bodyName[BODYNAMELEN];
      bodc2n_c(id,BODYNAMELEN,bodyName,&found); // gets body name from its code.
      
     m_bodyid=id;
     m_bodyname=std::string(bodyName);    
    
     return found;
     
 

}


bool  SolarSystemBodyEphem::setBodyByName(  std::string bodyName)
{

     SpiceInt code;
     SpiceBoolean found;

     bodn2c_c (bodyName.c_str(),&code,&found);  // gets body code from its name
              std::cout <<"zz:"<<bodyName <<","<<code<<std::endl;

     m_bodyid=code;
     m_bodyname=bodyName;
     
     return found;
     

    
}

void SolarSystemBodyEphem::getPosititionRange (double jd,double& et, double& ra, double& dec, double& range)
{
    
    SpiceDouble starg[6],xform[6][6];
    SpiceDouble lt;
    double vout[6],jrange[4];
    
    std::ostringstream strs;
    strs << std::fixed <<jd<< " JD";
    std::string ut  = strs.str(); //
    str2et_c ( ut.c_str(), &et);
    std::cout << et << std::endl;
    
    std::cout<< "ET: " << et << std::endl;
    spkezr_c(m_bodyname.c_str(),et,m_ref.c_str(),"LT",m_observerLocation.c_str(),starg,&lt);
    sxform_c ( m_ref.c_str(), "J2000",   et,    xform);
    mxvg_c ( xform,starg,6,6,vout);
    memcpy(jrange,vout,3*sizeof(double));
//     for (int i=0;i<3;i++) std::cout<<xform[i]<<std::endl;
    recrad_c(jrange,&range,&ra,&dec);
    std::cout << "Ra Dec:" << ra << dec <<std::endl;
    
    ra *=dpr_c();
    dec *=dpr_c();
    
    
    
      /*
     void spkezr_c ( ConstSpiceChar     *targ,
                   SpiceDouble         et,
                   ConstSpiceChar     *ref,
                   ConstSpiceChar     *abcorr,
                   ConstSpiceChar     *obs,
                   SpiceDouble         starg[6],
                   SpiceDouble        *lt        )*/
  
    
    

}

void SolarSystemBodyEphem::setObserverLocation( const std::string  site)
{
    
    
    m_observerLocation=site;
    m_ref=m_observerLocation+"_TOPO";
    
    
}



std::string SolarSystemBodyEphem::getObserverLocation()
{

    
    
    return m_observerLocation;

}


std::string SolarSystemBodyEphem::getBodyName()
{
    return m_bodyname;

}




 std::string SolarSystemBodyEphem::spiceToolkitVersion()
{
   ConstSpiceChar  * versn;
   versn = tkvrsn_c ( "TOOLKIT" ); 
   return std::string(versn);

}



int SolarSystemBodyEphem::addKernel(std::string kernel)
{
    int total_kernel;
    
     
    furnsh_c (kernel.c_str());   // load kernels from metakernel kernel_file
    ktotal_c ( "ALL", &total_kernel );
    return total_kernel;
    
}



