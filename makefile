CXX=arm-linux-gnueabihf-g++

INCLUDES=-I/usr/arm-linux-gnueabi/include/c++/4.6.3 -I./include

CPPFLAGS=-D__GXX_EXPERIMENTAL_CXX0X__ -D__GCC_HAVE_SYNC_COMPARE_AND_SWAP_1 -D__GCC_HAVE_SYNC_COMPARE_AND_SWAP_2 -D__GCC_HAVE_SYNC_COMPARE_AND_SWAP_4 -D__GCC_HAVE_SYNC_COMPARE_AND_SWAP_8

CXXFLAGS=-std=c++0x -O0 -g3 -Wall -c -fmessage-length=0 -pthread $(CPPFLAGS) $(INCLUDES)

LDFLAGS=-lpthread

LDLIBS=-L/usr/arm-linux-gnueabi/lib

RM=rm -f

SOURCES=./BlackLib/BlackADC/BlackADC.cpp ./BlackLib/BlackDirectory/BlackDirectory.cpp  ./BlackLib/BlackGPIO/BlackGPIO.cpp ./BlackLib/BlackI2C/BlackI2C.cpp ./BlackLib/BlackMutex/BlackMutex.cpp ./BlackLib/BlackPWM/BlackPWM.cpp ./BlackLib/BlackSPI/BlackSPI.cpp ./BlackLib/BlackThread/BlackThread.cpp ./BlackLib/BlackTime/BlackTime.cpp  ./BlackLib/BlackUART/BlackUART.cpp ./BlackCore.cpp ./main.cpp

OBJECTS=$(SOURCES:.cpp=.o)

EXECUTABLE=BlackLib-executable


all: $(SOURCES) $(EXECUTABLE)
    
$(EXECUTABLE): $(OBJECTS) 
	$(CXX) $(LDLIBS) $(OBJECTS) $(LDFLAGS) -o $@

.cpp.o:
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	$(RM) $(OBJECTS)

