section .text
global dot_product_asm

dot_product_asm:
    xorpd xmm0, xmm0
    test rcx, rcx
    jle .done

    xor r10, r10

.loop_start:
    movsd xmm1, qword [rdx + r10*8]
    mulsd xmm1, qword [r8 + r10*8]
    addsd xmm0, xmm1

    inc r10
    cmp r10, rcx
    jl .loop_start

.done:
    movsd qword [r9], xmm0
    ret