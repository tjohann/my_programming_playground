#
# playground wang os programming book
#

MODULES = $(shell ls -d */ | cut -f1 -d'/')

MY_PREFIX=arm-none-eabi

.PHONY: all
all:	ts.s

	$(MY_PREFIX)-as -o ts.o ts.s
	$(MY_PREFIX)-ld -Tt.ld -o t.elf ts.o
	$(MY_PREFIX)-objcopy -O binary t.elf t.bin

.PHONY: show_scetions
show_scetions: t.elf
	$(MY_PREFIX)-nm t.elf

.PHONY: run
run: t.bin
	qemu-system-arm -M versatilepb -kernel t.bin -nographic -serial /dev/null


.PHONY: clean
clean:
	rm -f *~
	rm -f *.elf
	rm -f *o
	for dir in $(MODULES); do (cd $$dir && $(MAKE) $@); done

distclean: clean
