SOURCES = $(wildcard *.cpp)
OBJECTS = $(SOURCES:.cpp=.o)
FLAGS = -std=c++17
#-Wall -Wextra

all: $(OBJECTS) countUniquePaths
.cpp.o:
	g++ $(FLAGS) -c $<
clean:
	rm $(OBJECTS) $(wildcard *.exe)
countUniquePaths: countUniquePaths.o
	g++ countUniquePaths.o -o countUniquePaths
