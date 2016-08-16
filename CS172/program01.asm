TITLE Programming Assignment 1     (program01.asm)

; Author: Darlene Zouras
; Course / Project ID: Program 1                  Date: 6/26/2016
; Description: This program displays the author's name and title of the program,

INCLUDE Irvine32.inc

; My constants would go here
; ... if I had any!

.data

intro_1		BYTE	"Assembly Language Arithmetic	", 0
intro_2		BYTE	"by Darlene Zouras", 0
intro_3		BYTE	"**EC: Program verifies that second number is less than first.", 0
intro_4		BYTE	"**EC: Program also loops until the user decides to quit.", 0
instruct_1	BYTE	"You will be prompted to enter two numbers. This program will print the sum, difference, product, and quotient with remainder of those two numbers. ", 0
instruct_2	BYTE	"They should be positive integers, and the first number must be greater than the second. ", 0
getFirst	BYTE	"Enter the first number: ", 0
getSecond	BYTE	"Enter the second number: ", 0
num1		DWORD	?
num2		DWORD	?
sum			BYTE	" + ", 0
numSum		DWORD	0
diff		BYTE	" - ", 0
numDiff		DWORD	0
prod		BYTE	" * ", 0
numProd		DWORD	0
quot		BYTE	" / ", 0
numQuot		DWORD	0
rem			BYTE	" R ", 0
numRem		DWORD	0
equals		BYTE	" = ", 0
goodBye		BYTE	"Pretty cool, right? Bye! ", 0
doAgain		BYTE	"(Extra Credit 1) Enter 0 to enter two more numbers, enter any other number to quit.", 0	; EC 1
repeatMath	DWORD	0
repeatNums	BYTE	"(Extra Credit 2) Sorry, the second number must be less than the first. Try again!", 0 ; EC 2
inputErr	DWORD	?

.code
main PROC

; Display name and program title
	mov		edx, OFFSET intro_1			; move intro_1 (name) string to edx
	call	WriteString					; print edx
	call	CrLf						
	mov		edx, OFFSET intro_2			; display intro_2 (program title) to edx
	call	WriteString					; display edx
	call	CrLf						
	mov		edx, OFFSET intro_3			; move intro_3 (ec) to edx
	call	WriteString					; print edx
	call	CrLf						
	mov		edx, OFFSET	intro_4			; move intro_4 (ec) to edx
	call	WriteString					; print edx
	call	CrLf
	call	CrLf						; line breaks

; Display instructions to user
	mov		edx, OFFSET instruct_1		; move instruct_1 string to edx
	call	WriteString					; print edx
	mov		edx, OFFSET instruct_2		; move instruct_2 string to edx
	call	WriteString					; print edx
	call	CrLf
	call	CrLf						; line breaks
	jmp		CHECKINPUT

; Prompt user to enter two integers, save in num1 and num2
	CHECKINPUT:							; THIS LOOP SATISFIES EXTRA CREDIT OPTION 1 & 2
	mov		edx, OFFSET getFirst		; move getFirst string to edx
	call	WriteString					; print edx
	call	ReadInt						; user enters a number
	mov		num1, eax					; move eax to num1
	mov		edx, OFFSET getSecond		; move getSecond string to edx
	call	WriteString					; print edx
	call	ReadInt						; user enters a number
	mov		num2, eax					; move eax to num2
	call	CrLf						; line break
	cmp 	eax, num1					; compare eax (num2) with num1
	JLE		MATH						; if they are equal, jump to the math line

	mov		edx, OFFSET repeatNums		; mov repeatNums string to edx
	call	WriteString					; display the string
	call	CrLf						; line break
	JG		CHECKINPUT					; since the second number is greater,

	MATH:
; Sum of numbers
	mov		eax, num1					; move num1 to eax
	call	WriteDec					; display eax
	mov		edx, OFFSET sum				; move addition sign to edx
	call	WriteString					; display addition sign
	mov		eax, num2					; move num2 to eax
	call	WriteDec					; display num2
	add		eax, num1					; add num1 to eax
	mov		numSum, eax					; move number in eax to numSum
	mov		edx, OFFSET equals			; move equal sign to edx
	call	WriteString					; display equals sign
	call	WriteDec					; display number held in numSum
	call	CrLf						; line break

; Difference of numbers
	mov		eax, num1					; move num1 to eax
	mov		numDiff, eax				; move eax into numDiff
	call	WriteDec					; display eax
	mov		edx, OFFSET diff			; move subtraction sign to edx
	call	WriteString					; display subtraction sign
	mov		eax, num2					; move num2 to eax
	call	WriteDec					; display eax
	mov		edx, OFFSET equals			; move equal sign to edx
	call	WriteString					; display equal sign
	sub		numDiff, eax				; subtract eax (num2) from numDiff (num1)
	mov		eax, numDiff				; move numDiff to eax
	call	WriteDec					; display the difference
	call	CrLf						; line break

; Product of numbers
	mov		eax, num1					; move num1 to eax
	call	WriteDec					; display num1
	mov		numProd, eax				; move eax into numProd
	mov		edx, OFFSET prod			; move multplication sign to edx
	call	WriteString					; display multiplication sign
	mov		eax, num2					; move num2 to eax
	call	WriteDec					; display num2
	mul		numProd						; multiply eax with numProd?
	mov		edx, OFFSET equals			; move equals sign to edx
	call	WriteString					; display equals sign
	call	WriteDec					; display product
	call	CrLf						; line break

; Integer quotient and remainder of numbers
	mov		eax, num1					; move num1 to eax
	call	WriteDec					; dislpay num1
	mov		edx, OFFSET quot			; move the division sign into edx
	call	WriteString					; display division sign
	mov		eax, num2					; move num2 to eax
	call	WriteDec					; display num2
	mov		edx, 0						; must initially set edx to 0
	mov		eax, num1					; move num1 to eax
	div		num2						; divide eax (num1) by num2
	mov		numQuot, eax				; move the quotient (in eax) to numQuot
	mov		numRem, edx					; move the remainder (in edx) to numRem
	mov		edx, OFFSET equals			; move equal sign to edx
	call	WriteString					; display equal sign
	call	WriteDec					; display quotient
	mov		edx, OFFSET rem				; move R to edx
	call	WriteString					; print R
	mov		eax, numRem					; move numRem to eax
	call	WriteDec					; print the remainder
	call	CrLf						; line break

; repeat it all until repeatMath is not equal to 0
	mov		edx, OFFSET doAgain			; move doAgain string to edx
	call	WriteString					; print the string
	call	ReadInt						; User enters a number
	mov		repeatMath, eax				; The number is kept in repeatMath
	call	CrLf						; line break
	cmp 	eax, 0
	JE		CHECKINPUT

; Display terminating message
	mov		edx, OFFSET goodBye			; move goodBye message to edx
	call	WriteString					; print edx
	call	CrLf						; line break

	exit	; exit to operating system
	
main ENDP

; (insert additional procedures here)

END main
