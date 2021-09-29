# my simple programming playground

MODULES = $(shell ls -d */ | cut -f1 -d'/')

.PHONY: all
all:
	@echo "Pls go to the different folders, see also README.md"
	@echo "Cheers :-)"

.PHONY: clean
clean:
	rm -f *~
	for dir in $(MODULES); do (cd $$dir && $(MAKE) $@); done

distclean: clean
