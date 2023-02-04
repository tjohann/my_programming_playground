/*
 * errornous file ... see what happens
 */

#include <cstdio>
#include <cstdlib>
#include <array>

int main(void)
{
	std::array<int, 2> tmp_2 {0};
	tmp_2[3] = 0x7ffff7b36cebUL; /* access outside bounderies */

	printf("Hello World\n");

	return EXIT_SUCCESS;
}
