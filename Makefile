CXX = g++
CXXFLAGS = -std=c++17 -Wall

OBJS = main.o library.o

all: game_library

game_library: $(OBJS)
	$(CXX) $(CXXFLAGS) -o game_library $(OBJS)

main.o: main.cpp library.h game.h
	$(CXX) $(CXXFLAGS) -c main.cpp

library.o: library.cpp library.h game.h
	$(CXX) $(CXXFLAGS) -c library.cpp

clean:
	rm -f *.o game_library
