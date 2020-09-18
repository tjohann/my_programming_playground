# playground for https://www.youtube.com/watch?v=JRyrhsx-L5Y

MODULES = $(shell ls -d */ | cut -f1 -d'/')

all: hello hello_2
	@echo "done :-)"

hello: hello.c
	gcc -Wall -o hello hello.c
	objdump -d hello > objdump_of_hello.txt

hello_2: hello_2.c
	gcc -Wall -o hello_2 hello_2.c
	objdump -d hello_2 > objdump_of_hello_2.txt

.PHONY: clean
clean:
	rm -f *~
	for dir in $(MODULES); do (cd $$dir && $(MAKE) $@); done
	rm -f hello
	rm -f hello_2

distclean: clean
