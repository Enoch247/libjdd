CFLAGS   = $(CXXFLAGS)
CXXFLAGS = -Wall -std=c++0x
LDFLAGS  = $(CXXFLAGS)

VPATH = ../

#===============================================================================
#convenience items for testing and what not:

.PHONY: all clean todolist test test-bitbang test-coroutine

.DEFAULT_GOAL = all
all: bitbangtest coroutine others

clean:
	-rm `find -name "*.o"` `find -name "*.o.dep"`
	-rm bitbangtest coroutine

todolist:
	grep --color=auto 'TODO' `find`

test: test-bitbang test-coroutine

test-bitbang: bitbangtest
	./$<

test-coroutine: coroutine
	./$<

#===============================================================================
#recipes:

#for each foo.o include its foo.o.dep
-include *.dep
-include ../*.dep

#create test program
bitbangtest: bitbangtest.o

#create test program
coroutine: coroutine.o

#compile everthing else just to test syntax
.PHONY: others
others: uri.o FtdiStreamBuf.o FtdiStream.o FtdiWrapper.o

#-------------------------------------------------------------------------------
#generic recipes:

#create program from program.o file (and other object files)
%: %.o
	$(CXX) $(LDFLAGS) -o $@ $^

#for any obj.o compile it from its obj.cpp file
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<
	$(CXX) -MM $(CPPFLAGS) -MT $@ -MF $@.dep $<

