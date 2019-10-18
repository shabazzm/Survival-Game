
CXX=g++
CXXFLAGS=-c -Wall -std=c++11
LDFLAGS=
SOURCES=main.cpp Menu.cpp Game.cpp Space.cpp CrashSite.cpp Forest.cpp River.cpp Boat.cpp Cabin.cpp Safety.cpp inputValidation.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=main

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm *o main



