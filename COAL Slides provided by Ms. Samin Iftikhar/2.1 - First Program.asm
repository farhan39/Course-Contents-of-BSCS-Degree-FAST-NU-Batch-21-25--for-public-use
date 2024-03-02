; To start a comment a semicolon is used
; the assembler ignores everything else on the same line.
; this program adds three numbers in registers

[org 0x0100]	;we will see org directive later

mov ax, 5	; AX = 5
mov bx, 10	; BX = 10
add ax, bx	; AX = AX + BX
mov bx, 15	; BX = 15
add ax, bx	; AX = AX + BX

mov ax, 0x4c00	;terminate the program
int 0x21

; The ending lines are related more to the operating system than to
; assembly language programming. It is a way to inform DOS that our
; program has terminated so it can display its command prompt
; again. The computer may reboot or behave improperly if this
; termination is not present.

; Lecture Topics:
; 1. Instructions Addresses
; 2. Inst. Opcodes
; 3. Little Endian VS Big Endian
; 4. Size of COM file = 18Bytes
; 5. Overview of AFD
; 6. Registers
; 7. Why is 1st instruction on 0x100
; 8. Debug program and watch Registers
