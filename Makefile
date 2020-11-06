SOURCES = $(wildcard *.cpp)
OBJECTS = $(SOURCES:.cpp=.o)
FLAGS = -std=c++17 -c
#-Wall -Wextra

all: $(OBJECTS)
.cpp.o:
	g++ $(FLAGS) $<
clean:
	rm $(OBJECTS)
