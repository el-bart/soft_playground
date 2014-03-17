.SECONDARY:

srcs:=$(filter-out bug.cpp, $(wildcard *.cpp))
bins:=$(srcs:.cpp=.out)

CXX:=g++
#CXX:=g++-4.7
#CXX:=clang++

.PHONY: all
all: $(bins)

%.out: %.cpp Makefile
	$(CXX) -Wall -std=c++11 -O3 -o $@ $*.cpp

.PHONY: clean
clean:
	rm -f $(bins) $(objs)
