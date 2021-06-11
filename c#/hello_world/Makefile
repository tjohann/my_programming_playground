#
# some stuff around time topics
#


.PHONY: all
all:
	@echo "**** see Makefile for relevant build targets ****"

hello_world: hello_world.cs
	mcs hello_world.cs

hello_world_gtk: hello_world_gtk.cs
	mcs hello_world_gtk.cs -pkg:gtk-sharp-2.0

hello_world_winforms: hello_world_winforms.cs
	mcs hello_world_winforms.cs -r:System.Windows.Forms.dll

.PHONY: clean
clean:
	rm -f *~ .*~
	rm -f *.exe

distclean: clean
