SRCS:=$(wildcard *.cpp)
APPS:=$(SRCS:.cpp=.out)

CXX:=clang++-5.0
CXXFLAGS+=-std=c++1z
CXXFLAGS+=-Werror -Wall
CXXFLAGS+=-g3 -ggdb
CXXFLAGS+=-fcoroutines-ts -stdlib=libc++

.PHONY: all
all: $(APPS)

%.out: %.cpp Makefile
	$(CXX) $(CXXFLAGS) -o "$@" "$<"

.PHONY: clean
clean:
	rm -fv $(APPS)
