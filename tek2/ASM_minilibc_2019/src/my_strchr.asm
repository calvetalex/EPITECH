BITS 64                         ; 64 bits mode

section .text                   ; code section, rdi, rsi, rdx, rcx, r8, r9

global strchr                   ; export char *strchr(const char *str, int c)

strchr:
    push rbp                    ;
    mov rbp, rsp                ; equal ENTER keyword with line before

    xor rcx, rcx                ; count to 0
    xor rax, rax                ; result to 0
    cmp rdi, 0                  ; check if str is NULL
    je end                      ; if null return
    cmp rsi, 0                  ; check if c != 0
    je end                      ; if 0 return

.loop:
    cmp BYTE[rdi + rcx], sil    ; cmp str[i] with elem to find, bit / bit
    je .find                     ; if found c, jump to find
    cmp BYTE[rdi + rcx], 0      ; cmp str[i] with '\0'
    je end                      ; if end of str, jump to end
    inc rcx                     ; increment count by one
    jmp .loop                   ; repeat

.find:
    mov rax, rdi                ; move str in result
    add rax, rcx                ; adding i to res to get address of str[i]
    jmp end                     ; return

end:
    mov rsp, rbp            ;
    pop rbp                 ;   equal LEAVE keyword with line before
    ret
