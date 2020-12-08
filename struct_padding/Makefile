#
# playground around struct padding
#

all: struct_padding.c
	gcc -Wall -Wextra -o struct_padding struct_padding.c
	objdump -d struct_padding > output_objdump.txt
	@echo "build minimal version"
	gcc -c struct_padding_minimal.c
	objdump -d struct_padding_minimal.o > output_objdump_minimal.txt

.PHONY: clean
clean:
	rm -f *~
	rm -f struct_padding
	rm -f struct_padding_minimal

distclean: clean
