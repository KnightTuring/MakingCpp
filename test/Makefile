#-------------------------------------------------------
# This is the Makefile for the test directory,		|
# it will build the binary. During the build 		|
# process it will link the libcomplex library which is 	|
# created by an upper level Makefile.			|
#-------------------------------------------------------

#-----------------------------------------------
# Setting up the path for cpp files, .o files,	|
# libcomplex path and the binary file path	|
#-----------------------------------------------
cppsrc=$(wildcard src/*.cpp)
obj=$(cppsrc:.cpp=.o)
EXECUTABLE=./bin/m.out
LIBPATH=../lib

#-----------------------------------------------
# Let make know about which compiler to use	| 
# and what flags to pass during compilation.	|
#-----------------------------------------------
CXX=g++
CXXFLAGS=-std=c++11 -g -ftest-coverage -fprofile-arcs
LDFLAGS=-lcppunit -lgcov -lcomplex

# ----------------------------------------------
# Recipes for ultimately getting a binary	|
# ----------------------------------------------
all:$(EXECUTABLE)

$(EXECUTABLE):$(obj)
	(cd ..; make)
	$(CXX) $(CXXFLAGS) -o $@ $^ -L$(LIBPATH) $(LDFLAGS)

$(obj):$(cppsrc)

# ----------------------------------------------
# Rules for make clean				|
# ----------------------------------------------
.PHONY:clean
clean:
	(cd ..; make clean)
	rm -v -f ./bin/*.out ./bin/*.xml *.txt *.o *.gcda src/*.gcda src/*.o src/*.gcno *.gcno *.gcda
