	.file	"zadanie3.cpp"
	.text
	.globl	_Z5dodajii
	.type	_Z5dodajii, @function
_Z5dodajii:
.LFB0:
	.cfi_startproc #instrukcje rozpoczynające się od .cfi to tak zwane “call frame instructions”, które mają znaczenie dla operowania na stosie i obsługi wyjątków
	pushq	%rbp #umieszczamy na stosie base pointer
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp #zapisujemy do %rbp wartość %rsp
	.cfi_def_cfa_register 6
	movl	%edi, -4(%rbp) #zapisujemy 4 bajtów poniżej %rbp wartość %edi (6)
	movl	%esi, -8(%rbp) #zapisujemy 8 bajtów poniżej %rbp wartość %esi (4)
	movl	-4(%rbp), %edx #zapisujemy wartość z -4(%rbp) do %edx (6)
	movl	-8(%rbp), %eax #zapisujemy wartość z -8(%rbp) do %eax (4)
	addl	%edx, %eax #dodajemy zawartość %edx (6) do %eax (4)
	popq	%rbp #zdejmujemy base pointer ze stosu
	.cfi_def_cfa 7, 8
	ret #kończymy funkcję - wynik funkcji (wartość 10) jest zapisany w rejestrze %eax
	.cfi_endproc
.LFE0:
	.size	_Z5dodajii, .-_Z5dodajii
	.globl	main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	pushq	%rbp #umieszczamy na stosie base pointer
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp #zapisujemy do %rbp wartość %rsp
	.cfi_def_cfa_register 6
	movl	$4, %esi #zapisujemy argument 4 do %esi
	movl	$6, %edi #zapisujemy argument 6 do %edi
	call	_Z5dodajii #wywołujemy funkcję 'dodaj' 'ii' oznacza, że parametrami są dwa integery
	movl	$0, %eax #nie używamy nigdzie wyniku funkcji dodaj dlatego od razu zerujemy rejestr %eax
	popq	%rbp #zdejmujemy base pointer ze stosu
	.cfi_def_cfa 7, 8
	ret #kończymy funkcję main
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 4.9.2-10ubuntu13) 4.9.2"
	.section	.note.GNU-stack,"",@progbits
