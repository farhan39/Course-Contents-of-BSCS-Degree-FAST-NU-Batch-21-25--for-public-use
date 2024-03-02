; Example 9.4 - Interrupt Chanining - another attempt to terminate program with Esc that hooks keyboard interrupt
	[org 0x100]
	jmp start

message1: db 10, 13, 'User entered something... $'
oldisr: dd 0									; space for saving old isr 1st 2 bytes for Offset, next 2 for cs
;---------------------------------------------------------------
; keyboard interrupt service routine
kbisr:		push ax
			push es

			mov ax, 0xb800
			mov es, ax						; point es to video memory

			in al, 0x60						; read a char from keyboard port

			cmp al, 0x2a					; is the key left shift
			jne nextcmp						; no, try next comparison
			mov byte [es:0], 'L'			; yes, print L at top left
			jmp nomatch						; leave interrupt routine

nextcmp:	cmp al, 0x36					; is the key right shift
			jne nomatch						; no, leave interrupt routine
			mov byte [es:0], 'R'			; yes, print R at top left

nomatch:	; mov al, 0x20
			; out 0x20, al					; DONT send EOI to PIC
			
			pop es
			pop ax
			jmp far [cs:oldisr]				; call the original ISR
			
			; iret
;---------------------------------------------------------------
start:		xor ax, ax
			mov es, ax								; point es to IVT base
			
			mov ax, [es:9*4]
			mov [oldisr], ax						; save offset of old routine
			mov ax, [es:9*4+2]
			mov [oldisr+2], ax						; save segment of old routine

			cli										; disable interrupts
			mov word [es:9*4], kbisr				; store offset at n*4
			mov [es:9*4+2], cs						; store segment at n*4+2
			sti										; enable interrupts
			
l1:			mov ah, 0								; service 0 – get keystroke			
			int 0x16								; call BIOS keyboard service

			mov dx, message1 						; greetings message
			mov ah, 9 								; service 9 – write string
			int 0x21 								; dos services


			cmp al, 27								; is the Esc key pressed
			jne l1									; if no, check for next key

			mov ax, 0x4c00							; terminate program
			int 0x21