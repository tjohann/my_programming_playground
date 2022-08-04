some stuff around steves strace and co talk@youtube
===================================================

Note: output files are generated on a void-linux system (AMD64)

https://www.youtube.com/watch?v=JRyrhsx-L5Y


following the talk
------------------

gcc -save-temps -Wall -Wextra -o hello hello.c
objdump -d hello

ELF ... executable and linkable format :-) ...


gcc -save-temps -Wall -Wextra -o hello_2 hello_2.c
..


With -save-temps we will preserve the temporary files. Also the .o file is the output before linkage.




objdump stuff
-------------

Sourcefiles: hello.c and hello_2.c

See objdump_of_hello*.txt for the different opjdump outputs. Important is that there`s a lot of additional code added to make that simple program work. For a baremetal objdump for a simple addition, you can take a look at https://github.com/tjohann/my_eos_and_rtos_playground/tree/master/src_qemu/setup_environment . The file objdump_main.txt there has less than 20 lines of objdump output.

Also to note is, that gcc automatically does optimization. For example see the comments in objdump_of_hello_with_comments.txt . Gcc replaces our printf call with a puts call because there no addtional arguments. Compere objdump_of_hello.txt with objdump_of_hello_2.txt to see the difference when we add a argument (in this case the address of main() ).

See hello_ccp.cc for an c++ example.


additional stuff
----------------

([TODO](TODO.md))
