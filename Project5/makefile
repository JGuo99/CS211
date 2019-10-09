CC=g++
CFLAGS=-c -Wall
SOURCES=evaluate.cpp
HEADERS=evalhead.h myStack.h proj5.h
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=proj5

$(EXECUTABLE): $(SOURCES) $(HEADERS)
	$(CC) -c $(SOURCES) $(CFLAGS)
	$(CC) -o $@ $(OBJECTS)

run:
	./$(EXECUTABLE)

debug: clean $(EXECUTABLE)
	./$(EXECUTABLE) -d

all: clean $(EXECUTABLE) run

clean:
	rm *.o proj5
