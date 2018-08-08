CXXFLAGS += -std=c++14

comparator: comparator.o
	g++ comparator.o -o bin/comparator

comparator.o: comparator.cpp
	g++ -c comparator.cpp  $(CXXFLAGS)