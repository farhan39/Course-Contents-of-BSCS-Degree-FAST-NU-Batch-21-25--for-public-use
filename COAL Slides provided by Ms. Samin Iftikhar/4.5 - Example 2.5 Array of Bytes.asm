; a program to add three numbers using 1 byte data

[org 0x0100]

mov al, [num1]		;load num 1 in ax 
mov [num1+3], al	;write data from ax in number 4
mov al, [num1+1]	;load num 2 in ax
add [num1+3], al	;add 2 numbers
mov al, [num1+2]	;load num 3 in ax
add [num1+3], al	;add 2 numbers

mov ax, 0x4c00	;terminate the program
int 0x21

num1:	db 5, 10, 15, 0	