SRC = $(shell ls *.cpp test/*.cpp)
OBJ = $(SRC:.cpp=.o)
DEP = $(OBJ:.o=.o.dep)

CFLAGS   = $(CXXFLAGS)
CXXFLAGS = -Wall -fPIC -std=c++0x
LDFLAGS  = $(CXXFLAGS)

#===============================================================================
#convenience items for testing and what not:

.PHONY: all clean todolist test test-bitbang test-coroutine

.DEFAULT_GOAL = all
all: libjdd.a test/bitbangtest test/coroutine

clean:
	-rm `find -name "*.o"` `find -name "*.o.dep"` libjdd.a
	-rm test/bitbangtest test/coroutine

todolist:
	grep --color=auto 'TODO' `find`

test: test-bitbang test-coroutine

test-bitbang: test/bitbangtest
	./$<

test-coroutine: test/coroutine
	./$<

#===============================================================================
#recipes:

#for each foo.o include its foo.o.dep
-include $(DEP)

#create lib
libjdd.a: uri.o FtdiWrapper.o FtdiStreamBuf.o FtdiStream.o

#create test program
test/bitbangtest: test/bitbangtest.o

#create test program
test/coroutine: test/coroutine.o

#-------------------------------------------------------------------------------
#generic recipes:

#create program from program.o file (and other object files)
%: %.o
	$(CXX) $(LDFLAGS) -o $@ $^

#generate foo.a from it's dependencies
%.a:
	$(AR) rcs $@ $?

#for any obj.o compile it from its obj.cpp file
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<
	$(CXX) -MM $(CPPFLAGS) -MT $@ -MF $@.dep $<

