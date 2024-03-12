global sgn

section .data

section .text

sgn:
    mov   eax, edi   ; argument 1
    cmp   eax, 0
    jz    sgn_exit
    mov   eax, 1 
    jns   sgn_exit
    neg   eax
    sgn_exit:
