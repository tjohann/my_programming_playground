/*
 * some stuff around time topics
 */

#include <stdio.h>
#include <time.h>

int
test(void)
{
	time_t t = time(NULL);
	printf("hello seconds since EPOCH -> %ld\n", t);

	return 0;
}

int
main(void)
{
	return test();
}
