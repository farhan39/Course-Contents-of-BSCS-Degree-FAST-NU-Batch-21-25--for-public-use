; ex:2.1 - a program to add three numbers using memory variables

[org 0x0100]	;What is this line doing?

mov ax, [num1]	;load num1 in ax
mov bx, [num2]	;load num2 in bx
add ax, bx	;ax = ax + bx
mov bx, [num3]	;load num3 in bx
add ax, bx	;ax = ax + bx
mov [num4], ax	;write sum in num4

mov ax, 0x4c00	;terminate the program
int 0x21

		; data is being stored after code
num1: dw 5	; label num1 is defined as a word (16bits) and 5 will be stored there
num2: dw 10
num3: dw 15
num4: dw 0
;-------------------------------------------------------------
;TO DO
;-------------------------------------------------------------
;Opcode A1: move data from memory to AX
;num1 has been translated to 1700
;[1700]: (0000 0017) ---> 0017 (Big Endian) ---> 1700 (Little Endian)
;Difference between MOV REG, num1 VS MOV REG, [num1]
;num is an address [num1] is content of that address

;8B1E: ??? Verify opcode of MOV BX, [MemoryAddress] throughout the program.
;[1900] ???
;Why are memory addresses of data 17,19,1B,1D ???
;01D8??? Verify opcode throughout the program.
;Opcode A3 ???
;[1D00]???

;What is MOV AX,[0117] ???
;0x0017 + 0x100 = 0117 = (?) in little endian

;You can see the content of 0x117 highlighted grey with cmd