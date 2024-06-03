/*
** EPITECH PROJECT, 2024
** memory lib header
** File description:
** header in order to handle memory
*/
#include <stdbool.h>
#include <stdlib.h>

#ifndef GARBAGE_H_
    #define GARBAGE_H_

    // verify if the given actions is valid
    #define ACT_ERROR(act) ((act < 0) || (act > 4)) ? (-1) : (0)

    /// free all address stocked
    #define DUMP 0

    /// store the addr given
    #define STORE 1

    /// check if the addr is stored
    #define IS_STORED 2

    /// free the addr
    #define FREE 3

    /// print the addr store in the garbage
    #define PRINT 4

typedef struct garbage_s {
    void *data;
    struct garbage_s *next;
} garbage_t;


/// @brief handle the garbage object
/// @param data the address of the block allocated
/// @param type the type of the block allocated
/// @param act action to do, free or store
/// @return -1 in error case, else 0 in success
int mem_handler(void *data, int act);

/// @brief stock in the garbage object
/// @param grb the garbage object
/// @param type the type of the data
/// @param data the data to store
void store_in_grabage(garbage_t **grb, void *data);

/// @brief allocate a block of memory of size and stock it in the garbage
/// @param size the size of the block allocated
/// @param type the type of the size allocated
/// @return the address of the block allocated
void *my_malloc(size_t size);

/// @brief copy the block of memory pointed by src into dest
/// @param dest the block of memory where to copy
/// @param src the block of memmory to be copied
/// @param nb the number of memory block to copy
/// @note dest must have enough size
void my_memcpy(void *dest, void *src);

/// @brief duplicate a block of memory
/// @param mem the block of memory to copy
/// @return a pointer to the new block of memory
void *my_memdup(void *mem);

/// @brief extend a memory block to a new size precise by size
/// @param ptr the memeory block to extend
/// @param size the size to extend the memory
/// @return the new block of memory allocated
/// @note the extended size is not initialized
void *my_realloc(void *ptr, size_t size);


/// @brief count the len of block of memory
/// @param ptr the block of memory to count the len
/// @return the len of the block of memory
int my_memlen(void *ptr);

/// @brief free the data
/// @param data the data to free
void my_free(void *data);

/// @brief print the length, size and the address of the allocated block
/// @param grb the garbage object that store the data
void print_garbage(garbage_t *grb);

/// @brief free the garbage structure
/// @param grb the garbage object
void free_garbage(garbage_t *grb);

/// @brief delete an element of the garabage structure
/// @param grb the garbage object
/// @param data the data to delete
void del_in_garbage(garbage_t **grb, void *data);

#endif /* !GARBAGE_H_ */
