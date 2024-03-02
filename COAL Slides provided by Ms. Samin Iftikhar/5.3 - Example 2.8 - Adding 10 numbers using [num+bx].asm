; a program to add ten numbers using reg+offset addressing

[org 0x0100]

mov bx, 0					; initialize array index to 0
mov cx, 10				; load total count in cx
mov ax, 0				; initialize sum to 0

l1: 	add ax, [num1+bx]		; add ith number in ax
		add bx, 2			; move bx to next number
		sub cx, 1			; decrement counter by 1
		jnz l1				; JUMP to l1 if ZERO FLAG is not Set
							; Zero flag is set if last arithmetic/logical 
							; operation produces zero in its destination

mov [total], ax				; save sum in total

mov ax, 0x4c00			;terminate the program
int 0x21

num1:	dw 1, 2, 3, 4, 5, 1, 2, 3, 4, 5
total:	dw 0