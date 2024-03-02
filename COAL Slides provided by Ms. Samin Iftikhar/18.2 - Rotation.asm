; Example 11.1 - elementary multitasking of two threads - TaskOne Explanation

[org 0x0100]
mov bx, 0xb800
mov es, bx
mov bx, 0

jmp taskone

chars:		db '\|/-' ; shapes to form a bar

;---------------------------------------------------------------------------
; one task to be multitasked
;---------------------------------------------------------------------------
taskone:	mov al, [chars+bx]			; read the next shape
			mov [es:0], al				; write at top left of screen 
			inc bx						; increment to next shape
			and bx, 3					; taking modulus by 4

			; 0000 && 0011 = 0000
			; 0001 && 0011 = 0001
			; 0010 && 0011 = 0010
			; 0011 && 0011 = 0011
			; 0100 && 0011 = 0000

			jmp taskone					; infinite task

