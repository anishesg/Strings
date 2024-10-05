/* str.h
 * Header file for the Str module.
 * Author: Anish Kataria
 */

#ifndef STR_H
#define STR_H

#include <stddef.h> /* For size_t */

/* Function declarations */

/* Returns the length of the string pcSrc (excluding the null terminator). */
size_t Str_getLength(const char pcSrc[]);

/* Copies the string pcSrc to pcDest. Returns pcDest. */
char *Str_copy(char pcDest[], const char pcSrc[]);

/* Concatenates pcSrc to the end of pcDest. Returns pcDest. */
char *Str_concat(char pcDest[], const char pcSrc[]);

/* Compares pcStr1 and pcStr2 lexicographically.
 * Returns negative value if pcStr1 < pcStr2,
 * zero if pcStr1 == pcStr2,
 * positive value if pcStr1 > pcStr2.
 */
int Str_compare(const char pcStr1[], const char pcStr2[]);

/* Searches pcHaystack for the substring pcNeedle.
 * Returns a pointer to the first occurrence of pcNeedle in pcHaystack,
 * or NULL if pcNeedle is not found.
 */
char *Str_search(const char pcHaystack[], const char pcNeedle[]);

#endif /* STR_H */