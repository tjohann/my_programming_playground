#
# some stuff around time topics
#


.PHONY: all
all:
	@echo "**** see Makefile for relevant build targets ****"

hello_world: hello_01.go
	go build -o ./hello_world hello_01.go

.PHONY: clean
clean:
	rm -f *~ .*~
	rm -f hello_world
	go clean

distclean: clean
