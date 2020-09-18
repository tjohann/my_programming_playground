some stuff around steves strace and co talk@youtube
===================================================

https://www.youtube.com/watch?v=JRyrhsx-L5Y


following the talk
------------------

gcc -save-temps -Wall -Wextra -o hello hello.c
objdump -d hello

ELF ... executable and linkable format :-) ...


gcc -save-temps -Wall -Wextra -o hello_2 hello_2.c
..


With -save-temps we will preserve the temporary files. Also the .o file is the output before linkage.

See hello_ccp and hello.cc for an c++ example.

additional stuff
----------------

([TODO](TODO.md))
