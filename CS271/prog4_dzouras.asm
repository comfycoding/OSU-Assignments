TITLE Program Template     (template.asm)

; Author: Darlene Zouras
; CS 271 Summer 2016, Program 4                Date: 7/25/2016
; Description: This program generates a certain number of random integers,
; and then displays, arranges, and presents results of some calculations
; based off of those integers.

INCLUDE Irvine32.inc

.data

	listMax 	EQU		200
	listMin		EQU		10
	listHi		EQU	 	999
	listLo		EQU 	100
	two			EQU		2

		; request holds the number of items to hold in the array
	request		DWORD	?
	array		DWORD	listMax DUP(?)

	titleU		BYTE	"Unsorted list: ", 0
	titleS		BYTE	"Sorted list: ", 0

.code
main PROC

	call 	introduction 		; call the introduction

	push 	OFFSET request 		; push the address of request onto stack
	call 	getnum 				; obtain a number from the user

	push 	OFFSET array
	push	request
	call 	fillArray			; fill the array with random integers

	push 	OFFSET array
	push	request
	push	OFFSET titleU
	call	printArray			; prints the current contents of the array

	push 	OFFSET array
	push	request
	call 	sortArray 			; sort the contents of the array

	push 	OFFSET array
	push	request
	push	OFFSET titleS
	call 	printArray 			; print the sorted array

	push 	OFFSET array
	push 	request
	call 	printMedian			; calculate and display the list median

	exit
main ENDP

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; The introduction prints some information about this program.
introduction PROC

.data
	intro1 		BYTE	"Presenting, Sorting, and Calculations with Random Integers.", 0
	intro2		BYTE	"Programmed by Darlene Zouras", 0
	intro3		BYTE	"This program fills an array with random integers. ", 0
	intro4		BYTE	"You will decide on the size of the array. ", 0
	intro5		BYTE	"Then, the array will be sorted and the median displayed. ", 0

.code
	mov 	edx, OFFSET intro1
	call 	WriteString
	call 	crlf
	mov 	edx, OFFSET intro2
	call 	WriteString
	call 	crlf
	call 	crlf
	mov		edx, OFFSET intro3
	call 	WriteString
	mov		edx, OFFSET intro4
	call 	WriteString
	mov		edx, OFFSET intro5
	call 	WriteString
	call 	crlf
	call 	crlf

	ret
introduction ENDP

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; This procedure requests that the user enter a number within a range,
; validates the input, and then returns that number.
; PARAMETERS: request (reference)
; REGISTERS: ebx, edx, eax
getnum PROC
.data
	getdat1		BYTE	"Please enter a number between 10 and 200: ", 0
	getdat2		BYTE 	"Out of range. ", 0

.code
	REQUESTSIZE:
		push 	ebp 		; sets up the stack frame
		mov		ebp, esp	; ebp now points to the top of the stack
		mov		ebx, [ebp + 8]	; [ebp + 8] should hold address of register

		mov		edx, OFFSET getdat1
		call 	WriteString
		call 	ReadInt
			; validate input
		cmp 	eax, listMin
			; jump if less than or equal
		JLE 	OUTOFRANGE
		cmp 	eax, listMax
			; jump if greater than or equal
		JGE	 	OUTOFRANGE
		JMP 	INRANGE

	OUTOFRANGE:
		mov 	edx, OFFSET getdat2
		call 	WriteString
		call	crlf
		jmp 	REQUESTSIZE

	INRANGE:
		mov 	[ebx], eax	; move the entered number into request address!
		pop 	ebp			; restore stack
		ret 	4			; should remove @ request from the stack
getnum ENDP

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; The fillArray procedure fills an array (the size has just been determined by
; the user), and fills that array with random integers.
; PARAMETERS: request (value), array (reference)
fillArray PROC
	push	ebp
	mov		ebp, esp		; ebp points to top of stack 
							; ebp + 8 = value of request
							; ebp + 12 = @ array
	mov		edi, [ebp + 12] ; edi points to first spot in array
	mov		ecx, [ebp + 8]	; counter is the value of request

	mov		edx, listHi
	sub		edx, listLo		; edx = absolute range
	cld

	FILL:
		mov		eax, edx
		call	RandomRange
		add		eax, listLo
		stosd
		loop	FILL

	pop		ebp
	ret		8
fillArray ENDP

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; printArray prints each item in the array.
; PARAMETERS: array (reference), request (value), title (reference)
; REGISTERS: eax, edx, ebx, ecx
printArray PROC
.data
	spaces	BYTE	"   ", 0
.code
	push	ebp
	mov		ebp, esp		; ebp points to top of stack 
							; ebp + 8 = @ title of the array 
							; ebp + 12 = value of request
							; ebp + 16 = @ array
	mov		edx, [ebp + 8]
	call	WriteString
	call	Crlf

	mov		ecx, [ebp + 12]
	mov		esi, [ebp + 16]
	mov		ebx, 1
	cld		; direction = forward
	PRINTLOOP:
		lodsd
		call	WriteDec
		mov		edx, OFFSET spaces
		call	WriteString
		mov		eax, ebx
		push	ebx
		mov		edx, 0
		mov		ebx, 10
		div		ebx
		cmp		edx, 0
		JNE		DOLOOP
		call	crlf
	DOLOOP:
		pop		ebx
		inc		ebx
		loop	PRINTLOOP		

	call	Crlf
	pop		ebp
	ret		12
printArray ENDP

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; sortArray sorts the items in the array in ascending order.
; this BubbleSort algorithm refers heavily to the code found in the textbook!!!
; PARAMETERS: array (refrence), request (value)
; calls the exchange procedure, exArray
sortArray PROC
	push	ebp
	mov		ebp, esp		; ebp points to top of stack 
							; ebp + 8 = value of request
							; ebp + 12 = @ array
	
	mov		ecx, [ebp + 8]	; ecx holds the value of request
	dec		ecx

	L1:
		push	ecx
		mov		esi, [ebp + 12] ; esi points to the first spot in the array
		
	L2:
		mov		eax, [esi]		; get array value
		cmp		[esi + 4], eax	; compare adjacent values
		JG		L3				; jump if [ESI] <= [ESI + 4], no exchange
		xchg	eax, [esi + 4]
		mov		[esi], eax
	L3:
		add		esi, 4
		loop	L2

		pop		ecx
		loop	L1

	pop		ebp
	ret		8
sortArray ENDP


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; The printMedian determines the middle item in the array and displays it.
; PARAMETERS: request (value), array (reference)
; REGISTERS: ebx, edx, eax
printMedian PROC
.data
	printmed1	BYTE	"The median is found in array spot ", 0
	printmed2	BYTE	"The median is: ", 0

.code
	call	Crlf
	mov 	edx, OFFSET printmed1
	call 	WriteString

	push	ebp
	mov		ebp, esp		; ebp now points to top of stack
							; ebp + 8 is the value of request
							; ebp + 12 is the address of array

	mov		eax, [ebp + 8]  ; move the value of request into eax
	mov		ebx, 2
	mov		edx, 0
	div		ebx
	call	WriteDec
	call	Crlf
	mov		ecx, eax
	mov		esi, [ebp + 12]
	cld
	MOVETOMID:
		lodsd
		loop	MOVETOMID

	mov		edx, OFFSET printmed2
	call	WriteString
	; find the value in the middle of the array 
	; move that location to eax
	call 	WriteDec
	call 	crlf

	pop		ebp			; restore stack
	ret		8			; remove request and @ array from stack
printMedian ENDP

END main
