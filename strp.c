/* strp.c
 * Pointer-based implementation of the Str module.
 * Author: anish kataria
 */

#include <stddef.h>
#include <assert.h>
#include "str.h"

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
            const char *h = hayIter;
            const char *n = pcNeedle;

            /* Start comparing from current position */
            for (; *n != '\0' && *h != '\0' && *h == *n; h++, n++) {
                /* No operation inside the loop */
            }

            /* If we reached the end of needle, match is found */
            if (*n == '\0') {
                return (char *)hayIter;
            }
        }
    }

    /* Needle not found */
    return NULL;
}