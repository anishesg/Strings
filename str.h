/* str.h
 * header file for the str module.
 * author: anish kataria
 */

#ifndef STR_H
#define STR_H

#include <stddef.h> /* for size_t */

/* function declarations */

/* 
 * function: str_getlength
 * -----------------------
 * calculates the number of characters in the given string
 *
 * pcsrc: the string whose length is to be determined
 *
 * returns: the length of the string as a size_t value
 */
size_t Str_getLength(const char pcSrc[]);

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
char *Str_copy(char pcDest[], const char pcSrc[]);

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
char *Str_concat(char pcDest[], const char pcSrc[]);

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
int Str_compare(const char pcStr1[], const char pcStr2[]);

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
char *Str_search(const char pcHaystack[], const char pcNeedle[]);

#endif /* STR_H */ss