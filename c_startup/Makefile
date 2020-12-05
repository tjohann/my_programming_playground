# c and cpp startup analysis
#

MODULES = $(shell ls -d */ | cut -f1 -d'/')

.PHONY: all
all:
	gcc -v -o hello_world hello_world.c

.PHONY: clean
clean:
	rm -f *~
	for dir in $(MODULES); do (cd $$dir && $(MAKE) $@); done

distclean: clean
