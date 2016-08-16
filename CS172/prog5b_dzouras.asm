TITLE Program Template     (template.asm)

; Author: Darlene Zouras
; CS 271 Summer 2016 | Program 5 Option B        Date: 8/3/2016
; Description: Uses recursion to test 

INCLUDE Irvine32.inc

	N_HIGH = 12
	N_LOW = 3
	MAXSIZE = 50

.data

	intro1		BYTE	"Program 5B: Recursion using MASM Assembly Language. ", 0
	intro2		BYTE	"Written by Darlene Zouras for CS271 Summer 2016. ", 0
	intro3		BYTE	"This program will display a combinations problem. ", 0
	intro4		BYTE	"Enter an answer, and it will let you know if you're right! ", 0

	numProbs	DWORD	0
	numRight	DWORD	0

	n			DWORD	?
	r			DWORD	?
	answer		DWORD	?
	result		DWORD	?

	res1	BYTE	"There are ", 0
	res2	BYTE	" possible combinations of ", 0
	res3	BYTE	" items from a set of ", 0
	res4	BYTE	". ", 0
	res5	BYTE	"Your answer was: ", 0

	correct	BYTE	"You were correct! ", 0
	wrong	BYTE	"Your guess was wrong. ", 0

.code

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; the PrintStr macro prints a string that it receives, while saving
; the edx registers
; the PrintDec macro prints an integer, also reserves the eax register
PrintStr	macro string
	push		edx
	mov			edx, string
	call		WriteString
	pop			edx
	endm

PrintDec	macro num
	push		eax
	mov			eax, num
	call		WriteDec
	pop			eax
	endm

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; MAIN !!!!
main PROC

	call introduction

	pushad
	push		OFFSET n
	push		OFFSET r
	call		showProblem
	popad
		
	pushad
	push		OFFSET answer
	call		getData
	popad

	pushad
	push		n
	push		r
	push		OFFSET result
	call		combinations; pass n and r by value. result by address
	popad
		
	pushad
	push		n
	push		r
	push		result
	push		answer
	call		showResults; pass n, r, answer, result by value. numRight by ref
	call		crlf
	popad

	exit	; exit to operating system
main ENDP

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; The introduction procedure displays some information about the assignment, 
; my name, and some instructions for the user.
introduction PROC
	PrintStr	OFFSET intro1
	call		crlf
	PrintStr	OFFSET intro2
	call		crlf
	PrintStr	OFFSET intro3
	PrintStr	OFFSET intro4
	call		crlf
	ret
introduction ENDP

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; The showProblem procedure generates two random numbers to be calculated in a 
; combination problem.
showProblem PROC
.data
	prob1		BYTE	"Number of elements in the set: ", 0
	prob2		BYTE	"Number of elements to choose from the set: ", 0
	prob3		BYTE	"How many ways can you choose ", 0
	prob4		BYTE	" from ", 0
	prob5		BYTE	"? ", 0

.code
	push		ebp				; set up the stack frame
	mov			ebp, esp		; ebp now points to the top of the stack
							; ebp + 8 = @ r
							; ebp + 12 = @ n
	mov			edi, [ebp + 8]	
	mov			ebx, [ebp + 12]

	; generate two random numbers
	push	eax
	mov		edx, N_HIGH
	sub		edx, N_LOW
	mov		eax, edx
	call	RandomRange
	add		eax, N_LOW
	mov		[ebx], eax

	mov		edx, [ebx]
	sub		edx, 1
	mov		eax, edx
	call	RandomRange
	add		eax, 1
	mov		[edi], eax
	pop		eax

	; then print the problem
	PrintStr	OFFSET prob1
	PrintDec	[ebx]			; print n
	call		crlf
	PrintStr	OFFSET prob2
	PrintDec	[edi]
	call		crlf			; print r
	PrintStr	OFFSET prob3
	PrintDec	[edi]
	PrintStr	OFFSET prob4
	PrintDec	[ebx]
	PrintStr	OFFSET prob5

	pop			ebp
	ret			8
showProblem ENDP

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; the getData procedure receives input from the user, they make a guess 
; for how many possible ways the two numbers can be comibned.
; Parameters: answer (by reference)
getData	PROC
.data
	answered	BYTE	"You entered ", 0
	promptagain	BYTE	"Try again, enter a number: ",0
	tempString	BYTE	?

.code
	push	ebp			; set up stack frame
	mov		ebp, esp	; ebp points to top of stack frame
						; ebp + 8 = @ answer

