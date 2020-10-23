/*
** EPITECH PROJECT, 2020
** my_malloc
** File description:
** my_malloc
*/

#ifndef MY_MALLOC_H_
#define MY_MALLOC_H_

#include <unistd.h>
#include <stdbool.h>

typedef struct stack_s
{
    size_t size;
    bool free;
    struct stack_s *next;
} stack_t;

#define _SIZE sizeof(struct stack_s)
#define JUSTIFY(x) ((((x) - 1) >> 2) << 2) + 4


/*
** Alloc functions
*/
void *malloc(size_t);
void *calloc(size_t, size_t);
void *realloc(void *, size_t);
void free(void *);

/*
** Memory functions
*/
stack_t *find_free_space(stack_t **, size_t);
stack_t *get_space(stack_t*, size_t);
stack_t *get_block(void *);

/*
** tools
*/
void debug(char *);

#endif /* !MY_MALLOC_H_ */
