findNthTermOfAP(int, int, int):                 # @findNthTermOfAP(int, int, int)
        cmp     edx, 2
        jl      .LBB0_2
        dec     edx
        imul    edx, esi
        add     edi, edx
.LBB0_2:                                # %for.cond.cleanup
        mov     eax, edi
        ret