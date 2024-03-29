%include "io64.inc"
section .data 
;test data here but this should get input from C...I think
a dd 2.0, 2.0, 2.0, 2.0
b dd 2.0, 4.0, 6.0, 8.0
n dd 4 ;length
sdot dd 0.0 ;total
section .text
global main
main:
    mov rbp, rsp; for correct debugging
    ;write your code here
    
                 movups xmm1, [a]
		movups xmm2, [b]
		mulps xmm1, xmm2
		haddps xmm1, xmm1
		haddps xmm1, xmm1
                 movups [sdot], xmm1
                
    xor rax, rax
    ret