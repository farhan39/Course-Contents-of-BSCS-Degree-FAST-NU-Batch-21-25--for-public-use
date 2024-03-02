; hello world printing using string instructions
	[org 0x0100]
	jmp start

message: db 'hello world' ; string to be printed
length: dw 11 ; length of string
;-------------------------------------------------------------------
; subroutine to clear the screen
;-------------------------------------------------------------------
clrscr:	push es
	push ax
	push cx
	push di

	mov ax, 0xb800
	mov es, ax ; point es to video base
	xor di, di ; point di to top left column
	mov ax, 0x0720 ; space char in normal attribute
	mov cx, 2000 ; number of screen locations
	
	cld ; auto increment mode
	rep stosw ; clear the whole screen

	pop di 
	pop cx
	pop ax
	pop es
	ret
;-------------------------------------------------------------------
; subroutine to print a string
; takes the x position, y position, attribute, address of string and
; its length as parameters
;-------------------------------------------------------------------
printstr:	push bp
		mov bp, sp
		push es
		push ax
		push cx
		push si
		push di

		mov ax, 0xb800
		mov es, ax 			; point es to video base

		mov al, 80 			; load al with columns per row
		mul byte [bp+12] 	; multiply with row number
		add ax, [bp+10] 	; add col
		shl ax, 1 			; turn into byte offset

		mov di, ax 			; point di to required location
		mov si, [bp+6] 		; point si to string
		mov cx, [bp+4] 		; load length of string in cx
		mov ah, [bp+8] 		; load attribute in ah

		cld ; auto increment mode

nextchar:	lodsb 			; load next char in al -> mov al,[ds:si] -> add si,1
			stosw 			; print char/attribute pair -> mov [es:di], ax -> add di,2
			loop nextchar 		; repeat for the whole string
		
		pop di
		pop si
		pop cx
		pop ax
		pop es
		pop bp
		ret 10

;-------------------------------------------------------------------
start: 		call clrscr 		; call the clrscr subroutine
		
		mov ax, 2
		push ax 		; push row number
		mov ax, 10
		push ax 		; push col number
		
		mov ax, 0x07 		; blue on black attribute
		push ax 		; push attribute
		mov ax, message
		push ax 		; push address of message
		push word [length] 	; push message length
		call printstr 		; call the printstr subroutine

		mov ax, 20
		push ax 		; push row number
		mov ax, 40
		push ax 		; push col number
		
		mov ax, 0x07 		; blue on black attribute
		push ax 		; push attribute
		mov ax, message
		push ax 		; push address of message
		push word [length] 	; push message length
		call printstr 		; call the printstr subroutine

		mov ax, 0x4c00 		; terminate program
		int 0x21