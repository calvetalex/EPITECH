BITS 64                     ; 64 bits mode

SECTION .text               ; code section

GLOBAL strlen               ; export size_t strlen(const char *s)

strlen:
    push rbp                ;
    mov rbp, rsp            ; equal ENTER keyword with line before
    xor rcx, rcx            ; loop count = 0
    cmp rdi, 0              ; check if s is NULL
    je end                  ; if NULL return

.loop:
    cmp BYTE[rdi + rcx], 0  ; cmp rdi[rcx] to null bit. Like str[i] != '\0'
    je end                  ; if end of str, ret
    inc rcx                 ; increment rcx by one
    jmp .loop
end:
    mov rax, rcx            ; count moved in return register
    mov rsp, rbp            ;
    pop rbp                 ;   equal LEAVE keyword with line before
    ret
