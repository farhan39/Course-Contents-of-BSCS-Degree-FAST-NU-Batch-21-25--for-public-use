; divide by zero interrupt -> Hangs system
[org 0x0100]
	 jmp start

; subroutine to generate a divide by zero interrupt

genint0: 	mov ax, 0x8432		; load a big number in ax. Try 0x84/2 instead... 8432/2
			mov bl, 2			; use a very small divisor
			div bl				; interrupt 0 will be generated ans = 0x4216 cannot be saved in al
			
			ret
;------------------------------------------------------
start: 		call genint0 ; generate interrupt 0
			
			mov ax, 0x4c00 ; terminate program
			int 0x21 