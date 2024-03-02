; example 9.2  - differentiate left and right shift keys with scancodes
[org 0x0100]
jmp start

;------------------------------------------------------
; keyboard interrupt service routine

kbisr:		push ax
			push es
	
			mov ax, 0xb800
			mov es, ax						; point es to video memory

			;************************************
			; TEST YOUR CONCEPTS
			; WHAT IS FOLLOWING LINE DOING

			in al, 0x60						; read a char from keyboard port, scancode

			;************************************
			; TEST YOUR CONCEPTS
			; GIVEN THE PRESS CODE OF SHIFT LEFT, WHAT WILL BE ITS RELEASE CODE
	
			cmp al, 0x2a					; is the key left shift
			jne nextcmp					; no, try next comparison
			mov byte [es:0], 'L'			; yes, print L at top left
			mov byte [es:1], 01000111B		; Attribute Byte for L
			jmp nomatch						; leave interrupt routine

nextcmp:	cmp al, 0x36					; is the key right shift
			jne nomatch						; no, leave interrupt routine
			mov byte [es:0], 'R'			; yes, print R at top left
			mov byte [es:1], 00000111B		; Attribute Byte for R

			;************************************
			; TEST YOUR CONCEPTS
			; WHAT IF WE FORGET EOI SIGNAL???

nomatch:		mov al, 0x20
			out 0x20, al					; send EOI to PIC
			
			pop es
			pop ax

			;************************************
			; TEST YOUR CONCEPTS
			; WHAT IS EXACT FUNCTIONALITY OF IRET????

			iret
;-------------------------------------------------------
start:			xor ax, ax
			mov es, ax					; es=0, point es to IVT base
	
			cli						; disable interrupts

			
			; 9th entry of IVT --> ([36]:[38] = csabc:ipxyz) --> Pointing to Default Keyboard Handler

			mov word [es:9*4], kbisr		; store offset at n*4....... csabc:kbisr	
			mov [es:9*4+2], cs			; store segment at n*4+2
			
			; 9th entry of IVT --> ([36]:[38] = 19F5:kbisr) --> Pointing to Our hanlder now
			
			;************************************
			; TEST YOUR CONCEPTS
			; AT WHAT RELATIVE ADDRESS YOU WILL FIND BASE ADDRESS OF INT 20???

			sti						; enable interrupts 
			;************************************
			; TEST YOUR CONCEPTS
			; WHAT IF WE FORGET CLI AND/OR STI HERE


l1:		 	jmp l1						; infinite loop 