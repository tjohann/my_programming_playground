/*
 * Exercise 1-1
 */

#include <stdio.h>
#include <stdlib.h>

int absolute_value(int x)
{
	if (x >= 0)
		return x;
	else
		return -x;
}

int main(void)
{
	int value = -10;

	int abs_value = absolute_value(value);
	printf("The absolute vaule of %d is %d\n", value, abs_value);

	exit(EXIT_SUCCESS);
}
