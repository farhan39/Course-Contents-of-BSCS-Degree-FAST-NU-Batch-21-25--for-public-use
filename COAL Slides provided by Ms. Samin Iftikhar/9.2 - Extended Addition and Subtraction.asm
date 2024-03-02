; Extended Addition and subtraction

[org 0x0100]

		jmp start

a: 	DD 0xFF59D4E1
b:	DD 0x0FFA5C32
c: 	DD 0xE059D4E1
d:	DD 0x00FA5C32

start: 	mov ax, [a]
	add [b], ax
	mov ax, [a+2]
	adc [b+2], ax;10F543113

	mov ax, [c]
	sub word[d], ax
	mov ax, [c+2]
	sbb word[d+2], ax;FFF...20A08751

mov ax, 0x4c00		;terminate the program
int 0x21

