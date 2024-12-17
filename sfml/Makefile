#
# Beginning C++ Game Programming book
#

MODULES = $(shell ls -d */ | cut -f1 -d'/')

CC = g++
CFLAGS = -Wall -Wextra `pkg-config --cflags sfml-all`
LIBS = `pkg-config --libs sfml-all`

PROG_01 = hello_world
OBJ_01 = hello_world.o

%.o: %.cc
	$(CC) -c -o $@ $< $(CFLAGS)
	$(CC) -S $< $(CFLAGS)


all: $(PROG_01) $(PROG_02)

$(PROG_01): $(OBJ_01)
	$(CC) -o $@ $^ -lc $(LIBS)


clean:
	rm -rf *~ .*~
	rm -rf *.o
	rm -rf *.s
	rm -rf $(PROG_01)
	for dir in $(MODULES); do (cd $$dir && $(MAKE) $@); done

distclean: clean

.PHONY: clean
