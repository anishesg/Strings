/* strp.c
 * Pointer-based implementation of the Str module.
 * Author: anish kataria
 */

#include <stddef.h>
#include <assert.h>
#include "str.h"

/* 
 * function: Str_getLength
 * -----------------------
 * calculates the number of characters in the given string
 *
 * pcSrc: the string whose length is to be determined
 *
 * returns: the length of the string as a size_t value
 */
size_t Str_getLength(const char pcSrc[]) {
    const char *pcIter;
    assert(pcSrc != NULL);

    /* Initialize after declarations */
    pcIter = pcSrc;
    while (*pcIter) {
        pcIter++;
    }
    return (size_t)(pcIter - pcSrc);
}

/* 
 * function: Str_copy
 * -------------------
 * copies the source string into the destination array
 *
 * pcDest: the array where the string will be copied
 * pcSrc:  the string to be copied
 *
 * returns: a pointer to the destination string pcDest
 */
char *Str_copy(char pcDest[], const char pcSrc[]) {
    char *pcDestIter;
    assert((pcDest != NULL) && (pcSrc != NULL));

    /* Initialize after declarations */
    pcDestIter = pcDest;
    for (; (*pcDestIter = *pcSrc) != '\0'; pcDestIter++, pcSrc++) {
        /* Copying characters from pcSrc to pcDest */
    }
    return pcDest;
}

/* 
 * function: Str_concat
 * ---------------------
 * appends the source string to the end of the destination string
 *
 * pcDest: the array where the source string will be concatenated
 * pcSrc:  the string to append to the destination
 *
 * returns: a pointer to the concatenated destination string pcDest
 */
char *Str_concat(char pcDest[], const char pcSrc[]) {
    char *pcDestEnd;
    size_t destLength;
    assert((pcDest != NULL) && (pcSrc != NULL));

    /* get length */
    destLength = Str_getLength(pcDest);
    pcDestEnd = pcDest + destLength;

    /* Append pcSrc to pcDest */
    while ((*pcDestEnd++ = *pcSrc++)) {
        /* Copy each character from pcSrc to the end of pcDest */
    }
    return pcDest;
}

/* 
 * function: Str_compare
 * ----------------------
 * compares two strings to determine their lexicographical order
 *
 * pcStr1: the first string to compare
 * pcStr2: the second string to compare
 *
 * returns: 
 *   -1 if pcStr1 is less than pcStr2,
 *    0 if pcStr1 is equal to pcStr2,
 *    1 if pcStr1 is greater than pcStr2
 */
int Str_compare(const char pcStr1[], const char pcStr2[]) {
    assert((pcStr1 != NULL) && (pcStr2 != NULL));

    while (*pcStr1 && (*pcStr1 == *pcStr2)) {
        pcStr1++;
        pcStr2++;
    }
    if (*pcStr1 == *pcStr2) {
        return 0;
    } else if ((unsigned char)*pcStr1 < (unsigned char)*pcStr2) {
        return -1;
    } else {
        return 1;
    }
}

/* 
 * function: Str_search
 * ---------------------
 * searches for the first occurrence of the needle string within the haystack string
 *
 * pcHaystack: the string to be searched within
 * pcNeedle:   the string to search for
 *
 * returns:
 *   a pointer to the first occurrence of pcNeedle in pcHaystack,
 *   or NULL if the needle is not found
 */
char *Str_search(const char pcHaystack[], const char pcNeedle[]) {
    const char *hayIter;
    assert((pcHaystack != NULL) && (pcNeedle != NULL));

    /* Handle edge case: empty needle */
    if (*pcNeedle == '\0') {
        return (char *)pcHaystack;
    }

    /* Initialize after declarations */
    for (hayIter = pcHaystack; *hayIter != '\0'; hayIter++) {
        /* Check if the first character matches */
        if (*hayIter == *pcNeedle) {
            const char *currentHaystackPointer = hayIter;
            const char *currentNeedlePointer = pcNeedle;

            /* Start comparing from current position */
            for (; *currentNeedlePointer != '\0' && *currentHaystackPointer != '\0' && *currentHaystackPointer == *currentNeedlePointer; currentHaystackPointer++, currentNeedlePointer++) {
                /* No operation inside the loop */
            }

            /* If we reached the end of needle, match is found */
            if (*currentNeedlePointer == '\0') {
                return (char *)hayIter;
            }
        }
    }

    /* Needle not found */
    return NULL;
}