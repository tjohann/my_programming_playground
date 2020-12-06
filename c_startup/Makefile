#
# c startup analysis
#


.PHONY: all
all:
	@echo "**** see Makefile for relevant build targets ****"

build_stuff: hello_world.c
	gcc -v -o hello_world hello_world.c

linker_stuff: hello_test.c
	gcc -c hello_test.c
	objdump -d hello_test.o > output_objdump.txt
	@echo "**** now build all ****"
	gcc -Wall -Wextra -o hello_test hello_test.c
	objdump -d hello_test > output_final_objdump.txt

minimal_stuff: minimal_prog.c
	gcc -c minimal_prog.c
	objdump -d minimal_prog.o > output_minimal_objdump.txt
	@echo "**** now build all ****"
	gcc -Wall -Wextra -o minimal_prog minimal_prog.c
	objdump -d minimal_prog > output_final_minimal_objdump.txt

.PHONY: clean
clean:
	rm -f *~
	rm -f hello_world
	rm -f hello_world.o
	rm -f hello_test
	rm -f hello_test.o
	rm -f minimal_prog
	rm -f minimal_prog.o

distclean: clean
