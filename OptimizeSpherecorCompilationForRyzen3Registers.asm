mov rax, [data1]  ; Load into RAX (fastest register)
mov rbx, [data2]  ; Load into RBX
add rax, rbx      ; Perform computation in registers
mov [result], rax ; Store back to memory
