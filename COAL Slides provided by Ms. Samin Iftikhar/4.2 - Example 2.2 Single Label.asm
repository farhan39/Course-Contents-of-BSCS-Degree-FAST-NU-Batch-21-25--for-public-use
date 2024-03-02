; a program to add three numbers accessed using a single label

[org 0x0100]

mov ax, [num1]		;load num 1 in ax OR load 16 bits from location num1 in ax
mov bx, [num1+2]	;load num 2 in bx OR load 16 bits from location num1+2 in bx (what is num1+2)
add ax, bx		;add bx in ax
mov bx, [num1+4]	;load num 3 in bx OR load 16 bits from location num1+4 in bx
add ax, bx		;add bx in ax
mov [num1+6], ax	;write sum in number 4

mov ax, 0x4c00	;terminate the program
int 0x21

num1:	dw 5	; label num1 will be used to access all the data
	dw 10
	dw 15
	dw 0
