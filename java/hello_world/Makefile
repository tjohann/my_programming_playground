#
# some stuff around time topics
#


.PHONY: all
all:
	@echo "**** see Makefile for relevant build targets ****"

hello_01: hello_01.java
	javac -verbose hello_01.java
	java hello_01
#	java -verbose hello_01

.PHONY: clean
clean:
	rm -f *~ .*~
	rm -f hello_01
	rm -f hello_01.class

distclean: clean
