BITS 64                                     ;64 bits mode

SECTION .text                               ; code section

GLOBAL strncmp                               ; export int strncmp(char const *s1, char const *s2, size_t n)

strncmp:
    push rbp                                ;
    mov rbp, rsp                            ; equal to ENTER keyword with line before

    xor rcx, rcx                            ; loop count = 0

.loop:
    mov r8b, [rdi + rcx]                    ; mov str1[i] in tmp var
    mov r9b, [rsi + rcx]                    ; mov str2[i] in tmp var
    cmp r8b, 0                              ; cmp s1[i] with '\0
    je end                                  ; if equal, jump to end
    cmp r9b, 0                              ; cmp s2[i] with '\0'
    je end                                  ; if equal jump to end
    cmp r8b, r9b                            ; cmp s1[i] and s2[i]
    jne end                                 ; if not equal, jump to end
    inc rcx                                 ; increment rcx by one
    cmp rcx, rdx                            ; check if count > n
    je end
    jmp .loop                                ; repeat

end:
    sub r8b, r9b                            ; substract tmp2 to tmp
    movsx rax, r8b                          ; place result of the sub in return result

    mov rsp, rbp                            ;
    pop rbp                                 ; equal LEAVE keyword with line before
    ret