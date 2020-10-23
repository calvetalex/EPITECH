BITS 64                                     ;64 bits mode

section .text                               ; code section

global rindex                               ; export char *index(const char *s, int c)

rindex:
    push rbp                                ;
    mov rbp, rsp                            ; equal to ENTER keyword with line before
    mov rax, 0                              ; prepare to return NULL by default
    xor rcx, rcx                            ; loop count = 0
    cmp rdi, 0                              ; check if s is NULL
    je end                                  ; if NULL return
    cmp rsi, 0                              ; check if c equal to 0
    je end                                  ; if equal to 0 return

.set_counter_to_end:
    cmp BYTE [rdi + rcx], 0                 ; check when \0 is reached in s
    je .loop                                ; if reached, we go to the loop function to find c
    inc rcx                                 ; increment rcx by one
    jmp .set_counter_to_end                 ; repeat this loop

.loop:
    cmp rcx, 0                              ; check when rcx is equal to 0
    jl end                                  ; when rcx equal to 0, end the function
    cmp BYTE [rdi + rcx], sil               ; check if str[i] == c
    je .found                               ; if found, go to found
    dec rcx                                 ; decement rcx by one
    jmp .loop                               ; repeat

.found:
    mov rax, rdi                            ; mov str in return value
    add rax, rcx                            ; adding count to get address from str[i]

end:
    mov rsp, rbp                            ;
    pop rbp                                 ; equal LEAVE keyword with line before
    ret