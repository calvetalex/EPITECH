BITS 64
section .text                   ; code section
global strpbrk                  ; export char *strpbrk(const char *s, const char *accept)

strpbrk:
    push rbp                    ;
    mov rbp, rsp                ; equal to ENTER keyword with line before
    xor rcx, rcx                ; set count to 0
    xor r8, r8                  ; set count2 to 0
    cmp rdi, 0                  ; check if s is NULL
    je .not_found               ; if nul lreturn
    cmp rsi, 0                  ; check if accept is null
    je .not_found               ; if null, no occurency could be found, return NULL

.main_loop:
    mov r9b, [rdi + rcx]        ; place s[count] in tmp var
    cmp r9b, 0           ; check when \0 is reached in s
    je .not_found               ; if reached, no occurency was found

.find_loop:
    cmp r9b, BYTE [rsi + r8]    ; check if s[count] match with a char of accept
    je .find                    ; if yes, we found an occurency, we return it
    cmp BYTE [rsi + r8], 0      ; check when \0 is reached in accept
    je .repeat                  ; if found, we can iterate on s[count + 1]
    inc r8                      ; increment count2 by one
    jmp .find_loop              ; repeat this loop

.repeat:
    xor r8, r8                  ; set counter2 to 0
    inc rcx                     ; increment count by one
    jmp .main_loop              ; repeat main_loop

.find:
    mov rax, rdi                ; set return value to s
    add rax, rcx                ; get address of s[i]
    jmp end                     ; go to end

.not_found:
    mov rax, 0                  ; set return value to NULL
    jmp end                     ; go to end

end:
    mov rsp, rbp                ;
    pop rbp                     ; equal to LEAVE keyword with line before
    ret