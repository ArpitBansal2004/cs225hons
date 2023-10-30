findNthTermOfAP(int, int, int):                 # @findNthTermOfAP(int, int, int)
        push    rbp
        mov     rbp, rsp
        mov     dword ptr [rbp - 4], edi
        mov     dword ptr [rbp - 8], esi
        mov     dword ptr [rbp - 12], edx
        mov     edx, dword ptr [rbp - 4]
        mov     dword ptr [rbp - 16], edx
        mov     dword ptr [rbp - 20], 1
.LBB0_1:                                # %for.cond
        mov     eax, dword ptr [rbp - 20]
        cmp     eax, dword ptr [rbp - 12]
        jge     .LBB0_4
        mov     eax, dword ptr [rbp - 8]
        add     eax, dword ptr [rbp - 16]
        mov     dword ptr [rbp - 16], eax
        mov     eax, dword ptr [rbp - 20]
        add     eax, 1
        mov     dword ptr [rbp - 20], eax
        jmp     .LBB0_1
.LBB0_4:                                # %for.end
        mov     eax, dword ptr [rbp - 16]
        pop     rbp
        ret