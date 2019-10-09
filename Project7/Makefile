Airport: Proj7.o Airport.o
	g++ Proj7.o Airport.o -o Airport

Proj7.o: Proj7.cpp
	g++ -c Proj7.cpp

Airport.o: Airport.cpp Airhead.h
	g++ -c Airport.cpp

clean:
	rm *.o Airport
