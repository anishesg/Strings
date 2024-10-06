/* stra.c
 * array-based implementation of the str module.
 * author: anish kataria
 */

#include <stddef.h>
#include <assert.h>
#include "str.h"

/* 
 * function: str_getlength
 * -----------------------
 * calculates the number of characters in the given string
 *
 * pcsrc: the string whose length is to be determined
 *
 * returns: the length of the string as a size_t value
 */
size_t Str_getLength(const char pcSrc[]) {
    size_t length = 0;
    assert(pcSrc != NULL);
    /* count the number of characters until null terminator */
    for (length = 0; pcSrc[length] != '\0'; length++) {
        /* no operation inside the loop */
    }
    return length;
}

/* 
 * function: str_copy
 * -------------------
 * copies the source string into the destination array
 *
 * pcdest: the array where the string will be copied
 * pcsrc:  the string to be copied
 *
 * returns: a pointer to the destination string pcDest
 */
char *Str_copy(char pcDest[], const char pcSrc[]) {
    size_t index = 0;
    assert(pcDest != NULL && pcSrc != NULL);
    /* handle empty source string explicitly */
    if (pcSrc[0] == '\0') {
        pcDest[0] = '\0';
        return pcDest;
    }
    /* copy characters from pcSrc to pcDest */
    while (pcSrc[index] != '\0') {
        pcDest[index] = pcSrc[index];
        index++;
    }
    /* add null terminator to the end of pcDest */
    pcDest[index] = '\0';
    return pcDest;
}

/* 
 * function: str_concat
 * ---------------------
 * appends the source string to the end of the destination string
 *
 * pcdest: the array where the source string will be concatenated
 * pcsrc:  the string to append to the destination
 *
 * returns: a pointer to the concatenated destination string pcDest
 */
char *Str_concat(char pcDest[], const char pcSrc[]) {
    size_t destLen;
    size_t i;
    assert(pcDest != NULL && pcSrc != NULL);
    /* find the length of pcDest */
    destLen = Str_getLength(pcDest);
    /* append pcSrc to pcDest */
    for (i = 0; pcSrc[i] != '\0'; i++) {
        pcDest[destLen + i] = pcSrc[i];
    }
    /* add null terminator at the end */
    pcDest[destLen + i] = '\0';
    return pcDest;
}

/* 
 * function: str_compare
 * ----------------------
 * compares two strings to determine their lexicographical order
 *
 * pcstr1: the first string to compare
 * pcstr2: the second string to compare
 *
 * returns: 
 *   -1 if pcStr1 is less than pcStr2,
 *    0 if pcStr1 is equal to pcStr2,
 *    1 if pcStr1 is greater than pcStr2
 */
int Str_compare(const char pcStr1[], const char pcStr2[]) {
    size_t i;
    assert(pcStr1 != NULL && pcStr2 != NULL);
    /* compare characters one by one */
    for (i = 0; pcStr1[i] != '\0' && pcStr2[i] != '\0'; i++) {
        if (pcStr1[i] != pcStr2[i]) {
            /* return -1 if pcStr1 < pcStr2, 1 if pcStr1 > pcStr2 */
            if ((unsigned char)pcStr1[i] < (unsigned char)pcStr2[i]) {
                return -1;
            } else {
                return 1;
            }
        }
    }
    /* strings are equal up to the length of the shorter one */
    if (pcStr1[i] == pcStr2[i]) {
        return 0;
    } else if ((unsigned char)pcStr1[i] < (unsigned char)pcStr2[i]) {
        return -1;
    } else {
        return 1;
    }
}

/* 
 * function: str_search
 * ---------------------
 * searches for the first occurrence of the needle string within the haystack string
 *
 * pchydstack: the string to be searched within
 * pcneedle:   the string to search for
 *
 * returns:
 *   a pointer to the first occurrence of pcNeedle in pcHaystack,
 *   or NULL if the needle is not found
 */
char *Str_search(const char pcHaystack[], const char pcNeedle[]) {
    size_t hayIndex = 0;
    size_t needleIndex;
    assert(pcHaystack != NULL && pcNeedle != NULL);
    
    /* if needle is empty, return haystack */
    if (pcNeedle[0] == '\0') {
        return (char *)pcHaystack;
    }

    /* iterate through haystack */
    while (pcHaystack[hayIndex] != '\0') {
        /* if first character matches, proceed to check the rest of the needle */
        if (pcHaystack[hayIndex] == pcNeedle[0]) {
            needleIndex = 0;
            /* check each subsequent character */
            while (pcNeedle[needleIndex] != '\0' &&
                   pcHaystack[hayIndex + needleIndex] == pcNeedle[needleIndex]) {
                needleIndex++;
            }
            /* if the entire needle was found, return the pointer to the start of the match */
            if (pcNeedle[needleIndex] == '\0') {
                return (char *)(pcHaystack + hayIndex);
            }
        }
        hayIndex++;
    }

    /* needle not found in haystack */
    return NULL;
}