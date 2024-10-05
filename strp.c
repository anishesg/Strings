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

    pcIter = pcSrc;  // Initialize after declarations
    while (*pcIter) {
        pcIter++;
    }
    return (size_t)(pcIter - pcSrc);
}

char *Str_copy(char pcDest[], const char pcSrc[]) {
    char *pcDestIter;
    assert((pcDest != NULL) && (pcSrc != NULL));

    pcDestIter = pcDest;  // Initialize after declarations
    for (; (*pcDestIter = *pcSrc) != '\0'; pcDestIter++, pcSrc++) {
        /* Copying characters from pcSrc to pcDest */
    }
    return pcDest;
}

char *Str_concat(char pcDest[], const char pcSrc[]) {
    char *pcDestEnd;
    assert((pcDest != NULL) && (pcSrc != NULL));

    pcDestEnd = pcDest;  // Initialize after declarations
    /* Move pcDestEnd to the end of pcDest */
    while (*pcDestEnd) {
        pcDestEnd++;
    }

    /* Append pcSrc to pcDest */
    while ((*pcDestEnd++ = *pcSrc++)) {
        /* Copy each character from pcSrc to the end of pcDest */
    }
    return pcDest;
}

int Str_compare(const char pcStr1[], const char pcStr2[]) {
    const char *str1;
    const char *str2;
    assert((pcStr1 != NULL) && (pcStr2 != NULL));

    str1 = pcStr1;  // Initialize after declarations
    str2 = pcStr2;

    while (*str1 && (*str1 == *str2)) {
        str1++;
        str2++;
    }
    return (int)((unsigned char)*str1 - (unsigned char)*str2);
}

char *Str_search(const char pcHaystack[], const char pcNeedle[]) {
    const char *hayIter;
    assert((pcHaystack != NULL) && (pcNeedle != NULL));

    if (*pcNeedle == '\0') {
        return (char *)pcHaystack;
    }

    hayIter = pcHaystack;  // Initialize after declarations
    while (*hayIter) {
        const char *hayTemp = hayIter;
        const char *needleTemp = pcNeedle;

        while (*hayTemp && *needleTemp && (*hayTemp == *needleTemp)) {
            hayTemp++;
            needleTemp++;
        }

        if (*needleTemp == '\0') {
            return (char *)hayIter;
        }

        hayIter++;
    }
    return NULL;
}