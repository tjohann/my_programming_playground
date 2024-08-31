first example (side 17 ff)
==========================



Qemu topics
-----------

arm-none-eabi-nm t.elf
0001001c d result
00011020 D stack_top
00010000 T start
00010014 t stop

start qemu:

	qemu-system-arm -M versatilepb -kernel t.bin -nographic -serial /dev/null

show register:

	info register

show value of result:

	xp /wd 0x1001C




useful links
------------

link to toolchain: https://developer.arm.com/downloads/-/arm-gnu-toolchain-downloads
