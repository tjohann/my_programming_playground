/*
  some stuff around struct and padding
 */

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

struct my_struct_a {
	uint64_t a;
	uint64_t b;
};

struct my_struct_b {
	uint64_t a;
	uint8_t b;
};

struct my_struct_c {
	uint8_t a;
	uint64_t b;
};

int
main(void)
{
	struct my_struct_a struct_a;
	size_t num_bytes = sizeof(struct_a);
	printf("sizeof struct_a = %ld\n", num_bytes);
	printf("sizeof of a = %ld and b = %ld\n", sizeof(struct_a.a),
		sizeof(struct_a.b));

	struct my_struct_b struct_b;
	struct_b.b = 255;
	num_bytes = sizeof(struct_b);
	printf("sizeof struct_b = %ld\n", num_bytes);
	printf("sizeof of a = %ld and b = %ld\n", sizeof(struct_b.a),
		sizeof(struct_b.b));
	printf("value of b.b = %d\n", struct_b.b);

	struct my_struct_c struct_c;
	struct_c.a = 256;
	num_bytes = sizeof(struct_c);
	printf("sizeof struct_c = %ld\n", num_bytes);
	printf("sizeof of a = %ld and b = %ld\n", sizeof(struct_c.a),
		sizeof(struct_c.b));
	printf("value of struct_c.a = %d\n", struct_c.a);

	return EXIT_SUCCESS;
}
