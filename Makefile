CXX = g++
CXXFLAGS = -g -Wall -Wextra -Wpedantic

.PHONY: all clean

all: program

program: main.cpp Van.o Car.o Vehicle.o CarPark.o
	$(CXX) $(CXXFLAGS) -o $@ $^

UnitTest: UnitTest.cpp Van.o Car.o Vehicle.o CarPark.o
	$(CXX) $(CXXFLAGS) -o $@ $^

Van.o: Van.cpp Vehicle.h
	$(CXX) $(CXXFLAGS) -c $<

Car.o: Car.cpp Vehicle.h
	$(CXX) $(CXXFLAGS) -c $<

Vehicle.o: Vehicle.cpp Vehicle.h
	$(CXX) $(CXXFLAGS) -c $<

CarPark.o: CarPark.cpp Vehicle.h
	$(CXX) $(CXXFLAGS) -c $<

check: UnitTest
	./UnitTest
clean:
	$(RM) *.o
	$(RM) program