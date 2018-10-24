#setting up project path
cppsrc=$(wildcard src/*.cpp)
obj=$(cppsrc:.cpp=.o)
OBJECTNAME=test_main.o

#setting up some variables
CXX=g++
CXXFLAGS=-std=c++11 -g -ftest-coverage -fprofile-arcs
LDFLAGS=-lcppunit -lgcov

all:$(obj) 
	$(CXX) -c $^ $(LDFLAGS)

.PHONY:clean
clean:
	rm -v -f *.txt *.o *.gcda src/*.gcda src/*.o src/*.gcno *.gcno
