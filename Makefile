CC=c++
CFLAGS= -lm 
CFLAGS_TEST= -L/opt/gtest/lib -lgtest -lgtest_main -lpthread 
DEPS = SolarSystemBodyEphem.h
# CSPICELIBPATH=/mnt/d/Work/Cspice_2014/cspice/lib/
# CSPICEINCLUDE=/mnt/d/Work/Cspice_2014/cspice/include/
INCLUDE=   -I$(CSPICEINCLUDE) -I.  
VPATH = src 

%.o: %.cpp $(DEPS)
	$(CC) -c  -o  $@ $< $(CFLAGS) $(INCLUDE)
	
lib: SolarSystemBodyEphem.o
	ar rcs lib/discosspice.a SolarSystemBodyEphem.o
	

ssbody:  SolarSystemBodyEphem.o   main.o 
	$(CC)  -o SolarSystemBodyEphem      main.o discosspice.a $(CSPICELIBPATH)cspice.a -I/mnt/d/Work/Cspice_2014/cspice/include

clean:
	rm -f  *.o lib/*.a 
	
test:  lib SolarSystemBodyEphem.o  gtestexample.o
	$(CC) -o TestSolSysEphem -I/usr/local/include  gtestexample.o  discosspice.a $(CSPICELIBPATH)/cspice.a $(CFLAGS_TEST) 
	


