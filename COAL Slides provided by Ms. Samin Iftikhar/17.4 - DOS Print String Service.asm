; INT 21 DOS Service 9
; Reference: http://www.delorie.com/djgpp/doc/rbinter/id/73/25.html
; Following piece of code prints a $ terminated string on Console using DOS Service # 9
[org 0x0100]

				jmp start

msg1:		db 'Hello World ...$'				;'$' terminated string

start:	mov dx, msg1	 						; ds:dx points to '$' terminated string
		mov ah, 9 								; service 9 –  WRITE STRING TO STANDARD OUTPUT
		int 0x21  						; dos services
		
		mov ax, 0x4c00 ; terminate program
		int 0x21 

