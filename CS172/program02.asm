TITLE Programming Assignment 2     (program02.asm)

; Author: Darlene Zouras
; Course / Project ID: CS 271 Programming Assignment #2            Date: 7/5/2016
; Description:

INCLUDE Irvine32.inc

; (insert constant definitions here)
NAME_MAX = 20

.data

intro_1		BYTE	"Calculating Fibonacci Numbers		by Darlene Zouras", 0
get_name	BYTE	"What is your name? ", 0
confName	BYTE	", is that right? (enter 0 if it is right, any other number if wrong) ", 0
greet		BYTE	"Hello, ", 0
userName	BYTE	(NAME_MAX+1) DUP(0)
instruct1	BYTE	"Please enter the number of Fibonacci terms to be displayed.", 0
instruct2	BYTE	"(The number must be an integer between 1 and 46.)", 0
numHigh		BYTE	"Sorry, that number is too high. Try again.", 0
numLow		BYTE	"Sorry, that number is too low. Try again.", 0
runFib		BYTE	"The fibonacci numbers are: ", 0
fibNum		DWORD	?
fibSpace	BYTE	"     ", 0
bye			BYTE	"Goodbye, ", 0
fibp		DWORD	1
checkNL		DWORD	5


.code
main PROC

; Display program title and programmer name
mov		edx, OFFSET intro_1		; move intro_1 to edx
call	writeString				; print the string in edx (intro string)
call	CrLf

; Get user name, greet user by name
GETNAME:
mov		edx, OFFSET get_name	; move name request to edx
call	writeString				; print string
mov		edx, OFFSET userName
mov		ecx, NAME_MAX
call	readString				; get name from user

mov		edx, OFFSET userName	; move user's name to edx
call	writeString				; print user's name
mov		edx, OFFSET confName	; move name confirmation to edx
call	writeString				; print name confirmation
call	readInt					; read integer from user
cmp		eax, 0					; compare the input to 0
JNE		GETNAME					; jump to GETNAME block if number is not 0

mov		edx, OFFSET greet		; move greet string to edx
call	WriteString				; print greeting
mov		edx, OFFSET userName	; move name to edx
call	WriteString				; print name
call	Crlf

; Display instructions
ENTERNUM:
mov		edx, OFFSET instruct1	; move first line of instructions to edx
call	writeString				; print line
call	Crlf
mov		edx, OFFSET instruct2	; move first line of instructions to edx 
call	writeString				; print line
call	Crlf

; User enters number of fibonacci terms to display (between 1 to 46)
call	ReadInt					; read an integer from the user

; (validate user input)
cmp		eax, 1					; compare entered number to 1
JL		TOOLOW					; if less than 1, jump to toolow message
cmp		eax, 46					; compare entered number to 46
JG		TOOHIGH					; if greater than 46, jump to toohigh message
JMP		CONFNUM					; if neither case, move to CONFNUM

TOOHIGH:
mov		edx, OFFSET numHigh		; move string to edx
call	writeString				; print that number is too high
call	Crlf
JMP		ENTERNUM				; jump back up to try again

TOOLOW:
mov		edx, OFFSET numLow		; move string to edx
call	WriteString				; print that number is too low
call	Crlf
JMP		ENTERNUM				; jump back up to try again

CONFNUM:
mov		fibNum, eax				; save the entered number into fibNum
mov		edx, OFFSET runFib				; move string to edx
call	writeString				; print string
call	Crlf					

; Calculate and display fibonacci numbers up to and including nth term
mov		ecx, fibNum				; move fibNum to the ecx register for loop counting
mov		fibNum, 0				; setting fibNum to 0 helps to determine line breaks

; 5 terms per line, 5 spaces between terms
FIBGEN:
cmp		fibNum, 1				
JLE		PRINT1

CHECKNEWLINE:
mov		edx, 0
mov		eax, fibNum
div		checkNL
cmp		edx, 0
JE		NEWLINE
JMP		CALCFIB					; if FibNum is 2, jump over print 1 block

PRINT1:
mov		eax, 1					; move 1 to eax;
call	WriteDec				; print eax
mov		edx, OFFSET fibSpace	; move the five spaces into edx to be printed
call	WriteString				; prints five spaces
inc		fibNum					; increments fibNum
JMP		RUNLOOP

NEWLINE:
call	Crlf
CALCFIB:
mov		eax, fibp				; move parent number to eax
add		eax, fibp				; add them together
call	WriteDec				; print the integer
mov		edx, OFFSET fibSpace	; move the five spaces into edx to be printed
call	WriteString				; print five spaces
mov		fibp, eax				; fibNum becomes the parent for next round
inc		fibNum
JMP		RUNLOOP

RUNLOOP:
loop	FIBGEN
call	Crlf
	
; FIGURE OUT HOW TO DETERMINE EVERY 5TH NUMBER????

; Display goodbye by name
SAYBYE:
mov		edx, OFFSET bye			; move goodbye string to edx
call	writeString				; print string
mov		edx, OFFSET userName			; move name to edx
call	writeString				; print name
call	Crlf


	exit	; exit to operating system
main ENDP

; (insert additional procedures here)

END main
