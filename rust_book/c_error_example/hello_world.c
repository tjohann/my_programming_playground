/*
 * errornous file ... see what happens
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	unsigned long tmp[1];
	tmp[3] = 0x7ffff7b36cebUL; /* access outside bounderies */

	printf("Hello World\n");

	return EXIT_SUCCESS;
}
