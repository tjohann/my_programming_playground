some stuff around structs padding
=================================

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


example with packed struct
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

Now we use the attribute packed to force the packaging of both variables.

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

Now the size is 12 bytes.



additional stuff
----------------

([TODO](TODO.md))
