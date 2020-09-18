/*
  see https://www.youtube.com/watch?v=JRyrhsx-L5Y

  gcc -Wall -o hello_2 hello_2.c
  objdump -d hello_2
 */

#include <stdio.h>

int
main(void)
{
	/* the address must be the same as in the objdump output
	   for example:
	   tjohann@echnaton:~/Programming/steve_rostedt_strace_talk$ ./hello_2
	   hello world 0x401112

	   and in objdump_of_hello_2.txt:
	   0000000000401112 <main>:
	   401112:	55                   	push   %rbp
	   ...
	*/
	printf("hello world %p\n", &main);

	return 0;
}
