/*
 * Example from prolog
 * Side xxxviii
 */

#include <cstdio>
#include <cstdlib>

constexpr int isqrt(int n)
{
	int i = 0;
	while (i * i < n)
		++i;

	return i - (i * i !=n);
}


int main(void)
{

	/* the constexpr is not really needed for the definition of x */
	constexpr int x = isqrt(1764); /**/

	printf("%d\n", x);

	exit(EXIT_SUCCESS);
}
