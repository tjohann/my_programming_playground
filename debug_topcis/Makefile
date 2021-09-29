#
# some stuff around debug topics
#


.PHONY: all
all:
	@echo "**** see Makefile for relevant build targets ****"

build_stuff: hello_debug.c
	gcc -Wall -Wextra -D__DEBUG__ -o hello_debug hello_debug.c
	gcc -Wall -Wextra -o hello_without_debug hello_debug.c

.PHONY: clean
clean:
	rm -f *~
	rm -f .*~
	rm -f hello_debug hello_without_debug

distclean: clean
