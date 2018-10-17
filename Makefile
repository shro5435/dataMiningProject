CXX = g++
CXXFLAGS	= -std=c++11 -Wall

all: election

clean:
	rm election Election.o ElectoralMap.o TextUI.o

election: main.cpp Election.o ElectoralMap.o TextUI.o
	$(CXX) $(CXXFLAGS) main.cpp Election.o ElectoralMap.o TextUI.o -o election

TextUI.o: TextUI.cpp
	$(CXX) $(CXXFLAGS) -c TextUI.cpp

ElectoralMap.o: ElectoralMap.cpp
		$(CXX) $(CXXFLAGS) -c ElectoralMap.cpp

Election.o: Election.cpp
	$(CXX) $(CXXFLAGS) -c Election.cpp
