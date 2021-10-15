#
# playground around json-c
#
# starting points:
# - https://linuxprograms.wordpress.com/2010/05/20/json-c-libjson-tutorial/
#

MODULES = $(shell ls -d */ | cut -f1 -d'/')

.PHONY: all
all:
	@echo "done :-)"

.PHONY: clean
clean:
	rm -f *~
	for dir in $(MODULES); do (cd $$dir && $(MAKE) $@); done

distclean: clean
