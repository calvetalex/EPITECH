BITS 64

section .text               ; code section
global memmove              ; export void *memmove(void *dest, void const *src, size_t n)

memmove:
    push rbp                ;
    mov rbp, rsp            ; equal to ENTER keyword with line before
    xor rcx, rcx            ; set count for loop to 0

.error_handle:
    cmp rdi, 0              ; check if dest is NULL
    je end                  ; if null return
    cmp rsi, 0              ; check if src is NULL
    je end                  ; if NULL return
    cmp rdx, 0              ; check if n == 0
    je end                  ; if yes return
    mov r8, rdi             ; place dest in tmp
    sub r8, rsi             ; sub tmp with src to check place in memory
    cmp r8, 0               ; check if dest is before src or not
    je end                  ; if src == dest we don't do anything
    jl .safe_copy           ; if src > dest we make a memcpy
    dec rdx                 ; set n to n-1 because array start at 0

.overlapped_region:
    cmp rdx, 0              ; check when 0 is reached
    jl end                  ; stop if count is equal to 0
    mov r8b, [rsi + rdx]    ; save src[n] in tmp
    mov [rdi + rdx], r8b    ; place tmp into dest[n]
    dec rdx                 ; decrement count by one
    jmp .overlapped_region  ; repeat

.safe_copy:
    cmp rdx, rcx            ; check when n is reached
    je end                  ; if count equal n then stop and return
    cmp BYTE [rsi + rcx], 0 ; check when \0 is reached in src
    je end                  ; if reached return
    mov r8b, [rsi + rcx]    ; mov src[count] int tmp var
    mov [rdi + rcx], r8b    ; set dest[count] equal to tmp var
    inc rcx                 ; increment counter by one
    jmp .safe_copy          ; repeat

end:
    mov rax, rdi            ; prepare to return dest
    mov rsp, rbp            ;
    pop rbp                 ; equal to LEAVE keyword with line before
    ret