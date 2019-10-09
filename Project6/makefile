Airport: sguo35Proj6.o Airport.o
	g++ sguo35Proj6.o Airport.o -o Airport

sguo35Proj6.o: sguo35Proj6.cpp
	g++ -c sguo35Proj6.cpp

Airport.o: Airport.cpp Airhead.h
	g++ -c Airport.cpp

clean:
	rm *.o Airport
