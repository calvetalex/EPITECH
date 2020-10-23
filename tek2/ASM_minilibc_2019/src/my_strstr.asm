BITS 64
section	.text               ; code section
global strstr               ; export char *strstr(const char *s1, const char *s2)

strstr:
    push rbp                ;
    mov rbp, rsp            ; equal to ENTER keyword with line before
    xor rcx, rcx            ; count init to 0
    xor rax, rax            ; set return value to 0
    cmp rdi, 0              ; check if s1 is NULL
    je end                  ; return if null
    cmp rsi, 0              ; check if s2 is NULL
    je end                  ; return is null
    jmp .loop               ; jump to loop

.rebase_value:
    cmp r8b, 0              ; check if s1 reached \0
    je end                  ; if yes substring was not found, return
    inc rdi                 ; increment s1 by one to loop on next substring
    xor rcx, rcx            ; rebase count to 0
    jmp .loop               ; loop again

.loop:
    mov r8b, [rdi + rcx]    ; place s1[count] in tmp
    mov r9b, [rsi + rcx]    ; place s2[count] in tmp2
    cmp r9b, 0              ; check when s2 reached \0
    je .find                 ; if s2 ended, substring is find
    cmp r8b, r9b            ; check if s1[count] = s2[count]
    jne .rebase_value       ; if not, substring is not found, rebase counter
    inc rcx                 ; increment count by one
    jmp .loop               ; repeat

.find:
    mov rax, rdi            ; place begining of substring in return value
    jmp end                 ; return

end:
    mov rsp, rsp           ;
    pop rbp                 ; equal to LEAVE keyword with line before
    ret