#ifndef PA1_H
#define PA1_H

/* Local function prototypes for PA1 (written in Assembly or C) */

int isInRange( long minRange, long maxRange, long value, long exclusive );
void drawS( long sWidth, long sChar, long fillerChar, long borderChar );
int isEven( long value );
int numOfDigits( long num, int base );


#define EXPECTED_ARGS 5

#define BASE 10
#define S_WIDTH_MIN 4
#define S_WIDTH_MAX 1000

/* Pass to isInRange to check inclusive ranges */
#define INCLUSIVE 0
#define EXCLUSIVE 1

/*
 * See "man ascii" for ASCII char values
 */
#define ASCII_MIN 32     /* ' ' */
#define ASCII_MAX 126    /* '~' */

/* Maximal size of the error buffer */
#define MAX_ERR_BUFFER 800

/*
 * void printChar( char ch );
 * int numOfDigits( long num, int base );
 * void printSegment( char character, long amount);
 *
 * Only called from an Assembly routine. Not needed in any C routine.
 * Would get a lint message about function declared but not used.
 */

#endif /* PA1_H */
