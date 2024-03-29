%include "io64.inc"
section .data 
;test data here but this should get input from C...I think
a dq 2.0, 2.0, 2.0, 2.0
b dq 2.0, 4.0, 6.0, 8.0
n dd 4 ;length
sdot dq 0.0 ;total
section .text
global main
main:
    mov rbp, rsp; for correct debugging
    ;write your code here
    
    mov rsi, a
    mov rdi, b
    mov rcx, [n]
    
    xorpd xmm0, xmm0
    
    NEXT: 
        movapd xmm1, [rsi]
        movapd xmm2, [rdi]
        
        mulpd xmm1, xmm2
        haddpd  xmm1, xmm1
        addpd xmm0, xmm1
        
        add rdi, 16
        add rsi, 16
        
        loop NEXT
        
        movapd [sdot], xmm0

                
    xor rax, rax
    ret