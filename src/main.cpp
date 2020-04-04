#include "SolarSystemBodyEphem.h"

int main (int argc, char **argv)
{
    
  
   std::string toolkit_version;

   SolarSystemBodyEphem* solsys= new SolarSystemBodyEphem();
   toolkit_version= solsys->spiceToolkitVersion();
   std::cout << "Toolkit Version:" << toolkit_version << std::endl;
   
   
   solsys->setBodyByName("Saturn");
  
   if (solsys->setBodyByName(" Jupiter")){
       
        std::cout << "Found" << std::endl;
   } else{
      std::cout << "Not Found" << std::endl;
   }
 
    

   std::cout << solsys ->getBodyName();
   

   return 0;

}
// 
