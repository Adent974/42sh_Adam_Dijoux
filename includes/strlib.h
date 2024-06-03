/*
** EPITECH PROJECT, 2024
** str lib header
** File description:
** header in order to handle strings
*/

#ifndef STRLIB_H_
    #define STRLIB_H_
    #include <stdbool.h>

    // check if the char is a num
    #define IS_NUM(char) (char > 47 && char < 58) ? (true) : (false)

    // check if the char is a upper letter
    #define IS_UPPER(char) (char > 64 && char < 91) ? (true) : (false)

    // check if the char is a lower letter
    #define IS_LOWER(char) (char > 96 && char < 123) ? (true) : (false)

    // check if the char is a letter
    #define IS_ALPHA(char) (IS_LOWER(char) || IS_UPPER(char)) ? (1) : (0)

    // check if the char is alphanumerique character
    #define IS_ALPHANUM(char) (IS_NUM(char) || IS_ALPHA(char)) ? (1) : (0)

/// @brief dupliacte a string
/// @param str the string to be duplicated
/// @return returns a pointer to the strings
char *my_strdup(char *str);

/// @brief count the len of a string
/// @param str the string to be counter
/// @return return the len of the string
int my_strlen(char *str);

/// @brief copy a string into a another
/// @param dest the destination to copy
/// @param src the source to be copied
/// @return the number of bytes copied
/// @note don't forget the null byte in the size of dest
int my_strcpy(char *dest, char *src);

/// @brief concatenate two strings together
/// @param dest the destination to concatenate the two strings
/// @param s1 the firs strings to be concateneted
/// @param s2 the second strings to be concatenated
void my_strcat(char *dest, char *s1, char *s2);

/// @brief cocatenate two strings but allocated it
/// @param s1 the first strings to concatenated
/// @param s2 the seconds strings to concatenated
/// @return returns a pointer to the strings allocated
char *my_strconcat(char *s1, char *s2);

/// @brief copy nbyte of a string in another string
/// @param dest the destination to copy
/// @param src the string to be copied
/// @param nbyte number of byte to copy
/// @note don't forget the null byte in the size of dest
void my_strncpy(char *dest, char *src, int nbyte);

/// @brief duplicate n byte of a string
/// @param str the string to duplicate
/// @param nbyte the number of byte to duplicate
/// @return returns a pointer to the strings duplicated
char *my_strndup(char *str, int nbyte);

/// @brief compare two strings and chek if there are the same
/// @param s1 the first string to compare
/// @param s2 the second string to compare
/// @return negative number if s1 < s2 and positive number in other case
/// @note if s1 == NULL, INT_MAX is returned and if s2 == NULL, -INT_MAX
/// is returned
int my_strcmp(char *s1, char *s2);

/// @brief indicate if the str content is alpha character
/// @param str the string to check
/// @return true if str only contains alpha character
bool my_str_isalpha(char *str);


/// @brief indicate if the str content is alphanum character
/// @param str the string to check
/// @return true if str only contains alphanum character
bool my_str_isalphanum(char *str);

/// @brief indicate if the str content is num character
/// @param str the string to check
/// @return true if str only contains num character
bool my_str_isnum(char *str);

/// @brief indicate if the str content is upper character
/// @param str the string to check
/// @return true if str only contains upper character
bool my_str_isupper(char *str);

/// @brief indicate if the str content is lower character
/// @param str the string to check
/// @return true if str only contains lower character
bool my_str_islower(char *str);

/// @brief append a new character at the end of string
/// @param str the sting to append a char
/// @param c the char to append
/// @return the string with the char append
char *my_strappend(char *str, char c);

/// @brief compare two strings until nbyte
/// @param s1 the first strings to compare
/// @param s2 the second strings to compare
/// @param nbyte the number of byte to compare
/// @return 0 if the two stings is the same,
///         negative number if s2 > s1
///         positive number if s1 > s2
int my_strncmp(char *s1, char *s2, int nbyte);

/// @brief reversed a string
/// @param str the string to reversed
/// @return returns a pointer to the string reversed
char *my_revstr(char *str);

/// @brief count the occurences of a character in a string
/// @param str the string to parse
/// @param c the charactere to count the occurences
/// @return the occurences of c
int my_strocc(char *str, char c);


/// @brief copy a string until a character
/// @param dest the palce to copy the string
/// @param src the string to be copied
/// @param c the character to copy until
/// @return returns the number of byte copied
int my_strcpytil(char *dest, char *src, char c);

/// @brief duplicate a string until a character
/// @param str the string to parse
/// @param c the end character
/// @return a pointer to the new string allocated
char *my_strduptil(char *str, char c);

#endif /* !STRLIB_H_ */
