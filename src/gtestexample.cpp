// main.cpp

#include "SolarSystemBodyEphem.h"
#include "gtest/gtest.h"
#include <iostream>
 
class EphemTest : public ::testing::Test {
 protected:
     
     SolarSystemBodyEphem solsys= SolarSystemBodyEphem();

  virtual void SetUp() {
      

  }

  virtual void TearDown() {
  }
};



   

TEST_F(EphemTest,versionTest){
    std::string toolkit_version;
     EXPECT_STREQ("CSPICE_N0065",solsys.spiceToolkitVersion().c_str());
 
}



TEST_F(EphemTest,setBodyById){
    
//      SolarSystemBodyEphem solsys= SolarSystemBodyEphem();
     ASSERT_EQ(false,solsys.setBodyById(-3333333));
     ASSERT_EQ(true,solsys.setBodyById(599));

     ASSERT_STRCASEEQ("Jupiter",solsys.getBodyName().c_str());
     
    
     
     
}



TEST_F(EphemTest,setObserverLocation)
{
//       SolarSystemBodyEphem solsys= SolarSystemBodyEphem();
      solsys.setObserverLocation("SRT");
      ASSERT_STRCASEEQ("SRT",solsys.getObserverLocation().c_str());

    
}

TEST_F(EphemTest,setBodyName){
    
//       SolarSystemBodyEphem solsys= SolarSystemBodyEphem();
      ASSERT_EQ(false,solsys.setBodyByName("Jupyter"));
//      ASSERT_EQ(true,solsys.setBodyByName("Jupiter"));
//      ASSERT_EQ("Jupiter",solsys.getBodyName());
//      ASSERT_EQ(599,solsys.getBodyId());     
// 
//      ASSERT_EQ(true,solsys.setBodyByName("Saturn"));
//      ASSERT_EQ("Saturn",solsys.getBodyName());
//      ASSERT_EQ(699,solsys.getBodyId());     
//     
}
TEST_F(EphemTest,ititialize)
{
      int r;
//       SolarSystemBodyEphem solsys= SolarSystemBodyEphem();
      
  //    ASSERT_EXIT (solsys.initializeKernel("../inaf_kernels.txt"),
                                      //        ::testing::ExitedWithCode(1),"");
  //     ASSERT_EQ(1,solsys.initializeKernel("../inaf_kernels.txtccc"));
       ASSERT_EQ(0,solsys.initializeKernel("inaf_kernels.txt",r));
       ASSERT_EQ(14,r);
       
      
}

TEST_F(EphemTest,getPosition){
       double ra,dec,range,et;
       
//        SolarSystemBodyEphem solsys= SolarSystemBodyEphem();
       solsys.setObserverLocation("SRT");
       solsys.setBodyByName("Saturn");
       
       solsys.getPosititionRange(2457836.500000000,et,ra,dec,range);
       EXPECT_NEAR(267.207118370,ra,2.7e-5);
       EXPECT_NEAR(-22.081696425,dec,2.7e-5);
       
       solsys.getPosititionRange(2458932.500000000  ,et,ra,dec,range);
       EXPECT_NEAR(302.046613001,ra,2.7e-5);
       EXPECT_NEAR(-20.227066752,dec,2.7e-5);
     //EXPECT_NEAR(  140254384.185,et,1e-5);
    //       EXPECT_DOUBLE_EQ(100989360.974561,et);
     
}




// Google Test can be run manually from the main() function
// or, it can be linked to the gtest_main library for an already
// set-up main() function primed to accept Google Test test cases.
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}

// Build command: g++ main.cpp -lgtest
