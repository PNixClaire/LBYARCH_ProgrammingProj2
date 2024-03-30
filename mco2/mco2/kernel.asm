;%include "io64.inc"
section .data 
;test data here but this should get input from C...I think
;a dq 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0
;b dq 2.0, 4.0, 6.0, 8.0, 10.0, 12.0, 14.0, 16.0
;n dd 8 ;length

sdot dq 0.0 ;total

section .text
bits 64
default rel
global dotProdAsm
extern printf

;global main
;main:

dotProdAsm:

    sub rsp, 8*5
    mov rsi, rcx ;*a
    mov rdi, rdx ;*b
    mov rcx, r8 ;n
    shr rcx, 1
    
    xorpd xmm0, xmm0
    NEXT: 
        movapd xmm0, [rsi]
        movapd xmm2, [rdi]
        
        mulpd xmm1, xmm2
        haddpd  xmm1, xmm1
        addpd xmm0, xmm1
        
        add rdi, 16
        add rsi, 16
        
        loop NEXT
        
        movapd [sdot], xmm0
        add rsp, 8*5
        ret
