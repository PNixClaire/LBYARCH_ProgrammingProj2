section .data 

;test data here
a dd 0.0, 0.0, 0.0, 0.0
b dd 0.0, 0.0, 0.0, 0.0
n dd 4 ;length
sdot dd 0.0 ;total

section .text
bits 64 
default rel

global dotProd

dotProd:
	START: 
		cmp rax, [n]
		jge END

		movupd xmm1, [a + rax*8]
		movupd xmm2, [b + rax*8]

		mulpd xmm1, xmm2
		addpd xmm0, xmm1

		add rax, 1
		jmp START
	END:
		haddpd xmm0, xmm0
		movupd [sdot], xmm0
ret