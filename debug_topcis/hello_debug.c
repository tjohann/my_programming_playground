/*
 * some stuff around debug topics
 */

#include <stdio.h>

#ifdef __DEBUG__
#define eprintf_l(fmt, args...) do {					\
	fprintf(stdout, "ERROR in file %s@line %d: "			\
		fmt, __FILE__, __LINE__, args);				\
	} while(0)
#define eprintf(fmt, args...) do {					\
	fprintf(stdout, "ERROR in file %s@line %d: "			\
		fmt, __FILE__, __LINE__);				\
	} while(0)
#else
#define eprintf_l(...)
#define eprintf(...)
#endif


int
test(void)
{
#ifdef __DEBUG__
	printf("hello debug with __DEBUG__\n");
	int err = -1;
#else
	printf("hello debug without __DEBUG__\n");
#endif

	eprintf_l("error messge with an error value %d\n", err);
	eprintf("error message without an value\n");

	return 0;
}

int
main(void)
{
	return test();
}
