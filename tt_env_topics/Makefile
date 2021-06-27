#
# some stuff around ttenv topics
#


.PHONY: all
all:
	@echo "**** see Makefile for relevant build targets ****"

build_stuff: hello_ttenv.c ttenv.c
	gcc -Wall -Wextra -o hello_ttenv ttenv.c hello_ttenv.c -lrt -lpthread

.PHONY: clean
clean:
	rm -f *~
	rm -f .*~
	rm -f hello_ttenv

distclean: clean
