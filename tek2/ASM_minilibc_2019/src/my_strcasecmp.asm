BITS 64

section .text                       ; code section
global strcasecmp                   ; export int strcasecmp(const char *s1, const char *s2)

strcasecmp:
    push rbp                        ;
    mov rbp, rsp                    ; enqual to ENTER keyword with line before
    xor rcx, rcx                    ; set count to 0
    xor rax, rax                    ; set return to 0 by default
    cmp rdi, 0                      ; check if s1 is NULL
    je end                          ; if true return
    cmp rsi, 0                      ; check if s2 is NULL
    je end                          ; if true return

.main_loop:
    mov r8b, [rdi + rcx]            ; place s1 in tmp
    cmp r8b, 65                     ; check if tmp is lower than 'A'
    jl .phase2                      ; if lower, then continue with s2
    cmp r8b, 90                     ; cmp tmp and 'Z'
    jl .to_lower_1                  ; replace tmp by tmp in lowercase

.phase2:
    mov r9b, [rsi + rcx]            ; place s2 in tmp
    cmp r9b, 65                     ; check if tmp is lower than 'A'
    jl .compare                     ; if lower, then continue with comparaison between s1 and s2
    cmp r9b, 90                     ; cmp tmp and 'Z'
    jl .to_lower_2                  ; replace tmp by tmp in lowercase

.compare:
    cmp r8b, 0                      ; check when \0 is reached in s1
    je .get_diff                    ; go to end if reached
    cmp r9b, 0                      ; check when \0 is reached in s2
    je .get_diff                    ; go to end if reached
    cmp r8b, r9b                    ; compare if s1 and s2 are equal
    jne .get_diff                         ; if not, go to end
    inc rcx                         ; increment counter by one
    jmp .main_loop

.to_lower_1:
    add r8b, 32                     ; transform tmp in lowercase
    jmp .phase2                     ; jump the loop part for s2

.to_lower_2:
    add r9b, 32                     ; transform tmp in lowercase
    jmp .compare                    ; jump to the end og the main loop

.get_diff:
    sub r8b, r9b                    ; substract tmp2 to tmp
    movsx rax, r8b                  ; place result of the sub in return result

end:
    mov rsp, rbp                    ;
    pop rbp                         ; equal to LEAVE keyword with line before
    ret