c and cpp startup analysis
==========================

Some analysis of the simple hello_world program.


build build related stuff
-------------------------

	make build_stuff &> output_build.txt

See output_build.txt for content.
For example the default configs used when build without any additional argumens like -Wall.
Also the C runtime libraries (crt\*) and the gcc specific libs (lgcc\_s) are shown.
See also https://gcc.gnu.org/onlinedocs/gccint/Collect2.html for more info about linker topics at startup.


collect2
--------

- Collect2 arrange the call to various init functions during startup of an application
- __main (the constructors) is what is called before main() provided by the application (the symbols are provided by -lgcc)

- .ctors and .dtors section ... depending on the architecture different operations can occure ... not all architectures support all sections
- crti.o (prologue in __init) and crtn.o (epilogue) are provided by the os or for some architecures/platforms from glibc
- .ctrbegin for .init and .crtend for .fini sections


libgcc.a and libgcc_s.so.1
--------------------------

- provide functions for operations which can not be perform directly by the target processor
- mostly arithmetic operations


build linking related stuff
---------------------------

	make linker_stuff

See `output_objdump.txt` and `output_final_objdump.txt` for content.


generation of output_objdump.txt file
-------------------------------------

The object file is generated with -c argument -> do not run linker.


Output **without** linker run
-----------------------------

```hello_test.o
hello_test.o:     file format elf64-x86-64


Disassembly of section .text:

0000000000000000 <test>:
   0:	55                   	push   %rbp
   1:	48 89 e5             	mov    %rsp,%rbp
   4:	48 8d 3d 00 00 00 00 	lea    0x0(%rip),%rdi        # b <test+0xb>
   b:	e8 00 00 00 00       	callq  10 <test+0x10>
  10:	b8 00 00 00 00       	mov    $0x0,%eax
  15:	5d                   	pop    %rbp
  16:	c3                   	retq

0000000000000017 <main>:
  17:	55                   	push   %rbp
  18:	48 89 e5             	mov    %rsp,%rbp
  1b:	e8 00 00 00 00       	callq  20 <main+0x9>
  20:	5d                   	pop    %rbp
  21:	c3                   	retq

So this is the generated code with the 2 functions main and test. All addresses are relativ and not absolut like after running the linker.
```

Output **with** linker run
--------------------------

