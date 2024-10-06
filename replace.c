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
    /* validate that the input pointers are not NULL */
    assert(pcLine != NULL);
    assert(pcFrom != NULL);
    assert(pcTo != NULL);
    
    const char *currentPtr = pcLine;
    size_t replacementCount = 0;
    
    size_t fromLength = Str_getLength(pcFrom);
    size_t toLength = Str_getLength(pcTo);
    
    /* handle empty pcFrom string */
    if (fromLength == 0) {
        printf("%s", pcLine);
        return 0;
    }
    
    while (*currentPtr != '\0') {
        /* search for the next occurrence of pcFrom in pcLine */
        char *found = Str_search(currentPtr, pcFrom);
        
        if (found != NULL) {
            /* calculate the number of characters before the found substring */
            size_t prefixLength = (size_t)(found - currentPtr);
            
            /* print the prefix part that does not include pcFrom */
            if (prefixLength > 0) {
                printf("%.*s", (int)prefixLength, currentPtr);
            }
            
            /* print the replacement string pcTo */
            printf("%s", pcTo);
            
            /* move the currentPtr pointer past the found pcFrom substring */
            currentPtr += prefixLength + fromLength;
            
            /* increment the replacement count */
            replacementCount++;
        } else {
            /* no more occurrences found; print the remaining part of pcLine */
            printf("%s", currentPtr);
            break;
        }
    }
    
    return replacementCount;
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

    fprintf(stderr, "%zu replacements\n", uReplaceCount);
    return 0;
}

/*--------------------------------------------------------------------*/