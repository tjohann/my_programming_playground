#
# wrong memory access
#

.PHONY: all
all:
	@echo "**** see Makefile for relevant build targets ****"

build_stuff: hello_world.cpp
	g++ -Wall -Wextra -o hello_world hello_world.cpp

.PHONY: clean
clean:
	rm -f *~
	rm -f hello_world

distclean: clean
