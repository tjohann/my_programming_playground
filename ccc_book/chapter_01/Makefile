#
# build
#

CC = /opt/gcc-latest/bin/g++
CFLAGS = -Wall -Wextra -std=c++23

PROG_01 = ex_1_1
OBJ_01 = ex_1_1.o


%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

all: $(PROG_01)

$(PROG_01): $(OBJ_01)
	$(CC) -o $@ $^ -lc


clean:
	rm -rf *~ .*~
	rm -rf *.o
	rm -rf $(PROG_01)

distclean: clean

.PHONY: clean
