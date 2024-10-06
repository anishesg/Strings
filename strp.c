/* strp.c
 * pointer-based implementation of the str module.
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
    const char *currentChar;
    size_t length = 0;

    assert(pcSrc != NULL);

    /* initialize pointer to the start of the string */
    currentChar = pcSrc;

    /* iterate through the string until the null terminator is reached */
    while (*currentChar) {
        length++;
        currentChar++;
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
 * returns: a pointer to the destination string pcdest
 */
char *Str_copy(char pcDest[], const char pcSrc[]) {
    char *destPointer;
    size_t index = 0;

    assert(pcDest != NULL && pcSrc != NULL);

    /* initialize pointer to the start of the destination array */
    destPointer = pcDest;

    /* copy characters from pcSrc to pcDest until the null terminator is encountered */
    while ((*(destPointer + index) = *(pcSrc + index)) != '\0') {
        index++;
    }

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
 * returns: a pointer to the concatenated destination string pcdest
 */
char *Str_concat(char pcDest[], const char pcSrc[]) {
    char *destinationEnd;
    size_t destinationLength;

    assert(pcDest != NULL && pcSrc != NULL);

    /* get the length of the destination string */
    destinationLength = Str_getLength(pcDest);

    /* set the pointer to the end of the destination string */
    destinationEnd = pcDest + destinationLength;

    /* append characters from pcSrc to pcDest */
    while ((*destinationEnd++ = *pcSrc++)) {
        /* copying characters */
    }

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
    assert(pcStr1 != NULL && pcStr2 != NULL);

    /* iterate through both strings character by character */
    while (*pcStr1 && (*pcStr1 == *pcStr2)) {
        pcStr1++;
        pcStr2++;
    }

    /* determine the result based on the comparison */
    if (*pcStr1 == *pcStr2) {
        return 0;
    } else if ((unsigned char)*pcStr1 < (unsigned char)*pcStr2) {
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
    const char *haystackPointer;
    const char *needlePointer;

    assert(pcHaystack != NULL && pcNeedle != NULL);

    /* handle edge case where the needle is an empty string */
    if (*pcNeedle == '\0') {
        return (char *)pcHaystack;
    }

    /* iterate through each character in the haystack */
    for (haystackPointer = pcHaystack; *haystackPointer != '\0'; haystackPointer++) {
        /* check if the current character matches the first character of the needle */
        if (*haystackPointer == *pcNeedle) {
            needlePointer = pcNeedle;

            /* start comparing subsequent characters */
            while (*needlePointer != '\0' && *haystackPointer == *needlePointer) {
                haystackPointer++;
                needlePointer++;
            }

            /* if the end of the needle is reached, a match is found */
            if (*needlePointer == '\0') {
                return (char *)(haystackPointer - (needlePointer - pcNeedle));
            }

            /* reset haystackPointer to the position after the initial match */
            haystackPointer -= (needlePointer - pcNeedle) - 1;
        }
    }

    /* if no match is found, return NULL */
    return NULL;
}