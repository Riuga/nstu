global sgn

section .data

section .text

sgn:
    movd  eax,xmm0   ; argument 1
    shl   eax, 1 ;CF
    jz    sgn_end
    sbb   eax, eax 
    or    al, 1
    sgn_end:
    ret