```hello_test
hello_test:     file format elf64-x86-64


Disassembly of section .init:

0000000000001000 <_init>:
    1000:	48 83 ec 08          	sub    $0x8,%rsp
    1004:	48 8b 05 dd 2f 00 00 	mov    0x2fdd(%rip),%rax        # 3fe8 <__gmon_start__>
    100b:	48 85 c0             	test   %rax,%rax
    100e:	74 02                	je     1012 <_init+0x12>
    1010:	ff d0                	callq  *%rax
    1012:	48 83 c4 08          	add    $0x8,%rsp
    1016:	c3                   	retq

Disassembly of section .plt:

0000000000001020 <.plt>:
    1020:	ff 35 e2 2f 00 00    	pushq  0x2fe2(%rip)        # 4008 <_GLOBAL_OFFSET_TABLE_+0x8>
    1026:	ff 25 e4 2f 00 00    	jmpq   *0x2fe4(%rip)        # 4010 <_GLOBAL_OFFSET_TABLE_+0x10>
    102c:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000001030 <puts@plt>:
    1030:	ff 25 e2 2f 00 00    	jmpq   *0x2fe2(%rip)        # 4018 <puts@GLIBC_2.2.5>
    1036:	68 00 00 00 00       	pushq  $0x0
    103b:	e9 e0 ff ff ff       	jmpq   1020 <.plt>

Disassembly of section .plt.got:

0000000000001040 <__cxa_finalize@plt>:
    1040:	ff 25 b2 2f 00 00    	jmpq   *0x2fb2(%rip)        # 3ff8 <__cxa_finalize@GLIBC_2.2.5>
    1046:	66 90                	xchg   %ax,%ax

Disassembly of section .text:

0000000000001050 <_start>:
    1050:	31 ed                	xor    %ebp,%ebp
    1052:	49 89 d1             	mov    %rdx,%r9
    1055:	5e                   	pop    %rsi
    1056:	48 89 e2             	mov    %rsp,%rdx
    1059:	48 83 e4 f0          	and    $0xfffffffffffffff0,%rsp
    105d:	50                   	push   %rax
    105e:	54                   	push   %rsp
    105f:	4c 8d 05 5a 01 00 00 	lea    0x15a(%rip),%r8        # 11c0 <__libc_csu_fini>
    1066:	48 8d 0d f3 00 00 00 	lea    0xf3(%rip),%rcx        # 1160 <__libc_csu_init>
    106d:	48 8d 3d d8 00 00 00 	lea    0xd8(%rip),%rdi        # 114c <main>
    1074:	ff 15 66 2f 00 00    	callq  *0x2f66(%rip)        # 3fe0 <__libc_start_main@GLIBC_2.2.5>
    107a:	f4                   	hlt
    107b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000001080 <deregister_tm_clones>:
    1080:	48 8d 3d a9 2f 00 00 	lea    0x2fa9(%rip),%rdi        # 4030 <__TMC_END__>
    1087:	48 8d 05 a2 2f 00 00 	lea    0x2fa2(%rip),%rax        # 4030 <__TMC_END__>
    108e:	48 39 f8             	cmp    %rdi,%rax
    1091:	74 15                	je     10a8 <deregister_tm_clones+0x28>
    1093:	48 8b 05 3e 2f 00 00 	mov    0x2f3e(%rip),%rax        # 3fd8 <_ITM_deregisterTMCloneTable>
    109a:	48 85 c0             	test   %rax,%rax
    109d:	74 09                	je     10a8 <deregister_tm_clones+0x28>
    109f:	ff e0                	jmpq   *%rax
    10a1:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    10a8:	c3                   	retq
    10a9:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

00000000000010b0 <register_tm_clones>:
    10b0:	48 8d 3d 79 2f 00 00 	lea    0x2f79(%rip),%rdi        # 4030 <__TMC_END__>
    10b7:	48 8d 35 72 2f 00 00 	lea    0x2f72(%rip),%rsi        # 4030 <__TMC_END__>
    10be:	48 29 fe             	sub    %rdi,%rsi
    10c1:	48 89 f0             	mov    %rsi,%rax
    10c4:	48 c1 ee 3f          	shr    $0x3f,%rsi
    10c8:	48 c1 f8 03          	sar    $0x3,%rax
    10cc:	48 01 c6             	add    %rax,%rsi
    10cf:	48 d1 fe             	sar    %rsi
    10d2:	74 14                	je     10e8 <register_tm_clones+0x38>
    10d4:	48 8b 05 15 2f 00 00 	mov    0x2f15(%rip),%rax        # 3ff0 <_ITM_registerTMCloneTable>
    10db:	48 85 c0             	test   %rax,%rax
    10de:	74 08                	je     10e8 <register_tm_clones+0x38>
    10e0:	ff e0                	jmpq   *%rax
    10e2:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)
    10e8:	c3                   	retq
    10e9:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

00000000000010f0 <__do_global_dtors_aux>:
    10f0:	80 3d 39 2f 00 00 00 	cmpb   $0x0,0x2f39(%rip)        # 4030 <__TMC_END__>
    10f7:	75 2f                	jne    1128 <__do_global_dtors_aux+0x38>
    10f9:	55                   	push   %rbp
    10fa:	48 83 3d f6 2e 00 00 	cmpq   $0x0,0x2ef6(%rip)        # 3ff8 <__cxa_finalize@GLIBC_2.2.5>
    1101:	00
    1102:	48 89 e5             	mov    %rsp,%rbp
    1105:	74 0c                	je     1113 <__do_global_dtors_aux+0x23>
    1107:	48 8b 3d 1a 2f 00 00 	mov    0x2f1a(%rip),%rdi        # 4028 <__dso_handle>
    110e:	e8 2d ff ff ff       	callq  1040 <__cxa_finalize@plt>
    1113:	e8 68 ff ff ff       	callq  1080 <deregister_tm_clones>
    1118:	c6 05 11 2f 00 00 01 	movb   $0x1,0x2f11(%rip)        # 4030 <__TMC_END__>
    111f:	5d                   	pop    %rbp
    1120:	c3                   	retq
    1121:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    1128:	c3                   	retq
    1129:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000001130 <frame_dummy>:
    1130:	e9 7b ff ff ff       	jmpq   10b0 <register_tm_clones>

0000000000001135 <test>:
    1135:	55                   	push   %rbp
    1136:	48 89 e5             	mov    %rsp,%rbp
    1139:	48 8d 3d c4 0e 00 00 	lea    0xec4(%rip),%rdi        # 2004 <_IO_stdin_used+0x4>
    1140:	e8 eb fe ff ff       	callq  1030 <puts@plt>
    1145:	b8 00 00 00 00       	mov    $0x0,%eax
    114a:	5d                   	pop    %rbp
    114b:	c3                   	retq

000000000000114c <main>:
    114c:	55                   	push   %rbp
    114d:	48 89 e5             	mov    %rsp,%rbp
    1150:	e8 e0 ff ff ff       	callq  1135 <test>
    1155:	5d                   	pop    %rbp
    1156:	c3                   	retq
    1157:	66 0f 1f 84 00 00 00 	nopw   0x0(%rax,%rax,1)
    115e:	00 00

0000000000001160 <__libc_csu_init>:
    1160:	41 57                	push   %r15
    1162:	4c 8d 3d 7f 2c 00 00 	lea    0x2c7f(%rip),%r15        # 3de8 <__frame_dummy_init_array_entry>
    1169:	41 56                	push   %r14
    116b:	49 89 d6             	mov    %rdx,%r14
    116e:	41 55                	push   %r13
    1170:	49 89 f5             	mov    %rsi,%r13
    1173:	41 54                	push   %r12
    1175:	41 89 fc             	mov    %edi,%r12d
    1178:	55                   	push   %rbp
    1179:	48 8d 2d 70 2c 00 00 	lea    0x2c70(%rip),%rbp        # 3df0 <__do_global_dtors_aux_fini_array_entry>
    1180:	53                   	push   %rbx
    1181:	4c 29 fd             	sub    %r15,%rbp
    1184:	48 83 ec 08          	sub    $0x8,%rsp
    1188:	e8 73 fe ff ff       	callq  1000 <_init>
    118d:	48 c1 fd 03          	sar    $0x3,%rbp
    1191:	74 1b                	je     11ae <__libc_csu_init+0x4e>
    1193:	31 db                	xor    %ebx,%ebx
    1195:	0f 1f 00             	nopl   (%rax)
    1198:	4c 89 f2             	mov    %r14,%rdx
    119b:	4c 89 ee             	mov    %r13,%rsi
    119e:	44 89 e7             	mov    %r12d,%edi
    11a1:	41 ff 14 df          	callq  *(%r15,%rbx,8)
    11a5:	48 83 c3 01          	add    $0x1,%rbx
    11a9:	48 39 dd             	cmp    %rbx,%rbp
    11ac:	75 ea                	jne    1198 <__libc_csu_init+0x38>
    11ae:	48 83 c4 08          	add    $0x8,%rsp
    11b2:	5b                   	pop    %rbx
    11b3:	5d                   	pop    %rbp
    11b4:	41 5c                	pop    %r12
    11b6:	41 5d                	pop    %r13
    11b8:	41 5e                	pop    %r14
    11ba:	41 5f                	pop    %r15
    11bc:	c3                   	retq
    11bd:	0f 1f 00             	nopl   (%rax)

00000000000011c0 <__libc_csu_fini>:
    11c0:	c3                   	retq

Disassembly of section .fini:

00000000000011c4 <_fini>:
    11c4:	48 83 ec 08          	sub    $0x8,%rsp
    11c8:	48 83 c4 08          	add    $0x8,%rsp
    11cc:	c3                   	retq
```

