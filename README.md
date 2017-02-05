# SPARC ASM s-letter drawer
This draws the letter 'S' using different chars for the letter itself, for filling and for the border. This uses SPARC assembly functions called from the C code.

Explanation of command line arguments:  
● sWidth -- Width of the ‘S’ (not including the borders)  
● sChar -- ASCII value of the character making up the ‘S’  
● fillerChar -- ASCII value of the character filling the space between the ‘S’ and the border  
● borderChar -- ASCII value of the character making up the rectangular border around the ‘S’

**Example**  
Parameters: sWidth = 8, sChar = '-', fillerChar = '?', borderChar = '#'  
Command line arguments: 8 45 63 35  
Output:  
 ##########  
 #?------?#  
 #-???????#  
 #-???????#  
 #-???????#  
 #-???????#  
 #-???????#  
 #-???????#  
 #?------?#  
 #???????-#  
 #???????-#  
 #???????-#  
 #???????-#  
 #???????-#  
 #???????-#  
 #?------?#  
 ##########


