; a program to add three numbers using indirect addressing

[org 0x0100]

mov bx, num1		; Point bx to first number
mov ax, [bx]		; load first number in ax, [si], [di], [bp]

add bx, 2			; move bx to next number
add ax, [bx]		; add second number in ax

add bx, 2			; move bx to next number
add ax, [bx]		; add third number in ax

add bx, 2			; move bx to next number
mov [bx], ax		; save sum at last index

mov ax, 0x4c00		;terminate the program
int 0x21

num1:	dw 5, 10, 15, 0	




;1C -> 0500
;1E -> 0A00
;20 -> 0f00
;22 -> 0000
; Total Size of COM file ?
; Verify from .com properties

; How to move BX backward???
; What if the data is of 1 byte ?