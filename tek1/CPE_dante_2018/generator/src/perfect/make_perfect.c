/*
** EPITECH PROJECT, 2019
** make_perfect.c
** File description:
** perfect maze generator
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"

void push_on(stack_t **stack, int x, int y)
{
    stack_t *new = malloc(sizeof(*new));

    new->col = x;
    new->line = y;
    new->next = *stack;
    *stack = new;
}

void pop_off(stack_t **stack)
{
    stack_t *tmp = NULL;

    if (*stack == NULL)
        return;
    tmp = (*stack)->next;
    free(*stack);
    *stack = tmp;
}

void freestack(stack_t *stack)
{
    while (stack != NULL)
        pop_off(&stack);
}

void random_dir(gen_t *d, int *neighbour)
{
    int dir = 0;
    int direct[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

    do {
        dir = rand()%4;
    }while (neighbour[dir] != 1);
    d->col = d->col + direct[dir][0];
    d->line = d->line + direct[dir][1];
}

void make_perfect(gen_t *d)
{
    stack_t *stack = NULL;
    int *neighbour = malloc(sizeof(int) * 4);
    int test = 0;

    do {
        if (d->maze[d->line][d->col] == WALL) {
            d->maze[d->line][d->col] = CORRIDOR;
            push_on(&stack, d->col, d->line);
        }
        test = find_neighbour(d, neighbour);
        if (test > 0) {
            random_dir(d, neighbour);
        } else {
            go_back(&stack, d, neighbour);
        }
    }while (stack != NULL);
    make_exit(d);
    freestack(stack);
}