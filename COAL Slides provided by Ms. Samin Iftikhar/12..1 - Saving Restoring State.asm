; Final - nested call bp save and restored in all subroutines
[ORG 0x0100]
jmp start

;------------------------------------------------------
FindMin:		cmp ax, bx
				ja bIsSmaller 		; b < a
				cmp ax, cx			; either a or c is min
				ja cIsSmallest		; a>c
				mov dx, ax
				jmp return
bIsSmaller:		cmp ax, bx
				ja bIsSmallest		; b < c		
				mov dx, cx			; c is smallest	
				jmp return	
bIsSmallest:	mov dx, bx
				jmp return
cIsSmallest:	mov dx, cx			;dl = c	

return:			mov [bp-2], dx		;***** What is this space???? Local Var no 1
;------------------------------------------------------
FindMax:		cmp ax, bx
				jb bIsGreater 		; b > a
				cmp ax, cx			; either a or c is max
				jb cIsGreatest		; c > a
				mov dx, ax
				jmp returnFindMax
bIsGreater:		cmp cx, bx
				jb bIsGreatest		; b < c		
				mov dx, cx			; c is greatest	
				jmp returnFindMax	
bIsGreatest:	mov dx, bx
				jmp returnFindMax
cIsGreatest:	mov dx, cx			;dl = c	
returnFindMax:	mov [bp-4], dx		;**** What is this space???? Local Var no 2
				jmp retFromFindMax	
;-------------------------------------------------------		
FindAvg:		; ************Callees responsibility before starting its task******************

				push bp				; save previous base pointer (activation record marker)
				mov bp, sp			; update marker

				;create space for locals, locals not required here
				; Save State
			
				push ax				; Save ax
				push cx
		
				;*************callees task*****************************************************
				mov al, [bp+4]		;Read total from parameters
				mov cl, 3
				div cl				;al = al/cl
				mov [bp+6], al		; save avg in return value

				;*************callees responsibility before leaving****************************
				pop cx
				pop ax				; Restore registers

				;release locals, not required here
				pop bp			; resotre bp
				ret 2			; clear 1 parameter from stack (2xNo of Parameters)
;----------------------------------------------------------------------------------------------

someFunc:			; ************Callees responsibility before starting its task******************

					; Save activiation record marker

					push bp		;save previous bp before pointing to new base
					mov bp, sp

					sub sp, 8	;create space for local vars on stack min,max, total,avg
		
					;Save State / Registers
					push ax		
					push bx
					push cx
					push dx

					;*************callees task*****************************************************
					;Fetch parameters and perform functionality

					mov cx, [bp+4]	;variable c
					mov bx, [bp+6]	;variable b 
					mov ax, [bp+8]	;variable a
		
					;-----------------------------------------
					jmp FindMin
					;--------------Find Total Below-----------

retFromFindMax:		mov dx, 0
					add dx, ax
					add dx, bx
					add dx, cx	;dx contains total
					mov [bp-6], dx

					;---------------Nested Function Call---------------

FindAvgCall:		;***Create Space for return value
					push ax			;***creating space for avg with junk data

					;***Pass parameters
					push dx			;***(parameter) total pushed on stack

					;----------Call Function
					call FindAvg
					;------Get returned value
					pop dx		;pop avg in dx

					mov [bp-8], dx	; save avg in local variable
					cmp byte[bp-8], 0xC
					jae AvgIsGreater
					mov dl, [bp-2]
					jmp ReturnFunc

AvgIsGreater:		mov dl, [bp-4]
ReturnFunc:			[bp+10], dl		;Copying answer on stack
		
					;*************callees responsibility before leaving****************************		
					;Restore State
					pop dx
					pop cx
					pop bx
					pop ax		

					add sp, 8		; local variable space removed min, max, total, avg

					pop bp
					ret 6			; Pop return address and increment sp by 6 Callee clearing 3 params from stack
;----------------------------------------------------------------------------------------------
start:			mov ax, 0x00CC		; Creating space for Return Values on stack
				push ax				; dummy push

				mov ax, 0xA
				push ax				; see Push instruction 2-126 of 88 manual
				mov ax, 0xB
				push ax
				mov ax, 0xC
				push ax

				call someFunc		; what if we do not pop return value from stack?
	
				pop dx				; ans is in dx

				MOV  AX, 0x4C00     ; Terminate Program 
				INT  0x21               
