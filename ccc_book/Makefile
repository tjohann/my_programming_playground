#
# c++ book "C++ Crash Course" examples/playground
#

MODULES = $(shell ls -d */ | cut -f1 -d'/')

CC = /opt/gcc-latest/bin/g++
CFLAGS = -Wall -Wextra -std=c++23 -O2

PROG_01 = hello_world
OBJ_01 = hello_world.o

PROG_02 = pre_listing_01
OBJ_02 = pre_listing_01.o

%.o: %.cc
	$(CC) -c -o $@ $< $(CFLAGS)
	$(CC) -S $< $(CFLAGS)


all: $(PROG_01) $(PROG_02)

$(PROG_01): $(OBJ_01)
	$(CC) -o $@ $^ -lc

$(PROG_02): $(OBJ_02)
	$(CC) -o $@ $^ -lc
	objdump -S $@ -a > $@_objdump.txt

clean:
	rm -rf *~ .*~
	rm -rf *.o
	rm -rf *.s
	rm -rf $(PROG_01)
	rm -rf $(PROG_02)
	for dir in $(MODULES); do (cd $$dir && $(MAKE) $@); done

distclean: clean

.PHONY: clean