So this is the generated code with the 2 functions main and test. All addresses are absolut because the linker runs and links/generates all additional functions needed to run the application on linux.


Addtional analysis of the results
---------------------------------


```start
0000000000001050 <_start>:
    1050:	31 ed                	xor    %ebp,%ebp
    1052:	49 89 d1             	mov    %rdx,%r9
    1055:	5e                   	pop    %rsi
    1056:	48 89 e2             	mov    %rsp,%rdx
    1059:	48 83 e4 f0          	and    $0xfffffffffffffff0,%rsp
    105d:	50                   	push   %rax
    105e:	54                   	push   %rsp
    105f:	4c 8d 05 5a 01 00 00 	lea    0x15a(%rip),%r8        # 11c0 <__libc_csu_fini>
    1066:	48 8d 0d f3 00 00 00 	lea    0xf3(%rip),%rcx        # 1160 <__libc_csu_init>
    106d:	48 8d 3d d8 00 00 00 	lea    0xd8(%rip),%rdi        # 114c <main>
    1074:	ff 15 66 2f 00 00    	callq  *0x2f66(%rip)        # 3fe0 <__libc_start_main@GLIBC_2.2.5>
    107a:	f4                   	hlt
    107b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)
```

The application loader from Linux calls _start, which then calls the libc start function (`__libc_start_main`). Note that the libc init and fini addresses loaded (called by `__libc_start_main`). See also `glibc/csu/libc-start.c`.

```libc_start_main
// SNIP
define LIBC_START_MAIN __libc_start_main
// SNIP
STATIC int LIBC_START_MAIN (int (*main) (int, char **, char **
                                         MAIN_AUXVEC_DECL),
                            int argc,
                            char **argv,
#ifdef LIBC_START_MAIN_AUXVEC_ARG
                            ElfW(auxv_t) *auxvec,
#endif
                            __typeof (main) init,
                            void (*fini) (void),
                            void (*rtld_fini) (void),
                            void *stack_end)
     __attribute__ ((noreturn));
// SNIP
```

To see the AUXVEC content you can set the env variable LD_SHOW_AUXV to 1.

```auxvec
LD_SHOW_AUXV=1 ./minimal_prog
AT_SYSINFO_EHDR:      0x7ffe2dd37000
AT_HWCAP:             bfebfbff
AT_PAGESZ:            4096
AT_CLKTCK:            100
AT_PHDR:              0x55898cd87040
AT_PHENT:             56
AT_PHNUM:             11
AT_BASE:              0x7fc67ea31000
AT_FLAGS:             0x0
AT_ENTRY:             0x55898cd88040
AT_UID:               1000
AT_EUID:              1000
AT_GID:               1000
AT_EGID:              1000
AT_SECURE:            0
AT_RANDOM:            0x7ffe2dc30b09
AT_HWCAP2:            0x2
AT_EXECFN:            ./minimal_prog
AT_PLATFORM:          x86_64

```


additional stuff
----------------

([TODO](TODO.md))
