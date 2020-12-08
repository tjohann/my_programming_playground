/*
  some stuff around struct and padding
 */

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

struct my_struct {
	uint64_t a;
	uint32_t b;
} __attribute__((packed));

int
main(void)
{
	struct my_struct struct_a;
	size_t num_bytes = sizeof(struct_a);

	return EXIT_SUCCESS;
}
