; Passing Parameters
[ORG 0x0100]
jmp start

min:	db 0xF
max:	db 0x0
total:	db 0x0
avg:	db 0x0
ans:	db 0x0
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

				cmp byte[avg], 0xC
				jae AvgIsGreater
				mov al, [min]
				jmp ReturnFunc

AvgIsGreater:	mov al, [max]
ReturnFunc:		mov [ans], al
				ret 6			; ***Pop return address and increment sp by 6
								; ***removing parameters
;---------------------------------------------------------------------------------
start:		mov ax, 0xA		; *** Passing Parameters
			push ax			; see 2-126 of 88 manual
			mov ax, 0xB
			push ax
			mov ax, 0xC
			push ax
			call someFunc

			MOV  AX, 0x4C00         ; Terminate Program 
			INT  0x21               
