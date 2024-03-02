; Extended Shifting
[org 0x0100]
		jmp start

a: 	DW 0xF0AF ; 1111 0000 1010 1111
b: 	DW 0xFA0F ; 1111 0000 1010 1111
c: 	DD 0x0A0FF0AF ; 0000 1010 0000 1111 1111 0000 1010 1111

start:
	mov ax, [a]
	shl ax, 1
	
	shl word[b], 1 	

	shl word[c],1	
	rcl word[c+2],1

mov ax, 0x4c00		;terminate the program
int 0x21

