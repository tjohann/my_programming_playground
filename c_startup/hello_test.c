/*
  simple hello world example with an test function to see how linker
  handles function signatures
 */

#include <stdio.h>

int test(void)
{
	printf("hello world\n");

	return 0;
}

int main(void)
{
	return test();
}
