#
# playground for https://www.youtube.com/watch?v=JRyrhsx-L5Y
#

MODULES = $(shell ls -d */ | cut -f1 -d'/')

all: hello hello_2 hello_cpp
	@echo "done :-)"

hello: hello.c
	gcc -save-temps --std=c18 -Wall -Wextra  -o hello hello.c
	objdump -d hello > objdump_of_hello.txt

hello_cpp: hello_cpp.cc
	g++ -save-temps --std=c++17 -Wall -Wextra  -o hello_cpp hello_cpp.cc
	objdump -d hello_cpp > objdump_of_hello_cpp.txt

hello_2: hello_2.c
	gcc -save-temps --std=c18 -Wall -Wextra -o hello_2 hello_2.c
	objdump -d hello_2 > objdump_of_hello_2.txt

.PHONY: clean
clean:
	rm -f *~
	rm -f *.i
	rm -f *.ii
	rm -f *.o
	rm -f *.s
	for dir in $(MODULES); do (cd $$dir && $(MAKE) $@); done
	rm -f hello
	rm -f hello_2
	rm -f hello_cpp

distclean: clean
