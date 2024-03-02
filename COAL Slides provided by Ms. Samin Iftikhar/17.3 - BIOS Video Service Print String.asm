; Video Service # 13 http://www.delorie.com/djgpp/doc/rbinter/id/15/2.html
;Example 8.2 - print string using bios service

[org 0x0100]
jmp start
message: db 'Hello World'

start: 	mov ah, 0x13		; service 13 - print string
		
		mov al, 1			; subservice 01 – update cursor 
		;????????????????????????????????WHAT WILL BE THE OUTPUT IF AL = 0???

		;Text video screen is in the form of pages which can be upto 32. At
		;one time one page is visible which is by default the zeroth page
		;unless we change it. 
		mov bh, 0			; output on page 0
		
		mov bl, 01000111B	; normal attrib
		mov cx, 11			; length of string
		mov dx, 0x0A03		; row 10 column 3
		
		;es:bp = ds:message
		push ds
		pop es				; es=ds segment of string
		mov bp, message		; bp = offset of string
		
		INT 0x10			; call BIOS video service

		mov dx, 0x020A
		INT 0x10			; call BIOS video service
		;?????????????????????????????????????How will this line work???
		
		mov ax, 0x4c00 ; terminate program
		int 0x21 