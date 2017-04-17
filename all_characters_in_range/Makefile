SRCS:=$(wildcard *.cpp)
DEPS:=$(SRCS:.cpp=.d)
BINS:=$(SRCS:.cpp=.out)

.PHONY: all
all: $(BINS)

%.out: %.cpp | Makefile
	g++ -MD -Wall -O3 -o "$@" $<

.PHONY: clean
clean:
	rm -fv $(BINS) $(DEPS)

-include $(DEPS)
