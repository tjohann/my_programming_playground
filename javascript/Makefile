#
# playground around cgroups
#

MODULES = $(shell ls -d */ | cut -f1 -d'/')

.PHONY: all
all:
	@echo "done :-)"

build: example.js
	js102 -w example.js

.PHONY: clean
clean:
	rm -f *~
	for dir in $(MODULES); do (cd $$dir && $(MAKE) $@); done

distclean: clean
