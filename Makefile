#*******************************************************************************
# Written by: Joshua DeWeese(josh.deweese@gmail.com)
# please catch and release
#*******************************************************************************

# additional dirs to search for libs
#LDIRS = ./

# additional dirs to search for header files
#IDIRS = ./

# flags
DEBUG    = -g
CFLAGS   = $(CXXFLAGS)
CXXFLAGS = $(DEBUG) -Wall -fPIC
LDFLAGS  = $(CXXFLAGS)

# other
.DEFAULT_GOAL = all
#VPATH = ./src/ ./test/
SRC = $(shell ls *.cpp test/*.cpp)
OBJ = $(SRC:.cpp=.o)
DEP = $(OBJ:.o=.o.dep)

#===============================================================================
#convenience items for testing and what not:

.PHONY: all clean todolist test

all: libjdd.a

clean:
	-rm $(OBJ) $(DEP) libjdd.a test/bitbangtest

todolist:
	grep --color=auto 'TODO' `find`

test: test-bitbang

test-bitbang: test/bitbangtest
	./$<

#===============================================================================
#recipes:

#for each foo.o include its foo.o.dep
#include $(patsubst %.o, %.o.dep,  $(wildcard *.o))
-include $(DEP)

#create lib
libjdd.a: bitbang.o uri.o FtdiWrapper.o FtdiStreamBuf.o FtdiStream.o

#create test program
test/bitbangtest: test/bitbangtest.o libjdd.a
	$(CXX) $(LDFLAGS) -o $@ $^

#-------------------------------------------------------------------------------
#generic recipes:

#create program from program.o file (and other object files)
#%: %.o
#	$(CXX) $(LDFLAGS) -o $@ $^

#generate foo.a from it's dependencies
%.a:
	$(AR) rcs $@ $?

#for any obj.o compile it from its obj.cpp file
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<
	$(CXX) -MM $(CPPFLAGS) -MT $@ -MF $@.dep $<

