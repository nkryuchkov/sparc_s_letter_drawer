 	.global printSegment	! Declare the symbol to be globally visible
							! so we can call this function from other 
							! module

	.section ".text"		! The test segment begins here

/* 
 * Function Name: printSegment()
 * Function Prototype: void printSegment ( long character, long amount );
 * Description: print character to stdout amount number of times
 * Parameters: long character, long amount
 * Side Effect: prints out the character amount number of times
 * Error: none
 * Return Value: none
 */

 printSegment:
 	save	%sp, -96, %sp 	! Save caller's window if different than -96
 printSegmentLoop:
	mov		%i0, %o0		! copy of formal parameter to print
	call	printChar		! Make function call
	nop						! Delay slot for call instruction
	subcc	%i1, 1, %i1		! Decrement amount by one and set flags
	bne,a	printSegmentLoop! If amount isn't equal to zero do a loop
	nop						! Delay slot for branch instruction
	ret						! Return from subroutine
	restore					! Restore caller's window
