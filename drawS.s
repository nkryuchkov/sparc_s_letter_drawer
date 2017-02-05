 	.global drawS			! Declare the symbol to be globally visible
							! so we can call this function from other 
							! module

	.section ".text"		! The test segment begins here

/* 
 * Function Name: drawS()
 * Function Prototype: void drawS ( long sWidth, long sChar, long FillerChar,
									long borderChar);
 * Description: perform the actual outputting of individual characters
 * such that the ‘S’ character is displayed with the user-supplied values
 * Parameters: long sWidth, long sChar, long FillerChar, long borderChar
 * Side Effect: performs the actual outputting of individual characters
 * Error: none
 * Return Value: none
 */

 drawS:
 	save	%sp, -96, %sp 	! Save caller's window if different than -96
	! we assume %l0 register for line, %l1 for section, %l2 for borderWidth
	mov		%i0, %o0		! Pass sWidth to the function
	call	numOfDigits		! Make function call
	mov		10, %o1			! Fill delay slot
	mov		%o0, %l2		! Save a result in borderWidth local variable
 
 /* Top border */
	clr 	%l0				! Clear line local variable
 first_loop:
	cmp		%l0, %l2		! if (line >= borderWidth)
	bge		first_loop_end	! break
	nop						! Delay slot for branch instruction
	mov 	%l2, %o0		! 1st parameter
	call	.mul			! Make function call
	mov 	2, %o1			! Fill delay slot passing 2nd parameter
	add		%o0, %i0, %o1	! Add borderWidth*2 and sWidth and pass to the function
	call 	printSegment	! Make function call
	mov		%i3, %o0		! Pass parameter to the function
	call	printChar		! Make function call
	mov 	'\n', %o0		! Pass parameter to the function
	inc 	%l0				! Increase a counter
	ba		first_loop		! Do a loop
	nop						! Delay slot for branch instruction
 first_loop_end:
	
 /* S character */
	clr 	%l1				! section = 0
 /* Top middle and bottom lines */
 second_loop:
	cmp		%l1, 3			! if (section >= 3)
	bge		second_loop_end	! break
	nop						! Delay slot for branch instruction
	mov 	%i3, %o0		! Pass borderChar as 1st argument
	call 	printSegment	! Make function call
	mov 	%l2, %o1		! borderWidth as 2nd
	call	printChar		! Make function call
	mov 	%i2, %o0		! Pass parameter to printChar
	mov 	%i1, %o0		! Pass parameter
	call 	printSegment	! Make function call
	sub 	%i0, 2, %o1		! Pass parameter subtracting 2 from it
	call 	printChar		! Make function call
	mov 	%i2, %o0		! Pass parameter
	mov 	%i3, %o0		! Pass parameter
	call 	printSegment	! Make function call
	mov 	%l2, %o1		! Pass parameter
	call 	printChar		! Make function call
	mov 	'\n', %o0		! Pass parameter (newline)
	
 /* Do not continue if drawing bottom line */
	cmp		%l1, 2			! if (section == 2)
	be		second_loop_end ! break
	nop						! Delay slot for branch instruction
	
 /* Fill between horizontal lines of S */
	clr 	%l0				! line = 0
 second_loop_inner:
	sub 	%i0, 2, %l3		! tmp = sWidth - 2
	cmp 	%l0, %l3		! if (line >= tmp) {
	bge		second_loop_inner_end ! break } else {
	nop						! Delay slot for branch instruction
	mov 	%i3, %o0		! Pass argument
	call	printSegment	! Make function call
	mov 	%l2, %o1		! Pass argument
	cmp 	%l1, 0			! if (section == 0)
	be,a 	second_loop_inner_select_char
	mov		%i1, %o0		! Set parameter to sChar
	ba		second_loop_inner_select_char
	mov 	%i2, %o0		! else Set parameter fillerChar
 second_loop_inner_select_char:
	call	printChar		! Make function call
	nop						! Delay slot for call instruction

  /* Fill in */
	mov 	%i2, %o0		! 1st parameter is sChar
	call 	printSegment	! Make function call
	sub		%i0, 2, %o1		! 2st parameter is sWidth - 2
 
 /* Check for top or bottom section and place appropriate char */
	cmp 	%l1, 0			! if (section == 0)
	be,a 	second_loop_inner_select_char_second
	mov		%i2, %o0		! Set parameter to fillerChar
	ba		second_loop_inner_select_char_second
	mov 	%i1, %o0		! else Set parameter sChar
 second_loop_inner_select_char_second:
	call 	printChar		! Make function call
	nop						! Delay slot for call instruction
	
	mov		%i3, %o0		! Parameter
	call 	printSegment	! Make function call
	mov 	%l2, %o1		! Parameter
	call 	printChar		! Make function call
	mov 	'\n', %o0		! Parameter
	
	inc 	%l0				! Increment counter
	ba 		second_loop_inner	! Do a loop
	nop						! Delay slot for branch instruction
 second_loop_inner_end:		! }
	
	inc 	%l1				! Increment counter
	ba		second_loop		! Do a loop
	nop						! Delay slot for branch instruction
 second_loop_end:
	
 /* Bottom border */
	clr 	%l0				! Clear line local variable
 third_loop:
	cmp		%l0, %l2		! if (line >= borderWidth)
	bge		third_loop_end	! break
	nop						! Delay slot for branch instruction
	mov 	%l2, %o0		! 1st parameter
	call	.mul			! Make function call
	mov 	2, %o1			! Fill delay slot passing 2nd parameter
	add		%o0, %i0, %o1	! Add borderWidth*2 and sWidth and pass to the function
	call 	printSegment	! Make function call
	mov		%i3, %o0		! Pass parameter to the function
	call	printChar		! Make function call
	mov 	'\n', %o0		! Pass parameter to the function
	inc 	%l0				! Increase a counter
	ba		third_loop		! Make function call
	nop						! Delay slot for call instruction
 third_loop_end:

	ret						! Return from subroutine
	restore					! Restore caller's window
