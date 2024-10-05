/* stra.c
 * Array-based implementation of the Str module.
 * Author: anish kataria
 */

#include <stddef.h>
#include <assert.h>
#include "str.h"

size_t Str_getLength(const char pcSrc[]) {
    size_t length = 0;
    assert(pcSrc != NULL);
    /* Count the number of characters until null terminator */
    for (length = 0; pcSrc[length] != '\0'; length++) {
        /* No operation inside the loop */
    }
    return length;
}

char *Str_copy(char pcDest[], const char pcSrc[]) {
    size_t index = 0;
    assert(pcDest != NULL && pcSrc != NULL);
    /* Handle empty source string explicitly */
    if (pcSrc[0] == '\0') {
        pcDest[0] = '\0';
        return pcDest;
    }
    /* Copy characters from pcSrc to pcDest */
    while (pcSrc[index] != '\0') {
        pcDest[index] = pcSrc[index];
        index++;
    }
    /* Add null terminator to the end of pcDest */
    pcDest[index] = '\0';
    return pcDest;
}

char *Str_concat(char pcDest[], const char pcSrc[]) {
    size_t destLen;
    size_t i;
    assert(pcDest != NULL && pcSrc != NULL);
    /* Find the length of pcDest */
    destLen = Str_getLength(pcDest);
    /* Append pcSrc to pcDest */
    for (i = 0; pcSrc[i] != '\0'; i++) {
        pcDest[destLen + i] = pcSrc[i];
    }
    /* Add null terminator at the end */
    pcDest[destLen + i] = '\0';
    return pcDest;
}

int Str_compare(const char pcStr1[], const char pcStr2[]) {
    size_t i;
    assert(pcStr1 != NULL && pcStr2 != NULL);
    /* Compare characters one by one */
    for (i = 0; pcStr1[i] != '\0' && pcStr2[i] != '\0'; i++) {
        if (pcStr1[i] != pcStr2[i]) {
            /* Return -1 if pcStr1 < pcStr2, 1 if pcStr1 > pcStr2 */
            if ((unsigned char)pcStr1[i] < (unsigned char)pcStr2[i]) {
                return -1;
            } else {
                return 1;
            }
        }
    }
    /* Strings are equal up to the length of the shorter one */
    if (pcStr1[i] == pcStr2[i]) {
        return 0;
    } else if ((unsigned char)pcStr1[i] < (unsigned char)pcStr2[i]) {
        return -1;
    } else {
        return 1;
    }
}

char *Str_search(const char pcHaystack[], const char pcNeedle[]) {
    size_t hayIndex = 0;
    assert(pcHaystack != NULL && pcNeedle != NULL);
    /* If needle is empty, return haystack */
    if (pcNeedle[0] == '\0') {
        return (char *)pcHaystack;
    }
    /* Iterate through haystack */
    while (pcHaystack[hayIndex] != '\0') {
        /* If first character matches, check for full needle */
        if (pcHaystack[hayIndex] == pcNeedle[0]) {
            size_t needleIndex = 0;
            /* Check for full needle */
            while (pcNeedle[needleIndex] != '\0') {
                if (pcHaystack[hayIndex + needleIndex] != pcNeedle[needleIndex]) {
                    break;
                }
                needleIndex++;
            }
            /* If we reached end of needle, match is found */
            if (pcNeedle[needleIndex] == '\0') {
                return (char *)(pcHaystack + hayIndex);
            }
        }
        hayIndex++;
    }
    /* Needle not found in haystack */
    return NULL;
}