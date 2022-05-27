	.file	"sseTest.c"
	.intel_syntax noprefix
	.text
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC6:
	.string	"|%g %g| * |%g %g| = |%g %g|\n"
.LC7:
	.string	"|%g %g|   |%g %g|   |%g %g|\n"
	.section	.text.startup,"ax",@progbits
	.p2align 4
	.globl	main
	.type	main, @function
main:
.LFB5548:
	.cfi_startproc
	endbr64
	sub	rsp, 120
	.cfi_def_cfa_offset 128
	pxor	xmm6, xmm6
	movsd	xmm1, QWORD PTR .LC2[rip]
	movsd	xmm10, QWORD PTR .LC0[rip]
	mov	rax, QWORD PTR fs:40
	mov	QWORD PTR 104[rsp], rax
	xor	eax, eax
	mov	rax, QWORD PTR .LC3[rip]
	movsd	xmm8, QWORD PTR .LC1[rip]
	mov	QWORD PTR 64[rsp], 0x000000000
	movsd	QWORD PTR 48[rsp], xmm1
	pxor	xmm9, xmm9
	lea	rsi, .LC6[rip]
	mov	edi, 1
	mov	QWORD PTR 56[rsp], rax
	movapd	xmm0, XMMWORD PTR 48[rsp]
	movapd	xmm3, xmm9
	mov	eax, 6
	movsd	QWORD PTR 32[rsp], xmm10
	movapd	xmm2, xmm0
	movsd	QWORD PTR 40[rsp], xmm8
	movapd	xmm7, XMMWORD PTR 32[rsp]
	addpd	xmm0, xmm0
	mov	QWORD PTR 72[rsp], 0x000000000
	mulpd	xmm2, xmm6
	mov	QWORD PTR 80[rsp], 0x000000000
	mulpd	xmm6, XMMWORD PTR 32[rsp]
	mulpd	xmm7, XMMWORD PTR .LC5[rip]
	mov	QWORD PTR 88[rsp], 0x000000000
	addpd	xmm7, XMMWORD PTR 64[rsp]
	addpd	xmm6, XMMWORD PTR 80[rsp]
	addpd	xmm7, xmm2
	addpd	xmm6, xmm0
	movapd	xmm2, xmm1
	movapd	xmm0, xmm10
	movapd	xmm5, xmm6
	movapd	xmm4, xmm7
	movaps	XMMWORD PTR 16[rsp], xmm6
	movaps	XMMWORD PTR [rsp], xmm7
	call	__printf_chk@PLT
	movapd	xmm6, XMMWORD PTR 16[rsp]
	movapd	xmm7, XMMWORD PTR [rsp]
	pxor	xmm9, xmm9
	mov	rax, QWORD PTR .LC1[rip]
	movapd	xmm2, xmm9
	mov	edi, 1
	lea	rsi, .LC7[rip]
	unpckhpd	xmm6, xmm6
	unpckhpd	xmm7, xmm7
	movq	xmm8, rax
	movq	xmm3, rax
	mov	rax, QWORD PTR .LC3[rip]
	movapd	xmm5, xmm6
	movapd	xmm4, xmm7
	movapd	xmm0, xmm8
	movq	xmm1, rax
	mov	eax, 6
	call	__printf_chk@PLT
	mov	rax, QWORD PTR 104[rsp]
	xor	rax, QWORD PTR fs:40
	jne	.L5
	xor	eax, eax
	add	rsp, 120
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	ret
.L5:
	.cfi_restore_state
	call	__stack_chk_fail@PLT
	.cfi_endproc
.LFE5548:
	.size	main, .-main
	.section	.rodata.cst8,"aM",@progbits,8
	.align 8
.LC0:
	.long	0
	.long	1072693248
	.align 8
.LC1:
	.long	0
	.long	1073741824
	.align 8
.LC2:
	.long	0
	.long	1074266112
	.align 8
.LC3:
	.long	0
	.long	1074790400
	.section	.rodata.cst16,"aM",@progbits,16
	.align 16
.LC5:
	.long	0
	.long	1074266112
	.long	0
	.long	1074266112
	.ident	"GCC: (Ubuntu 9.4.0-1ubuntu1~20.04) 9.4.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:
