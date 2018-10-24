cppsrc=$(wildcard src/*.cpp)
obj=$(cppsrc:.cpp=.o)

cpptestsrc=test/src/test_main.o		   |

#The following is not needed:
#----------------------------------
#cpptestsrc=test/src/test_main.cpp |
#objtest=test_main.o		   |
#----------------------------------

CXX=g++
CXXFLAGS=-std=c++11 -g -ftest-coverage -fprofile-arcs
LDFLAGS=-lcppunit -lgcov

all:m.out

m.out:$(obj) $(cpptestsrc)
	$(CXX) -o $@ $^ $(LDFLAGS)
$(cpptestsrc):
	(cd test; make)

.PHONY:clean
clean:
	#removed -r flag because we are considering specific files only and no directories
	(cd test; make clean)
	rm -v -f *.gcda *.xml *.o *.out src/*.gcda src/*.o src/*.gcno test/src/*.o test/src/*.gcno 
	
