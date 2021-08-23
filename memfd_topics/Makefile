#
# some stuff around memfd topics
#


.PHONY: all
all:
	@echo "**** see Makefile for relevant build targets ****"

build_stuff: get_seals.c memfd_create.c
	gcc -Wall -Wextra -o get_seals get_seals.c
	gcc -Wall -Wextra -o memfd_create memfd_create.c

.PHONY: clean
clean:
	rm -f *~
	rm -f .*~
	rm -f memfd_create
	rm -f get_seals

distclean: clean
