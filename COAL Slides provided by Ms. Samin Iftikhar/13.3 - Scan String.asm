;Example 7.3 - hello world printing with a null terminated string 
	[org 0x0100]
	jmp start

message: db 'hello world', 0 ; null terminated string  
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
; takes the x position, y position, attribute, and address of a null
; terminated string as parameters
;-------------------------------------------------------------------
printstr: 	push bp
		mov bp, sp
		push es
		push ax
		push cx
		push si
		push di

		push ds
		pop es ; es = ds

		mov di, [bp+4] ; point di to string... es:di -->"Hello World"

		mov cx, 0xffff ; load maximum number in cx
		xor al, al ; load a zero in al

		repne scasb ; find zero in the string

		mov ax, 0xffff ; load maximum number in ax
		sub ax, cx ; find change in cx
		dec ax ; exclude null from length ; ffff - cx - 1 = 11 (strlen)

		jz exit ; no printing if string is empty
		mov cx, ax ; load string length in cx
		
		mov ax, 0xb800
		mov es, ax ; point es to video base

		mov al, 80 ; load al with columns per row
		mul byte [bp+8] ; multiply with y position
		add ax, [bp+10] ; add x position
		shl ax, 1 ; turn into byte offset
		mov di,ax ; point di to required location
		
		mov si, [bp+4] ; point si to string
		mov ah, [bp+6] ; load attribute in ah

			cld ; auto increment mode
nextchar: 	lodsb ; load next char in al
			stosw ; print char/attribute pair
			loop nextchar ; repeat for the whole string

exit:		pop di
		pop si
		pop cx
		pop ax
		pop es
		pop bp
		ret 8 

start:	call clrscr ; call the clrscr subroutine

	mov ax, 30
	push ax ; push x position
	mov ax, 20
	push ax ; push y position
	mov ax, 1 ; blue on black attribute
	push ax ; push attribute
	mov ax, message
	push ax ; push address of message
	call printstr ; call the printstr subroutine
	mov ax, 0x4c00 ; terminate program
	int 0x21  
