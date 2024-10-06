/*--------------------------------------------------------------------*/
/* replace.c                                                          */
/* Author: Anish Kataria                                               */
/*--------------------------------------------------------------------*/

#include "str.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

/*--------------------------------------------------------------------*/

/* If pcFrom is the empty string, then write string pcLine to stdout
   and return 0.  Otherwise write string pcLine to stdout with each
   distinct occurrence of string pcFrom replaced with string pcTo,
   and return a count of how many replacements were made.  Make no
   assumptions about the maximum number of replacements or the
   maximum number of characters in strings pcLine, pcFrom, or pcTo. */
static size_t replaceAndWrite(const char *pcLine,
                              const char *pcFrom, const char *pcTo)
{
    /* Ensure that the input pointers are valid */
    assert(pcLine != NULL);
    assert(pcFrom != NULL);
    assert(pcTo != NULL);

    size_t replacementCounter = 0;
    const char *currentPosition = pcLine;
    const char *foundPosition;

    /* Check if the 'from' string is empty */
    if (Str_getLength(pcFrom) == 0) {
        printf("%s", pcLine);
        return 0;
    }

    /* Iterate through the line to find and replace occurrences */
    while ((foundPosition = Str_search(currentPosition, pcFrom)) != NULL) {
        /* Calculate the length of the segment before the match */
        size_t segmentLength = (size_t)(foundPosition - currentPosition);

        /* Print the segment before the matched 'from' string */
        printf("%.*s", (int)segmentLength, currentPosition);

        /* Print the 'to' string as a replacement */
        printf("%s", pcTo);

        /* Move the current position past the matched 'from' string */
        currentPosition = foundPosition + Str_getLength(pcFrom);

        /* Increment the replacement counter */
        replacementCounter++;
    }

    /* Print any remaining part of the line after the last match */
    printf("%s", currentPosition);

    return replacementCounter;
}

/*--------------------------------------------------------------------*/

/* If argc is unequal to 3, then write an error message to stderr and
   return EXIT_FAILURE.  Otherwise...
   If argv[1] is the empty string, then write each line of stdin to
   stdout, write a message to stderr indicating that 0 replacements
   were made, and return 0.  Otherwise...
   Write each line of stdin to stdout with each distinct occurrence of
   argv[1] replaced with argv[2], write a message to stderr indicating
   how many replacements were made, and return 0.
   Assume that no line of stdin consists of more than MAX_LINE_SIZE-1
   characters. */
   
int main(int argc, char *argv[])
{
    enum { MAX_LINE_SIZE = 4096 };
    enum { REQUIRED_ARG_COUNT = 3 };

    char inputLine[MAX_LINE_SIZE];
    char *searchString;
    char *replaceString;
    size_t totalReplacements = 0;

    /* Validate the number of command-line arguments */
    if (argc != REQUIRED_ARG_COUNT) {
        fprintf(stderr, "Usage: %s <from_string> <to_string>\n", argv[0]);
        return EXIT_FAILURE;
    }

    /* Assign the 'from' and 'to' strings from command-line arguments */
    searchString = argv[1];
    replaceString = argv[2];

    /* Process each line from standard input */
    while (fgets(inputLine, MAX_LINE_SIZE, stdin) != NULL) {
        /* Perform replacement and accumulate the count */
        totalReplacements += replaceAndWrite(inputLine, searchString, replaceString);
    }

    /* Output the total number of replacements to stderr */
    fprintf(stderr, "%lu replacements\n", (unsigned long)totalReplacements);

    return 0;
}