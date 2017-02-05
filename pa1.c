#include <stdio.h>
#include <stdlib.h>

#include "pa1.h"
#include "pa1Strings.h"

/*
 * void perror(char *error);
 * Sends error message to the stderr.
 */
void perror(char *error)
{
  fprintf(stderr, error);
}

int main(int argc, char* argv[]) 
{
  /*
   * Testing the number of arguments. If it does not match EXPECTED_ARGS,
   * returns EXIT_FAILURE.
   */
  if (argc == EXPECTED_ARGS)
  {
    char error[MAX_ERR_BUFFER];
    int cx = _snprintf_s(error, MAX_ERR_BUFFER, MAX_ERR_BUFFER, STR_USAGE,
		                argv[0], S_WIDTH_MIN, S_WIDTH_MAX, ASCII_MIN, 
						ASCII_MAX, ASCII_MIN, ASCII_MAX, ASCII_MIN, ASCII_MAX
						);
	if (cx >= 0 && cx < MAX_ERR_BUFFER)
    {
      perror(error);
    }
    return EXIT_FAILURE;
  }

  
  /*
   * Parsing the sWidth argument
   */
  char* endptr;
  errno = 0;
  int errorOccured1 = 0;  //flag for errors occured during parsing
  char* testSWidth = argv[1];
  long sWidth = strtol(testSWidth, &endptr, BASE);

  /*
   * Handling converting error
   */
  if (errno != 0) 
  {
    char error[MAX_ERR_BUFFER];
    int cx = _snprintf_s(error, MAX_ERR_BUFFER, MAX_ERR_BUFFER, 
		                STR_CONVERTING, testSWidth, sWidth
						);
    if (cx >= 0 && cx < MAX_ERR_BUFFER)
    {
      perror(error);
    }
    errorOccured1 = 1;
  }

  /*
   * Handling error when the sWidth argument is not int
   */
  if (!errorOccured1 && !strcmp(endptr, ""))
  {
    char error[MAX_ERR_BUFFER];
    int cx = _snprintf_s(error, MAX_ERR_BUFFER, MAX_ERR_BUFFER, 
		                STR_NOTINT, testSWidth
						);
    if (cx >= 0 && cx < MAX_ERR_BUFFER)
    {
      perror(error);
    }
    errorOccured1 = 1;
  }

  /*
   * Handling error when the sWidth argument is not in the required range
   */
  if (!errorOccured1 && isInRange(S_WIDTH_MIN, S_WIDTH_MAX, sWidth, 0) != 1)
  {
    char error[MAX_ERR_BUFFER];
    int cx = _snprintf_s(error, MAX_ERR_BUFFER, MAX_ERR_BUFFER,
		                STR_ERR_S_WIDTH_RANGE,
		                sWidth, S_WIDTH_MIN, S_WIDTH_MAX
						);
	if (cx >= 0 && cx < MAX_ERR_BUFFER)
    {
      perror(error);
    }
    errorOccured1 = 1;
  }

  /*
   * Handling error when the sWidth argument is not even
   */
  if (!errorOccured1 && isEven(sWidth) != 1)
  {
    char error[MAX_ERR_BUFFER];
    int cx = _snprintf_s(error, MAX_ERR_BUFFER, MAX_ERR_BUFFER,
		                STR_ERR_S_WIDTH_EVEN, sWidth
						);
    if (cx >= 0 && cx < MAX_ERR_BUFFER)
    {
      perror(error);
    }
    errorOccured1 = 1;
  }

  
  /*
   * Parsing the sChar argument
   */
  int errorOccured2 = 0;  //flag for errors occured during parsing
  errno = 0;
  char* testSChar = argv[2];
  long sChar = strtol(testSChar, &endptr, BASE);

  /*
   * Handling converting error
   */
  if (errno != 0) 
  {
    char error[MAX_ERR_BUFFER];
    int cx = _snprintf_s(error, MAX_ERR_BUFFER, MAX_ERR_BUFFER,
		                STR_CONVERTING, testSChar, sChar
						);
    if (cx >= 0 && cx < MAX_ERR_BUFFER)
    {
      perror(error);
    }
    errorOccured2 = 1;
  }
  
  /*
   * Handling error when the sChar argument is not int
   */
  if (!errorOccured2 && !strcmp(endptr, ""))
  {
    char error[MAX_ERR_BUFFER];
    int cx = _snprintf_s(error, MAX_ERR_BUFFER, MAX_ERR_BUFFER,
		                STR_NOTINT, testSChar
						);
    if (cx >= 0 && cx < MAX_ERR_BUFFER)
    {
      perror(error);
    }
    errorOccured2 = 1;
  }

  /*
   * Handling error when the sChar argument is not in the required range
   */
  if (!errorOccured2 && isInRange(ASCII_MIN, ASCII_MAX, sChar, 0) != 1)
  {
    char error[MAX_ERR_BUFFER];
    int cx = _snprintf_s(error, MAX_ERR_BUFFER, MAX_ERR_BUFFER, 
		                STR_ERR_S_CHAR_RANGE, sChar, ASCII_MIN, ASCII_MAX
						);
	if (cx >= 0 && cx < MAX_ERR_BUFFER)
    {
      perror(error);
    }
    errorOccured2 = 1;
  }

  
  /*
   * Parsing the fillerChar argument
   */
  int errorOccured3 = 0;  //flag for errors occured during parsing
  errno = 0;
  char* testFillerChar = argv[3];
  long fillerChar = strtol(testFillerChar, &endptr, BASE);
  
  /*
   * Handling converting error
   */
  if (errno != 0) 
  {
    char error[MAX_ERR_BUFFER];
    int cx = _snprintf_s(error, MAX_ERR_BUFFER, MAX_ERR_BUFFER, 
		                STR_CONVERTING, testFillerChar, fillerChar
						);
	if (cx >= 0 && cx < MAX_ERR_BUFFER)
    {
      perror(error);
    }
    errorOccured3 = 1;
  }
	
  /*
   * Handling error when the fillerChar argument is not int
   */
  if (!errorOccured3 && !strcmp(endptr, ""))
  {
    char error[MAX_ERR_BUFFER];
    int cx = _snprintf_s(error, MAX_ERR_BUFFER, MAX_ERR_BUFFER, STR_NOTINT, 
		                testFillerChar
						);
    if (cx >= 0 && cx < MAX_ERR_BUFFER)
    {
      perror(error);
    }
    errorOccured3 = 1;
  }

  /*
   * Handling error when the fillerChar argument is not in the required range
   */
  if (!errorOccured3 && isInRange(ASCII_MIN, ASCII_MAX, fillerChar, 0) != 1)
  {
    char error[MAX_ERR_BUFFER];
    int cx = _snprintf_s(error, MAX_ERR_BUFFER, MAX_ERR_BUFFER, 
		                STR_ERR_FILLERCHAR_RANGE, fillerChar, 
						ASCII_MIN, ASCII_MAX
						);
	if (cx >= 0 && cx < MAX_ERR_BUFFER)
    {
      perror(error);
    }
    errorOccured3 = 1;
  }
  
  /*
   * Handling error when the sChar argument is the same as the
   * fillerChar argument
   */
  if (!errorOccured3 && fillerChar == sChar)
  {
    char error[MAX_ERR_BUFFER];
    int cx = _snprintf_s(error, MAX_ERR_BUFFER, MAX_ERR_BUFFER,
		                STR_ERR_S_CHAR_FILLERCHAR_DIFF, 
                        sChar, fillerChar
						);
	if (cx >= 0 && cx < MAX_ERR_BUFFER)
    {
      perror(error);
    }
    errorOccured3 = 1;
  }


  /*
   * Parsing the borderChar argument
   */
  int errorOccured4 = 0;  //flag for errors occured during parsing
  errno = 0;
  char* testBorderChar = argv[4];
  long borderChar = strtol(testBorderChar, &endptr, BASE);
  
  /*
   * Handling converting error
   */
  if (errno != 0) 
  {
    char error[MAX_ERR_BUFFER];
    int cx = _snprintf_s(error, MAX_ERR_BUFFER, MAX_ERR_BUFFER,
		                STR_CONVERTING, testBorderChar, borderChar
						);
	if (cx >= 0 && cx < MAX_ERR_BUFFER)
    {
      perror(error);
    }
    errorOccured4 = 1;
  }
	
  /*
   * Handling error when the borderChar argument is not int
   */
  if (!errorOccured4 && !strcmp(endptr, ""))
  {
    char error[MAX_ERR_BUFFER];
    int cx = _snprintf_s(error, MAX_ERR_BUFFER, MAX_ERR_BUFFER, STR_NOTINT,
		                testBorderChar
						);
    if (cx >= 0 && cx < MAX_ERR_BUFFER)
    {
      perror(error);
    }
    errorOccured4 = 1;
  }

  /*
   * Handling error when the borderChar argument is not in the required range
   */
  if (!errorOccured4 && isInRange(ASCII_MIN, ASCII_MAX, borderChar, 0) != 1)
  {
    char error[MAX_ERR_BUFFER];
    int cx = _snprintf_s(error, MAX_ERR_BUFFER, MAX_ERR_BUFFER, 
		                STR_ERR_BORDERCHAR_RANGE, borderChar, ASCII_MIN,
						ASCII_MAX
						);
	if (cx >= 0 && cx < MAX_ERR_BUFFER)
    {
      perror(error);
    }
    errorOccured4 = 1;
  }
	
  /*
   * Handling error when the sChar argument is the same as the
   * borderChar argument
   */
  if (!errorOccured4 && borderChar == sChar)
  {
    char error[MAX_ERR_BUFFER];
    int cx = _snprintf_s(error, MAX_ERR_BUFFER, MAX_ERR_BUFFER, 
		                STR_ERR_S_CHAR_BORDERCHAR_DIFF, 
                        sChar, borderChar
						);
	if (cx >= 0 && cx < MAX_ERR_BUFFER)
    {
      perror(error);
    }
    errorOccured4 = 1;
  }


  /*
   * If an error occured while parsing any of the arguments, return
   * EXIT_FAILURE
   */
  if (errorOccured1 || errorOccured2 || errorOccured3 || errorOccured4)
    return EXIT_FAILURE;

  /*
   * Cal drawS and then return EXIT_SUCCESS
   */
  drawS(sWidth, sChar, fillerChar, borderChar);
  return EXIT_SUCCESS;
}
