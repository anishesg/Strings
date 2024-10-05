/* str.h
 * Header file for the Str module.
 * Author: anish kataria
 */

#ifndef STR_H
#define STR_H

#include <stddef.h> /* for size_t */

/* Function declarations */

/* Return the length of the string pcSrc. */
size_t Str_getLength(const char pcSrc[]);

/* Copy the string pcSrc to pcDest. Return pcDest. */
char *Str_copy(char pcDest[], const char pcSrc[]);

/* Add pcSrc to the end of pcDest. Return pcDest. */
char *Str_concat(char pcDest[], const char pcSrc[]);

/* Compare pcStr1 and pcStr2 lexicographically.
 * Return a negative value if pcStr1 < pcStr2,
 * zero if they are equal,
 * or a positive value if pcStr1 > pcStr2.
 */
int Str_compare(const char pcStr1[], const char pcStr2[]);

/* Search pcHaystack for the substring pcNeedle.
 * Return a pointer to the first occurrence of pcNeedle in pcHaystack,
 * or NULL if it's not found.
 */
char *Str_search(const char pcHaystack[], const char pcNeedle[]);

#endif /* STR_H */