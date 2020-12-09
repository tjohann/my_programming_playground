/*
  some stuff around struct and padding
 */

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>

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

struct my_struct_d {
	uint32_t a;
	uint64_t b;
} __attribute__((packed));

int
main(void)
{
	puts("\n--------------------------------------------------");
	struct my_struct_a struct_a;
	size_t num_bytes = sizeof(struct_a);
	printf("sizeof struct_a = %ld\n", num_bytes);
	printf("sizeof of a = %ld and b = %ld\n", sizeof(struct_a.a),
		sizeof(struct_a.b));
	printf("address %p from a.a\n", &struct_a.a);
	printf("address %p from a.b\n", &struct_a.b);

	puts("\n--------------------------------------------------");
	struct my_struct_b struct_b;
	struct_b.b = 255;
	num_bytes = sizeof(struct_b);
	printf("sizeof struct_b = %ld\n", num_bytes);
	printf("sizeof of a = %ld and b = %ld\n", sizeof(struct_b.a),
		sizeof(struct_b.b));
	printf("value of b.b = %d\n", struct_b.b);
	printf("address %p from b.a\n", &struct_b.a);
	printf("address %p from b.b\n", &struct_b.b);

	puts("\n--------------------------------------------------");
	struct my_struct_c struct_c;
	struct_c.a = 256;
	num_bytes = sizeof(struct_c);
	memset(&struct_c, 0, num_bytes);
	printf("sizeof struct_c = %ld\n", num_bytes);
	printf("sizeof of a = %ld and b = %ld\n", sizeof(struct_c.a),
		sizeof(struct_c.b));
	printf("value of struct_c.a = %d\n", struct_c.a);
	printf("address %p from c.a\n", &struct_c.a);
	printf("address %p from c.b\n", &struct_c.b);
	printf("address %p from c.a + sizeof c.a \n", &struct_c.a + sizeof(struct_c.a));
	printf("show content of that address: %d\n",
		*(&struct_c.a + sizeof(struct_c.a)));

	puts("\n--------------------------------------------------");
	struct my_struct_d struct_d;
	num_bytes = sizeof(struct_d);
	printf("sizeof struct_d = %ld\n", num_bytes);
	printf("sizeof of a = %ld and b = %ld\n", sizeof(struct_d.a),
		sizeof(struct_d.b));
	printf("address %p from d.a\n", &struct_d.a);
	printf("address %p from d.b\n", &struct_d.b);
	puts("\n--------------------------------------------------");

	return EXIT_SUCCESS;
}
