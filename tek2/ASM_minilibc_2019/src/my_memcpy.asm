BITS 64                             ; 64 bits mode

SECTION .text                       ; code section

GLOBAL memcpy                       ; export void *memcpy(void *dest, const void *src, size_t n)

memcpy:
    push rbp                        ;
    mov rbp, rsp                    ; equal ENTER keyword with line before
    xor rcx, rcx                    ; loop count = 0
    mov rax, rdi                    ; move ptr to return value
    cmp rdi, 0                      ; check if dest is NULL
    je end                          ; if NULL return
    cmp rsi, 0                      ; check if src is NULL
    je end                          ; if NULL return
    cmp rdx, 0                      ; check if n is equal to 0
    je end                          ; if yes return

.loop:
    cmp BYTE [rsi + rcx], 0         ; check when \0 is reached
    je end                          ; when reached, return
    cmp rcx, rdx                    ; cmp count with n
    je end                          ; if equal, n first byte were replaced so we return
    mov r8b, [rsi + rcx]            ; copy src[i] into dest[i] by using tmp var
    mov [rdi + rcx], r8b            ;
    inc rcx                         ; increment rcx by one
    jmp .loop                        ; repeat


end:
    mov rsp, rbp                    ;
    pop rbp                         ;   equal LEAVE keyword with line before
    ret