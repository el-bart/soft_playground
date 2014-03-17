.SECONDARY:

LOGS:=$(wildcard *.log)

GPLS_FULL :=$(LOGS:.log=-full.gpl)
GPLS_BEGIN:=$(LOGS:.log=-begin.gpl)

DATS_FULL :=$(LOGS:.log=-full.dat)
DATS_BEGIN:=$(LOGS:.log=-begin.dat)

IMGS_FULL :=$(LOGS:.log=-full.png)
IMGS_BEGIN:=$(LOGS:.log=-begin.png)

.PHONY: all
all: $(IMGS_FULL) $(IMGS_BEGIN)

%.png: %.gpl %.dat
	gnuplot "$*.gpl"

%-full.gpl: %.log
	sed 's:INPUT:$*-full:g' "template.gpl" > "$@"

%-begin.gpl: %.log
	sed 's:INPUT:$*-begin:g' "template.gpl" > "$@"

%-full.dat: %.log
	grep N "$^" | awk '{ print $$3," ",$$6," ",$$11 }' > "$@"

%-begin.dat: %-full.dat
	head -10 "$^" > "$@"

.PHONY: clean
clean:
	rm -fv $(DATS_FULL) $(DATS_BEGIN)
	rm -fv $(GPLS_FULL) $(GPLS_BEGIN)
	rm -fv $(IMGS_FULL) $(IMGS_BEGIN)
