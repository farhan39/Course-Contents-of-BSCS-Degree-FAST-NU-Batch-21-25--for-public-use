; scroll up the screen
[org 0x0100]
 
jmp start

buffer: times 4000 db 0 ; space for 4000 bytes

message1: db 10, 13, 'Program started. $'
message2: db 10, 13, 'Message 22222... $'
message3: db 10, 13, 'Message 333... $'
;---------------------------------------------------------------------------
sleep:		push cx

		mov cx, 0xFFFF
delay:		loop delay

		pop cx
		ret
;--------------------------------------------------------------------
; subroutine to clear the screen
;--------------------------------------------------------------------
clrscr:		push es
			push ax
			push di

			mov ax, 0xb800
			mov es, ax					; point es to video base
			mov di, 0					; point di to top left column

nextloc:	mov word [es:di], 0x0720	; clear next char on screen
			add di, 2					; move to next screen location
			cmp di, 4000				; has the whole screen cleared
			jne nextloc					; if no clear next position

			pop di
			pop ax
			pop es
			ret
;--------------------------------------------------------------------

 ;-----------------------------------------------------------------
; subroutine to save the screen
;-----------------------------------------------------------------
saveScreen:	pusha	


			mov cx, 4000 ; number of screen locations

					

			mov ax, 0xb800
			mov ds, ax ; ds = 0xb800

			push cs
			pop es
		
			mov si, 0
			mov di, buffer

			cld ; set auto increment mode
			rep movsb ; save screen

			;[es:di] = [ds:si]
			

popa
			ret
;-----------------------------------------------------------------
;-----------------------------------------------------------------
; subroutine to restore the screen
;-----------------------------------------------------------------
restoreScreen:		pusha	


			mov cx, 4000 ; number of screen locations

					

			mov ax, 0xb800
			mov es, ax ; ds = 0xb800

			push cs
			pop ds
		
			mov si, buffer
			mov di, 0

			cld ; set auto increment mode
			rep movsb ; save screen

			;[es:di] = [ds:si]
			

popa
			ret	
;-----------------------------------------------------------------
start: 

	call saveScreen

mov ah, 0								; service 0 – get keystroke
int 0x16

call clrscr
mov ah, 0								; service 0 – get keystroke
int 0x16

call restoreScreen
mov ah, 0								; service 0 – get keystroke
int 0x16




mov ax, 0x4c00 ; terminate program 
int 0x21 