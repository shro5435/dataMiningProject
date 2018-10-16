CXX = g++
CXXFLAGS	= -std=c++11 -Wall

all: ElectoralMap
	
run: ElectoralMap
	./ElectoralMap

clean:
	rm ElectoralMap.o ElectoralMap

ElectoralMap: ElectoralMap.o main.cpp
	$(CXX) $(CXXFLAGS) main.cpp ElectoralMap.o -o ElectoralMap

ElectoralMap.o: ElectoralMap.cpp
	$(CXX) $(CXXFLAGS) -c ElectoralMap.cpp
