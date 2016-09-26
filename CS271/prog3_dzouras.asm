TITLE Program Template     (template.asm)

; Author: Darlene Zouras
; Course / Project ID: CS271 Programming Assignment #3
; Date: 7/17/2016
; Description: This program calculates and displays composite numbers based on input from the user.
; The program verifies that the user's input is between 1 and 400.
; After that, the program calculates and dislpays all of the composite numbers up to and including the number that the user has entered.

INCLUDE Irvine32.inc

; (insert constant definitions here)

.data
	upperLimit	DWORD	400

	intro1		BYTE	"Calculating composite numbers with loops and procedures.", 0
	intro2		BYTE	"By Darlene Zouras, Summer 2016, CS271.", 0

	instr1		BYTE	"Enter how many composite numbers you would like to see. ", 0
	instr2		BYTE	"It must be a number between 1 and 400. ", 0
	instr3		BYTE	"Enter a number [1-400]: ", 0
	instr4		BYTE	"That entry is out of range.", 0

	prog1		BYTE	"This program will print ", 0
	prog2		BYTE	" composite numbers.", 0

	loopNum		DWORD	?
	compNum		DWORD	3
	printed		DWORD	0
	whiteSpace	BYTE	"   ", 0

	bye1		BYTE	"This program brought to you by Darlene. Goodbye. ", 0

.code
main PROC

	call introduction 					; display the introduction
	call getData						; get input from user
	call calcResults					; print composite numbers
	call farewell						; say goodbye

	exit	; exit to operating system
main ENDP

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; Displays the introduction, which includes the program goal,
; my name, and the current class and term.
introduction PROC
	mov		edx, OFFSET intro1
	call	WriteString
	call 	Crlf
	mov		edx, OFFSET intro2
	call	WriteString
	call	CrLf
	call 	CrLf
	ret
introduction ENDP

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; Print instructions, receive user input, and validate that it is
; within range for this program (in this case between 1 and 400).
getData PROC
		; display the instructions
		mov 	edx, OFFSET instr1
		call 	WriteString
		call 	Crlf
		mov 	edx, OFFSET instr2
		call	WriteString
		call 	Crlf
		call 	Crlf

		; gets input from user
	GETNUM:
		mov 	edx, OFFSET instr3
		call 	WriteString
		call 	ReadInt
		; validate input
		cmp 	eax, 1
		JL	 	OUTOFRANGE
		cmp 	eax, 400
		JG		OUTOFRANGE
		; if in range, jump over the out of range
		JMP		INRANGE

		; if out of range, print error message and jump to GETNUM to try again
	OUTOFRANGE:
		mov		edx, OFFSET instr4
		call 	WriteString
		JMP 	GETNUM

	INRANGE:
		mov		loopNum, eax

		mov		edx, OFFSET prog1
		call	WriteString
		call	WriteDec
		mov		edx, OFFSET prog2
		call	WriteString
		call	crlf
		call	crlf

		ret
getData ENDP


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; This procedure calculates and displays however many composite numbers
calcResults PROC
	; the outer loop will loop loopNum times.
	mov		ecx, loopNum
	L1:
	; Start at compNum
		inc 	compNum;

	; Before moving into the inner loop, hold ecx in loopNum
		mov 	loopNum, ecx
		mov		eax, compNum 
		sub		eax, 1
		mov 	ecx, eax
	; ecx now holds the number being compared - 1

		; This inner loop cycles through every integer below compNum
		L2:
		; if ecx gets to 1, this number must be prime, so skip any print step,
		; increment compNum and start inner loop over with next number.
			cmp 	ecx, 1
			JE		RESTART
		; set edx to 0, it will be used to compare the remainder
			mov		edx, 0
			mov 	eax, compNum
			div 	ecx
		; if there is no remainder when dividing compNum with ecx,
		; the remainder will be 0. print the number, this will return control
		; to the outer loop!
			cmp 	edx, 0
			je		PRINTNUM
		; if the remainder is not 0, loop through inner loop.
			loop 	L2

	; Printnum will print the number when edx equals zero
	PRINTNUM:
		mov 	eax, compNum;
		call 	WriteDec
		inc		printed
		mov		edx, OFFSET whiteSpace
		call	WriteString
		; add a line break every fifth space
		mov 	edx, 0
		mov		eax, printed
		mov		ebx, 10
		div 	ebx
		cmp 	edx, 0
		JNE		INCLOOP
		call 	crlf
		jmp 	INCLOOP

	RESTART:
		mov		ecx, loopNum
		jmp		L1
	INCLOOP:
		mov 	ecx, loopNum
		loop	L1
	
	call	crlf	
	ret
calcResults ENDP

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; This procedure is called at the very end of the program,
; repeats the programmer's name and says goodbye.
farewell PROC
	call	crlf
	mov		edx, OFFSET bye1
	call 	WriteString
	call 	crlf
	ret
farewell ENDP

END main
