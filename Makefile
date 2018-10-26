#-----------------------------------------------
# This is the top level Makefile, it will	|
# make libraries of Complex which will be	| 
# linked later in the lower level compilation 	|
# process.					|
#-----------------------------------------------

cppsrc=$(wildcard src/*.cpp)
obj=$(cppsrc:.cpp=.o)
LIBNAME=./lib/libcomplex.a

#-----------------------------------------------
# Let make know about which compiler to use	| 
# and what flags to pass during compilation.	|
#-----------------------------------------------

CXX=g++
CXXFLAGS=-std=c++11 -g -c -ftest-coverage -fprofile-arcs -lcppunit

#-----------------------------------------------------------------------------------------------
# Now, 												|
# Step 1: Create an object file for Complex (Complex.o). Complex.cpp resides in ./src/		|
# Step 2: Create a static library ( .a extension ) called libcomplex from the object file.	|
# Step 3: That'll be it, pass the controls to the lower level Makefile				|
# ----------------------------------------------------------------------------------------------

all:$(LIBNAME)

$(obj)%.o:$(cppsrc)
	
$(LIBNAME):$(obj)
	ar rsv $@ $^
	(cd test; make)
.PHONY:clean
clean:
	#removed -r flag because we are considering specific files only and no directories
	rm -v -f *.gcda *.xml *.o *.out src/*.gcda src/*.o src/*.gcno test/src/*.o test/src/*.gcno\  lib/*.a *.gcno bin/*.out	
