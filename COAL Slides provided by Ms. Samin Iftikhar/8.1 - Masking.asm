; Bitwise Logical Masking Operations
[org 0x100]
jmp start

a: 	dw 0xFAF5 
b: 	dw 0xFAF5 
c: 	dw 0xFAF5
d: 	dw 0xFAF5

start: 		mov AX, 0xFF00
		mov BX, [a]
		AND BX, AX
		
		mov BX, [a]
		OR BX, AX

		mov BX, [a]
		XOR BX, AX

		mov BX, [a]
		NOT BX

		mov AX, 0xFF00		
		AND [a], AX
		
		OR [b], AX

		XOR [c], AX

		NOT word[d]


mov ax, 0x4c00 ; terminate program
int 0x21 