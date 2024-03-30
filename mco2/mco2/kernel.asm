;%include "io64.inc"
section .data 
;a dq 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0
;b dq 2.0, 4.0, 6.0, 8.0, 10.0, 12.0, 14.0, 16.0
;n dd 8 ;length

sdot dq 0.0 ;total

section .text
bits 64
default rel
global dotProdAsm
extern printf

dotProdAsm:
    push rbp          
    mov rbp, rsp      

    mov rsi, rcx      ; *a
    mov rdi, rdx      ; *b
    mov rcx, r8       ; n

    xorpd xmm0, xmm0 
    xor rax, rax     

dotProdLoop:
    movapd xmm1, [rsi + rax*8]  
    movapd xmm2, [rdi + rax*8]  
    
    mulpd xmm1, xmm2  
    haddpd xmm1, xmm1 
    addpd xmm0, xmm1  
    
    add rax, 2         
    cmp rax, rcx       
    jl dotProdLoop     ;jump if < n
    
    movapd [sdot], xmm0 

    pop rbp           
    ret                
