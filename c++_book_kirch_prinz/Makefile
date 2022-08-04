#
# c++ book "C++ lernen und professionell anwenden" examples/playground
#

.PHONY: all
all:
	@echo "**** see Makefile for relevant build targets ****"

build_stuff: hello_world.cc
	clang++ -Wall -Wextra -o hello_world hello_world.cc

.PHONY: clean
clean:
	rm -f *~
	rm -f hello_world


distclean: clean
