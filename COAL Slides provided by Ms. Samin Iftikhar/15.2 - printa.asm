; hello world at desired screen location
	[org 0x0100]
	jmp start
message1: db 10, 13, 'END OF RECTANGLE PRINTING... $'

; subroutine to clear the screen
clrscr: 	pusha 

		mov ax, 0xb800
		mov es, ax 	; point es to video base
		mov di, 0 	; point di to top left column

nextloc: 	mov word [es:di], 0x0720 	; clear next char on screen
		add di, 2 			; move to next screen location
		cmp di, 4000 			; has the whole screen cleared
		jne nextloc 			; if no clear next position
	
		popa
		ret 

;---------------------------------------------------------------------------
printRectangle:	pusha

		mov ax, 0xb800
		mov es, ax 		; point es to video base

		mov al, 80 		; load al with columns per row
		mov dl, 2
		mul dl 	; multiply with row number
		add ax, 10 	; add col
		shl ax, 1 		; turn into byte offset
		mov di, ax 		; point di to required location
		mov ah, 0x44 		; load attribute in ah
		mov cx, 60
		sub cx, 10

topLine:	mov al, 0x2D 		; ASCII of '-'
		mov [es:di], ax 	; show this char on screen
		add di, 2 		; move to next screen location 
		call sleep;
		loop topLine		; repeat the operation cx times

		mov cx, 20
		sub cx, 2
		add di, 160

rightLine:	mov al, 0x7c 		; ASCII of '|'
		mov [es:di], ax 	; show this char on screen
		add di, 160 		; move to next screen location 		
		call sleep;
		loop rightLine		; repeat the operation cx times
		
		mov cx, 60
		sub cx, 10
		sub di, 2

bottomLine:	mov al, 0x2D 		; ASCII of '-'
		mov [es:di], ax 	; show this char on screen
		sub di, 2 		; move to next screen location 
		call sleep;
		loop bottomLine		; repeat the operation cx times

		mov cx, 20
		sub cx, 2
		sub di, 160

leftLine:	mov al, 0x7c 		; ASCII of '|'
		mov [es:di], ax 	; show this char on screen
		sub di, 160 		; move to next screen location 		
		call sleep;
		loop leftLine		; repeat the operation cx times

		popa
		ret
;---------------------------------------------------------------------------
sleep:		push cx
		mov cx, 0xFFFF
delay:		loop delay
		pop cx
		ret
;---------------------------------------------------------------------------
start: 		call clrscr 		; call the clrscr subroutine
		call printRectangle	; call the printstr subroutine
		
		mov dx, message1 						; greetings message
		mov ah, 9 								; service 9 – write string
		int 0x21 								; dos services
;---------------------------------------------------------------------------
		mov ax, 0x4c00 		; terminate program
		int 0x21
