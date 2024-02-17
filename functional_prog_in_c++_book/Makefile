#
# c++ book "Functional Programming in C++" examples/playground
#

# CFLAGS = -Wall -Wextra -std=c++23 -ggdb3 -pg -DDEBUG=1
CFLAGS = -Wall -Wextra -std=c++23 -ggdb3 -DDEBUG=1
LDLIBS =

.PHONY: all
all:
	@echo "**** see Makefile for relevant build targets ****"

build: hello_world


hello_world: hello_world.cc
	g++ $(CFLAGS) $(LDLIBS) -o $@ hello_world.cc
	objdump -S $@ -a > $@_objdump.txt


.PHONY: clean
clean:
	rm -f *~
	rm -f hello_world


distclean: clean
