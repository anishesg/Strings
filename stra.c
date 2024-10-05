/* stra.c
 * Array-based implementation of the Str module.
 * Author: [Anish Kataria]
 */

#include <stddef.h>
#include <assert.h>
#include "str.h"

size_t Str_getLength(const char pcSrc[]) {
    size_t length = 0;
    assert(pcSrc != NULL);
    while (pcSrc[length] != '\0') {
        length++;
    }
    return length;
}

char *Str_copy(char pcDest[], const char pcSrc[]) {
    size_t index = 0;
    assert(pcDest != NULL && pcSrc != NULL);
    while (pcSrc[index] != '\0') {
        pcDest[index] = pcSrc[index];
        index++;
    }
    pcDest[index] = '\0';
    return pcDest;
}

char *Str_concat(char pcDest[], const char pcSrc[]) {
    size_t destLength = 0;
    size_t srcIndex = 0;
    assert(pcDest != NULL && pcSrc != NULL);
    /* Find the end of pcDest */
    while (pcDest[destLength] != '\0') {
        destLength++;
    }
    /* Append pcSrc to pcDest */
    while (pcSrc[srcIndex] != '\0') {
        pcDest[destLength + srcIndex] = pcSrc[srcIndex];
        srcIndex++;
    }
    pcDest[destLength + srcIndex] = '\0';
    return pcDest;
}

int Str_compare(const char pcStr1[], const char pcStr2[]) {
    size_t index = 0;
    assert(pcStr1 != NULL && pcStr2 != NULL);

    while (pcStr1[index] != '\0' && pcStr2[index] != '\0') {
        if (pcStr1[index] != pcStr2[index]) {
            return (unsigned char)pcStr1[index] - (unsigned char)pcStr2[index];
        }
        index++;
    }
    return (unsigned char)pcStr1[index] - (unsigned char)pcStr2[index];
}

char *Str_search(const char pcHaystack[], const char pcNeedle[]) {
    size_t hayIndex;
    size_t needleIndex;
    assert(pcHaystack != NULL && pcNeedle != NULL);

    if (pcNeedle[0] == '\0') {
        return (char *)pcHaystack;
    }

    for (hayIndex = 0; pcHaystack[hayIndex] != '\0'; hayIndex++) {
        if (pcHaystack[hayIndex] == pcNeedle[0]) {
            needleIndex = 0;
            while (pcNeedle[needleIndex] != '\0' &&
                   pcHaystack[hayIndex + needleIndex] != '\0' &&
                   pcHaystack[hayIndex + needleIndex] == pcNeedle[needleIndex]) {
                needleIndex++;
            }
            if (pcNeedle[needleIndex] == '\0') {
                return (char *)&pcHaystack[hayIndex];
            }
        }
    }
    return NULL;
}