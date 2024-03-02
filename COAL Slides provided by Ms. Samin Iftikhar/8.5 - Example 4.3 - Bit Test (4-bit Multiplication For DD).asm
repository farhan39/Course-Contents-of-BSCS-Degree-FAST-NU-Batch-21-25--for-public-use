[org 0x0100]
jmp start

multiplicand: dd 0xABCDD4E1, 0
multiplier: dd 0xAB5C32
result: dd 0, 0

start: 
		mov cx, 32 ; initialize bit count to 32
		mov bx, [multiplicand]
	
checkbit: 
		shr word[multiplier + 2], 1
		rcr word[multiplier], 1
		jnc skip
 
		mov ax, [multiplicand]
		add [result], ax
		mov ax, [multiplicand+2]
		adc [result+2], ax
		mov ax, [multiplicand+4]
		adc [result+4], ax
		mov ax, [multiplicand+6]
		adc [result+6], ax

skip: 
	shl word [multiplicand], 1		;	 1300
	rcl word [multiplicand+2], 1	;	*  50
	rcl word [multiplicand+4], 1		
	rcl word [multiplicand+6], 1	; 	 0000
									;	6500X		;For this cross, we shift the multiplicand to left
									;				;so that the next addition of multiplicand is like
	dec cx							;	65000		;13000 and next 130000 and so on.
	jnz checkbit
	
mov ax,0x4c00
int 0x21