getAnswer:	
	mov		edx, OFFSET tempString
	mov		ecx, MAXSIZE
	call	ReadString

	mov		ecx, eax		; eax holds length of string, set to loop counter
	mov		esi, OFFSET tempString	; edx holds the string, set it to esi

	cld

	loopstring:
	push	eax
	push	ebx
	mov		ebx, [ebp + 8]
	mov		eax, [ebx]	; this will multiply value of answer by 10
	mov		ebx, 10d
	mul		ebx
	mov		ebx, [ebp + 8]
	mov		[ebx], eax
	pop		ebx
	pop		eax

	mov		al, [esi]
	inc		esi
	sub		al, 48d			; subtract 48 from the ASCII value to get the integer

	cmp		al, 0			; this block confirms that the entry is a number
	jl		notnumber
	cmp		al, 9
	jg		notnumber

addnum:
	mov		ebx, [ebp + 8]		; ebx holds @ answer
	add		[ebx], al			; add eax to value of answer
	loop	loopstring	
	jmp		gotAnswer

notnumber:
	PrintStr	OFFSET promptagain
	push		eax
	push		ebx
	mov			ebx, [ebp + 8]
	mov			eax, 0
	mov			[ebx], eax
	pop			ebx
	pop			eax
	jmp			getanswer

gotAnswer:
	call		crlf
	pop			ebp
	ret			4
getData ENDP

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; the Combinations problem calculates the answer to  possible combination of 
; selecting r items of n:
combinations PROC
	push	ebp
	mov		ebp, esp
				; ebp + 8 = @ result
				; ebp + 12 = r
				; ebp + 16 = n
	mov		ebx, [ebp + 16]
	mov		ecx, [ebp + 12]

	; 1) calculate n!
	push	ebx			; factorial needs both to work with
	push	ebx
	call	factorial			; there will be THREE CALLS for this calculation
	mov		ebx, [ebp + 8]
	mov		[ebx], eax		; RESULT CURRENTLY HOLDS n!

	; 2) calculate r!
	push	ecx
	push	ecx
	call	factorial
	mov		edx, eax		; EDX CURRENTLY HOLDS r!
	
	; 3) calculate (n-r)!
	mov		ebx, [ebp + 16]
	sub		ebx, ecx				; ebx now holds n-r, get (n-r)!
	push	ebx
	push	ebx
	call	factorial		; eax now holds (n-r)!

	; 4) multiply r! * (n - r)!
	; [ebp + 8] holds r!, edx holds r!, eax, holds (n-r)!
	mul		edx			; eax holds r! * (n-r)!
	mov		ecx, eax	; move it to ecx
	mov		edx, 0
	mov		ebx, [ebp + 8]
	mov		eax, [ebx]	; move n! into eax
	div		ecx			; eax / ecx = n! / r!(n-r)!
	mov		[ebx], eax	; move the result into @ result
	
	pop		ebp
	ret		12
combinations ENDP

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; Calculates the facorial of a number.  
factorial PROC
	; base case: the number is 1 (return)
	push	ebp
	mov		ebp, esp
				; ebp + 8 holds x
				; ebp + 12 holds current product
	
	mov		ebx, [ebp + 8]
	mov		eax, [ebp + 12]
	dec		ebx
	cmp		ebx, 1
	je		quit			; the base case is when x = 1

recurse:
	mul		ebx
	push	eax
	push	ebx
	call	factorial

quit:
	pop		ebp
	ret		8
factorial ENDP
	
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; showResults prints the correct answer, and says whether the user is right or
; wrong. (To fit EC requirements, also keeps tally of correct answers)
showResults	PROC
	push		ebp
	mov			ebp, esp		; ebp points to top of stack
						; ebp + 8 = answer
						; ebp + 12 = result
						; ebp + 16 = r
						; ebp + 20 = n

	PrintStr	OFFSET res1
	PrintDec	[ebp + 12]
	PrintStr	OFFSET res2
	PrintDec	[ebp + 16]
	PrintStr	OFFSET res3
	PrintDec	[ebp + 20]
	PrintStr	OFFSET res4
	call		crlf
	PrintStr	OFFSET res5
	PrintDec	[ebp + 8]
	call		crlf

	mov			ecx, [ebp + 8]
	mov			ebx, [ebp + 12]

	cmp			ecx, ebx
	JE			userCorrect
	jmp			userIncorrect

	userCorrect:
		PrintStr	OFFSET correct
		jmp			return 
	userIncorrect:
		PrintStr	OFFSET wrong
	return:
		pop			ebp
		ret			16
showResults ENDP

END main
