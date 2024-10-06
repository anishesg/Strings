/*--------------------------------------------------------------------*/
/* replace.c                                                          */
/* Author: Anish Kataria                                               */
/*--------------------------------------------------------------------*/

#include "str.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

/*--------------------------------------------------------------------*/

/* 
 * If pcFrom is the empty string, then write string pcLine to stdout
 * and return 0. Otherwise write string pcLine to stdout with each
 * distinct occurrence of string pcFrom replaced with string pcTo,
 * and return a count of how many replacements were made.
 */
static size_t replaceAndWrite(const char *pcLine,
                              const char *pcFrom, const char *pcTo)
{
    /* Validate that the input pointers are not NULL */
    assert(pcLine != NULL);
    assert(pcFrom != NULL);
    assert(pcTo != NULL);
    
    /* Declare all variables at the beginning */
    const char *currentPtr = pcLine;
    size_t replacementCount = 0;
    size_t fromLength = Str_getLength(pcFrom);
    char *found;
    size_t prefixLength;
    
    /* Handle empty pcFrom string */
    if (fromLength == 0) {
        printf("%s", pcLine);
        return 0;
    }
    
    while (*currentPtr != '\0') {
        /* Search for the next occurrence of pcFrom in pcLine */
        found = Str_search(currentPtr, pcFrom);
        
        if (found != NULL) {
            /* Calculate the number of characters before the found substring */
            prefixLength = (size_t)(found - currentPtr);
            
            /* Print the prefix part that does not include pcFrom */
            if (prefixLength > 0) {
                printf("%.*s", (int)prefixLength, currentPtr);
            }
            
            /* Print the replacement string pcTo */
            printf("%s", pcTo);
            
            /* Move the currentPtr pointer past the found pcFrom substring */
            currentPtr += prefixLength + fromLength;
            
            /* Increment the replacement count */
            replacementCount++;
        } else {
            /* No more occurrences found; print the remaining part of pcLine */
            printf("%s", currentPtr);
            break;
        }
    }
    
    return replacementCount;
}

/*--------------------------------------------------------------------*/

/* 
 * If argc is unequal to 3, then write an error message to stderr and
 * return EXIT_FAILURE. Otherwise...
 * If argv[1] is the empty string, then write each line of stdin to
 * stdout, write a message to stderr indicating that 0 replacements
 * were made, and return 0. Otherwise...
 * Write each line of stdin to stdout with each distinct occurrence of
 * argv[1] replaced with argv[2], write a message to stderr indicating
 * how many replacements were made, and return 0.
 * Assume that no line of stdin consists of more than MAX_LINE_SIZE-1
 * characters.
 */
int main(int argc, char *argv[])
{
   enum {MAX_LINE_SIZE = 4096};
   enum {PROPER_ARG_COUNT = 3};

   char acLine[MAX_LINE_SIZE];
   char *pcFrom;
   char *pcTo;
   size_t uReplaceCount = 0;

   if (argc != PROPER_ARG_COUNT)
   {
      fprintf(stderr, "usage: %s fromstring tostring\n", argv[0]);
      return EXIT_FAILURE;
   }

   pcFrom = argv[1];
   pcTo = argv[2];

    while (fgets(acLine, MAX_LINE_SIZE, stdin) != NULL) {
        uReplaceCount += replaceAndWrite(acLine, pcFrom, pcTo);
    }

   fprintf(stderr, "%lu replacements\n", (unsigned long)uReplaceCount);
   return 0;
}
/*--------------------------------------------------------------------*/