BITS 64                     ; 64 bits mode

SECTION .text               ; code section

GLOBAL memset               ; export void *memset(void *ptr, int c, size_t n)

memset:
    push rbp                ;
    mov rbp, rsp            ; equal ENTER keyword with line before
    xor rcx, rcx            ; loop count = 0
    mov rax, rdi            ; move ptr to return value
    cmp rdi, 0              ; check if ptr is NULL
    je end                  ; if NULL return
    cmp rsi, 0              ; check if c is equal to 0
    je end                  ; if 0 return
    cmp rdx, 0              ; check if n equal to 0
    je end                  ; if 0 return

.loop:
    cmp BYTE [rax + rcx], 0 ; check when \0 is reached
    je end                  ; return if \0 is found
    cmp rcx, rdx            ; cmp count with n
    je end                  ; if equal, n first byte were replaced so we return
    mov [rax + rcx], sil    ; moving c into return_ptr[i]
    inc rcx                 ; rcx incremented by one
    jmp .loop                ; repeat


end:
    mov rsp, rbp            ;
    pop rbp                 ;   equal LEAVE keyword with line before
    ret