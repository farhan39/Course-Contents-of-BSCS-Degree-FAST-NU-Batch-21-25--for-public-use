; Return value
[ORG 0x0100]
jmp start

; data A,B,C removed
min:	db 0xF
max:	db 0x0
total:	db 0x0
avg:	db 0x0
; Ans or Return Value Removed

;------------------------------------------------------
FindMinAndMax:	cmp ax, bx
				ja bIsSmaller 	; b < a
				cmp ax, cx	; either a or c is min
				ja cIsSmallest	; a>c
				mov dx, ax
				jmp return
bIsSmaller:		cmp ax, bx
				ja bIsSmallest	; b < c		
				mov dx, cx	; c is smallest	
				jmp return	
bIsSmallest:	mov dx, bx
				jmp return
cIsSmallest:	mov dx, cx	;dl = c
		
return:			mov [min], dx	
;------------------------------------------------------
FindMax:		cmp ax, bx
				jb bIsGreater 	; b > a
				cmp ax, cx	; either a or c is max
				jb cIsGreatest	; c > a
				mov dx, ax
				jmp returnFindMax
bIsGreater:		cmp cx, bx
				jb bIsGreatest	; b < c		
				mov dx, cx	; c is greatest	
				jmp returnFindMax	
bIsGreatest:	mov dx, bx
				jmp returnFindMax
cIsGreatest:	mov dx, cx	;dl = c		
returnFindMax:	mov [max], dx	
				jmp retFromFindMax		
;-------------------------------------------------------
someFunc:		mov bp, sp	; ***Read Parameters
				mov cx, [bp+2]	;variable c
				mov bx, [bp+4]	;variable b 
				mov ax, [bp+6]	;variable a

				;-----------------------------------------
				jmp FindMinAndMax
				;--------------Find Total Below-----------

retFromFindMax:	mov dx, 0
				add dx, ax
				add dx, bx
				add dx, cx
				mov [total], dx

				;--------------Find Avg Below-------------				
		
				mov al, [total]
				mov cl, 3
				div cl		;al = al/cl
				mov [avg], al				

				;--------------if else to set return value---

				cmp byte[avg], 0xC
				jae AvgIsGreater
				mov dl, [min]
				jmp ReturnFunc
AvgIsGreater:	mov dl, [max]

ReturnFunc:		mov dh, 0
				mov [bp+8], dx		; ***Copying answer in ret value space on stack
		
				ret 6			; ***Pop return address and increment sp by 6 
								; ***Callee clearing the stack, removing parameters
;----------------------------------------------------------------------------------
start:	mov ax, 0xCCCC	; ***Creating space for Return Values on stack
		push ax			; ***dummy push

		mov ax, 0xA		; ***Parameters
		push ax			; see 2-126 of 88 manual
		mov ax, 0xB
		push ax
		mov ax, 0xC
		push ax

		call someFunc		; ***what if we do not pop return value from stack?
		pop dx				; ***Saving returned value in dx

		MOV  AX, 0x4C00     ; Terminate Program 
		INT  0x21               
