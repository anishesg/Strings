/* stra.c
 * array-based implementation of the str module.
 * author: anish kataria
 */

#include <stddef.h>
#include <assert.h>
#include "str.h"

size_t Str_getLength(const char pcSrc[]) {
    size_t length = 0;
    assert((pcSrc) != NULL);
    /* count the number of characters until null terminator */
    for (length = 0; pcSrc[length] != '\0'; length++) {
        /* No operation inside the loop */
    }
    return length;
}

char *Str_copy(char pcDest[], const char pcSrc[]) {
    size_t index = 0;
    assert((pcDest != NULL) && (pcSrc != NULL));
    /* Handle empty source string explicitly */
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

char *Str_concat(char pcDest[], const char pcSrc[]) {
    size_t destLen = 0;
    size_t srcIndex = 0;
    assert((pcDest != NULL) && (pcSrc != NULL));
    /* Handle empty source string explicitly */
    if (pcSrc[0] == '\0') {
        return pcDest;
    }
    /* find the length of pcDest to know where to start concatenation */
    for (destLen = 0; pcDest[destLen] != '\0'; destLen++) {
        /* No operation inside the loop */
    }
    /* append pcSrc to pcDest */
    while (pcSrc[srcIndex] != '\0') {
        pcDest[destLen + srcIndex] = pcSrc[srcIndex];
        srcIndex++;
    }
    /* add null terminator at the end */
    pcDest[destLen + srcIndex] = '\0';
    return pcDest;
}

int Str_compare(const char pcStr1[], const char pcStr2[]) {
    size_t index = 0;
    int diff;
    assert((pcStr1 != NULL) && (pcStr2 != NULL));
    /* compare characters one by one */
    while (pcStr1[index] != '\0' && pcStr2[index] != '\0') {
        if (pcStr1[index] != pcStr2[index]) {
            /* return difference of first unmatched characters */
            diff = (unsigned char)pcStr1[index] - (unsigned char)pcStr2[index];
            return diff;
        }
        index++;
    }
    /* strings are equal up to the length of the shorter one */
    diff = (unsigned char)pcStr1[index] - (unsigned char)pcStr2[index];
    return diff;
}

char *Str_search(const char pcHaystack[], const char pcNeedle[]) {
    size_t hayIndex;
    size_t needleIndex;
    assert((pcHaystack != NULL) && (pcNeedle != NULL));
    /* if needle is empty, return haystack */
    if (pcNeedle[0] == '\0') {
        return (char *)pcHaystack;
    }
    /* iterate through haystack */
    for (hayIndex = 0; pcHaystack[hayIndex] != '\0'; hayIndex++) {
        /* if first character matches, check for full needle */
        if (pcHaystack[hayIndex] == pcNeedle[0]) {
            /* check for full needle */
            for (needleIndex = 0;
                 pcNeedle[needleIndex] != '\0' &&
                 pcHaystack[hayIndex + needleIndex] != '\0' &&
                 pcHaystack[hayIndex + needleIndex] == pcNeedle[needleIndex];
                 needleIndex++) {
                /* No operation inside the loop */
            }
            /* if we reached end of needle, match is found */
            if (pcNeedle[needleIndex] == '\0') {
                return (char *)&pcHaystack[hayIndex];
            }
        }
    }
    /* needle not found in haystack */
    return NULL;
}