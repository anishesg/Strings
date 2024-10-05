/* strp.c
 * Pointer-based implementation of the Str module.
 * Author: anish kataria
 */

#include <stddef.h>
#include <assert.h>
#include "str.h"

size_t Str_getLength(const char pcSrc[]) {
    const char *pcIter = pcSrc;
    assert(pcSrc != NULL);

    while (*pcIter) {
        pcIter++;
    }
    return (size_t)(pcIter - pcSrc);
}

char *Str_copy(char pcDest[], const char pcSrc[]) {
    char *pcDestIter = pcDest;
    assert((pcDest != NULL) && (pcSrc != NULL));

    while ((*pcDestIter++ = *pcSrc++)) {
        /* Copy each character from pcSrc to pcDest */
    }
    return pcDest;
}

char *Str_concat(char pcDest[], const char pcSrc[]) {
    char *pcDestEnd = pcDest;
    assert((pcDest != NULL) && (pcSrc != NULL));

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
    const char *str1 = pcStr1;
    const char *str2 = pcStr2;
    assert((pcStr1 != NULL) && (pcStr2 != NULL));

    while (*str1 && (*str1 == *str2)) {
        str1++;
        str2++;
    }
    return (int)((unsigned char)*str1 - (unsigned char)*str2);
}

char *Str_search(const char pcHaystack[], const char pcNeedle[]) {
    assert((pcHaystack != NULL) && (pcNeedle != NULL));

    if (*pcNeedle == '\0') {
        return (char *)pcHaystack;
    }

    const char *hayIter = pcHaystack;
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