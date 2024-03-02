; hello world in assembly
[org 0x0100]
jmp start
message: db 'hello world' ; string to be printed
length: dw 11 ; length of the string

message1: db 'hello Testing' ; string to be printed
length1: dw 13 ; length of the string
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

delay:      push cx
			mov cx, 0xFFFF
loop1:		loop loop1
			mov cx, 0xFFFF
loop2:		loop loop2
			pop cx
			ret

;--------------------------------------------------------------------
; subroutine to print a string at top left of screen
; takes x position, y position, string attribute, address of string
; and its length as parameters
;--------------------------------------------------------------------
printstr:	push bp
			mov bp, sp
			push es
			push ax
			push cx
			push si
			push di

			mov ax, 0xb800
			mov es, ax				; point es to video base

			mov al, 80				; load al with columns per row
			mul byte [bp+12]		; 80 x r
			add ax, [bp+10]			; word number (80xr) + c
			shl ax, 1				; byte no (((80xr) + c)x2)

			mov di, ax				; point di to required location
			mov si, [bp+6]			; point si to string
			mov cx, [bp+4]			; load length of string in cx
			mov ah, [bp+8]			; load attribute in ah

nextchar:	mov al, [si]			; load next char of string
			mov [es:di], ax			; show this char on screen
			add di, 2				; move to next screen location
			add si, 1				; move to next char in string
			call delay
			loop nextchar			; repeat the operation cx times

			pop di
			pop si
			pop cx
			pop ax
			pop es
			pop bp
			ret 10

;--------------------------------------------------------------------
start:	call clrscr ; call the clrscr subroutine

		mov ax, 10
		push ax				; push r position............[bp+12]
		mov ax, 30
		push ax				; push c position............[bp+10]
		mov ax, 1			; blue on black attribute
		push ax				; push attribute............[bp+8]
		mov ax, message
		push ax				; push address of message............[bp+6]
		push word [length]	; push message length ....[bp+4]
		
		call printstr ; call the printstr subroutine


		mov ax, 20
		push ax				; push r position............[bp+12]
		mov ax, 10
		push ax				; push c position............[bp+10]
		mov ax, 0x04		; blue on black attribute
		push ax				; push attribute............[bp+8]
		mov ax, message1
		push ax				; push address of message............[bp+6]
		push word [length1]	; push message length ....[bp+4]
		
		call printstr ; call the printstr subroutine
		
		mov ax, 0x4c00 ; terminate program
		int 0x21