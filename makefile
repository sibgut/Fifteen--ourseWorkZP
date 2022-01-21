CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=build/src/fifteen.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=bin/Fifteen-CourseWorkZP

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@