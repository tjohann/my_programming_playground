#
# some stuff around notify topics
#


.PHONY: all
all:
	@echo "**** see Makefile for relevant build targets ****"

build_stuff: fanotiy_example hello_poll

fanotiy_example: fanotiy_example.c
	gcc -Wall -Wextra -o fanotiy_example fanotiy_example.c

hello_poll: hello_poll.c
	gcc -Wall -Wextra -o hello_poll hello_poll.c

.PHONY: clean
clean:
	rm -f *~
	rm -f .*~
	rm -f fanotiy_example hello_poll

distclean: clean
