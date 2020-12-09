Some stuff around struct padding
================================

The simple examples show the result of the generated code.

```the_structs
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
```
As seen below all 3 structs result in the same size. The reason is that the compiler optimized for a fast access. So it alignes to the native size of the processor.

```output
./struct_padding
sizeof struct_a = 16
sizeof of a = 8 and b = 8
sizeof struct_b = 16
sizeof of a = 8 and b = 1
value of b.b = 255
sizeof struct_c = 16
sizeof of a = 1 and b = 8
value of struct_c.a = 0
```

Important to notice is that, although there`s a lot of additional space between struct_c.a and structc.b, the compiler stays in his type system:

```overrun
struct_c.a = 256;
```
The value of struct_c.a is 0. So the expected overun.


Example with packed struct
--------------------------

The compiler generated code from that struct has the size of 16 bytes, although the summary is only 12 bytes.

```without_packed
struct my_struct {
	uint64_t a;
	uint32_t b;
};

```

```section_without_packed
Disassembly of section .text:

0000000000000000 <main>:
   0:	55                   	push   %rbp
   1:	48 89 e5             	mov    %rsp,%rbp
   4:	48 c7 45 e8 10 00 00 	movq   $0x10,-0x18(%rbp)
   b:	00
   c:	b8 00 00 00 00       	mov    $0x0,%eax
  11:	5d                   	pop    %rbp
  12:	c3                   	retq
```

Next we use the attribute packed to force the packaging of both variables.

```packed
struct my_struct{
	uint64_t a;
	uint32_t b;
} __attribute__((packed));

```

```section_with_packed
Disassembly of section .text:

0000000000000000 <main>:
   0:	55                   	push   %rbp
   1:	48 89 e5             	mov    %rsp,%rbp
   4:	48 c7 45 e8 0c 00 00 	movq   $0xc,-0x18(%rbp)
   b:	00
   c:	b8 00 00 00 00       	mov    $0x0,%eax
  11:	5d                   	pop    %rbp
  12:	c3                   	retq

```

Now the size is 12 bytes. Important to notice is that the packed struct is not cache aligned anymor:
```address_packet
sizeof struct_d = 12
sizeof of a = 8 and b = 4
address 0x7ffdc35b3094 from my_struct.a
address 0x7ffdc35b3098 from my_struct.b

```
For example:
```next_struct
struct my_struct_c {
	uint8_t a;
	uint64_t b;
};
```
results in:
```address_unpacket
sizeof struct_c = 16
sizeof of a = 1 and b = 8
value of struct_c.a = 0
address 0x7ffdc35b30c0 from c.a
address 0x7ffdc35b30c8 from c.b
```
The start address of c.a starts with 0x...c0.
The size of a is 1 byte.
The start address of c.b starts with 0x...c8.
The differenz of between c1 and c8 is filled with padding bytes.

Note that the padding bytes could have any value:
```access_first_padding_byte
sizeof struct_c = 16
sizeof of a = 1 and b = 8
value of struct_c.a = 0
address 0x7ffda5b1c000 from c.a
address 0x7ffda5b1c008 from c.b
address 0x7ffda5b1c001 from c.a + sizeof c.a
show content of that address: 228
```
This shows the it makes sense to clear the struct before usage. So use memset() or bzero() to clear it:
```after_clearing_struct
sizeof struct_c = 16
sizeof of a = 1 and b = 8
value of struct_c.a = 0
address 0x7fffc6f52730 from c.a
address 0x7fffc6f52738 from c.b
address 0x7fffc6f52731 from c.a + sizeof c.a
show content of that address: 0
```


additional stuff
----------------

([TODO](TODO.md))
