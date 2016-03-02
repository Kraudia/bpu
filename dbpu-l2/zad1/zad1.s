	.file	"zad1.c"
	.text
	.globl	_Z6strStrPcS_
	.type	_Z6strStrPcS_, @function
_Z6strStrPcS_:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -40(%rbp)
	movq	%rsi, -48(%rbp)
	movq	-48(%rbp), %rax
	movzbl	(%rax), %eax
	testb	%al, %al
	jne	.L2
	movq	-40(%rbp), %rax
	jmp	.L3
.L2:
	movq	-40(%rbp), %rax
	movzbl	(%rax), %eax
	testb	%al, %al
	jne	.L4
	movl	$0, %eax
	jmp	.L3
.L4:
	movq	-40(%rbp), %rax
	movq	%rax, -24(%rbp)
	jmp	.L5
.L10:
	movq	-24(%rbp), %rax
	movq	%rax, -16(%rbp)
	movq	-48(%rbp), %rax
	movq	%rax, -8(%rbp)
	jmp	.L6
.L8:
	addq	$1, -16(%rbp)
	addq	$1, -8(%rbp)
.L6:
	movq	-16(%rbp), %rax
	movzbl	(%rax), %eax
	testb	%al, %al
	je	.L7
	movq	-8(%rbp), %rax
	movzbl	(%rax), %eax
	testb	%al, %al
	je	.L7
	movq	-16(%rbp), %rax
	movzbl	(%rax), %edx
	movq	-8(%rbp), %rax
	movzbl	(%rax), %eax
	cmpb	%al, %dl
	je	.L8
.L7:
	movq	-8(%rbp), %rax
	movzbl	(%rax), %eax
	testb	%al, %al
	jne	.L9
	movq	-24(%rbp), %rax
	jmp	.L3
.L9:
	addq	$1, -24(%rbp)
.L5:
	movq	-24(%rbp), %rax
	movzbl	(%rax), %eax
	testb	%al, %al
	jne	.L10
	movl	$0, %eax
.L3:
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	_Z6strStrPcS_, .-_Z6strStrPcS_
	.section	.rodata
.LC0:
	.string	"r"
	.align 8
.LC1:
	.string	"Plik nie istnieje lub wyst\304\205pi\305\202 problem z jego odczytem."
.LC2:
	.string	"%d -> %s\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$560, %rsp
	movl	%edi, -548(%rbp)
	movq	%rsi, -560(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$1, -540(%rbp)
	movq	-560(%rbp), %rax
	addq	$8, %rax
	movq	(%rax), %rax
	movl	$.LC0, %esi
	movq	%rax, %rdi
	call	fopen
	movq	%rax, -536(%rbp)
	cmpq	$0, -536(%rbp)
	sete	%al
	testb	%al, %al
	je	.L12
	movl	$.LC1, %edi
	movl	$0, %eax
	call	printf
	movl	$-1, %eax
	jmp	.L18
.L12:
	jmp	.L14
.L16:
	movq	-560(%rbp), %rax
	addq	$16, %rax
	movq	(%rax), %rdx
	leaq	-528(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_Z6strStrPcS_
	testq	%rax, %rax
	setne	%al
	testb	%al, %al
	je	.L15
	leaq	-528(%rbp), %rdx
	movl	-540(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC2, %edi
	movl	$0, %eax
	call	printf
.L15:
	addl	$1, -540(%rbp)
.L14:
	movl	$512, %ecx
	movq	-536(%rbp), %rdx
	leaq	-528(%rbp), %rax
	movl	%ecx, %esi
	movq	%rax, %rdi
	call	fgets
	testq	%rax, %rax
	setne	%al
	testb	%al, %al
	jne	.L16
	cmpq	$0, -536(%rbp)
	je	.L17
	movq	-536(%rbp), %rax
	movq	%rax, %rdi
	call	fclose
.L17:
	movl	$0, %eax
.L18:
	movq	-8(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L19
	call	__stack_chk_fail
.L19:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 4.9.2-10ubuntu13) 4.9.2"
	.section	.note.GNU-stack,"",@progbits
