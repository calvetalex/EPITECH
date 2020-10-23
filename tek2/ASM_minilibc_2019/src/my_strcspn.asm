BITS 64
section .text                   ; code section
global strcspn                  ; export int strcspn(const char *s, const char *reject)

strcspn:
    push rbp                    ;
    mov rbp, rsp                ; equal to ENTER keyword wit line before
    xor rcx, rcx                ; set counter to 0
    xor r8, r8                  ; set counter2 to 0
    cmp rdi, 0                  ; check if s is NULL
    je end                      ; if NULL return
    cmp rsi, 0                  ; check if reject is NULL
    je end                      ; if NULL return

.main_loop:
    mov r9b, [rdi + rcx]        ; place s[counter] in tmp var
    cmp r9b, 0                  ; check when \0 is reached in s
    je end                      ; if reached, s is ended

.check_char:
    cmp r9b, BYTE [rsi + r8]    ; check if s[counter] match with a char of reject
    je end                      ; if yes, we return
    cmp BYTE [rsi + r8], 0      ; check when \0 is reached in accept
    je .repeat                  ; if reached, we can iterate on s[counter + 1]
    inc r8                      ; increment ounter2 by one
    jmp .check_char             ; repeat this loop

.repeat:
    xor r8, r8                  ; set counter2 to 0
    inc rcx                     ; increment counter by one
    jmp .main_loop
end:
    mov rax, rcx                ; place counter in return value
    mov rsp, rbp                ;
    pop rbp                     ; equal to LEAVE keyword with line before
    ret