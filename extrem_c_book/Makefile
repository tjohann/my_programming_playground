#
# playground system programming book
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
