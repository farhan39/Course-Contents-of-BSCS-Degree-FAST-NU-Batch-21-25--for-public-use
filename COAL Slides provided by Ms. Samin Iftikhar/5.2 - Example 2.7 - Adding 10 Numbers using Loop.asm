; a program to add ten numbers
[org 0x0100]

mov bx, num1					; point bx to first number
mov cx, 10					; load count of numbers in cx
mov ax, 0					; initialize sum to zero

l1:		add ax, [bx]			; add number to ax ; [si] or [di] ???
		add bx, 2			; advance bx to next number
		sub cx, 1			; numbers to be added reduced
		jnz l1				; if numbers remain add next ; jump to l1 if (zero flag == 0)
				
mov [total], ax 				; write back sum in memory

mov ax, 0x4c00 			; terminate program
int 0x21

num1: dw 1, 2, 3, 4, 5, 1, 2, 3, 4, 5
total: dw 0


;Total size of com file ???
; The assembler does not differentiate between code labels and data labels. 
; The label l1 in this case is the address of the following instruction.

; JNZ stands for “jump if not zero.” --> “jump to the location l1 if the zero flag is not set.” 
; “the zero flag is set if the last mathematical or logical operation has
; produced a zero in its destination.” 
; For example “mov ax, 0” will not set the zero flag as it is not a mathematical or logical instruction.
; However subtraction and addition will set it. 
; Also it is set even when the destination is not a register. 
; The processor will blindly go to the label we mention even if it contains data and not code.