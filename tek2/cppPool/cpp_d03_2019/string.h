/*
** EPITECH PROJECT, 2020
** string
** File description:
** module string
*/

#ifndef LIBSTRING_H_
#define LIBSTRING_H_

#include <stddef.h>

typedef struct string_h {
    char *str;
    void (*string_init)(struct string_h *, const char *);
    void (*string_destroy)(struct string_h *);
    void (*assign_s)(struct string_h *, const struct string_h *);
    void (*assign_c)(struct string_h *, const char *);
    void (*append_s)(struct string_h *, const struct string_h *);
    void (*append_c)(struct string_h *, const char *);
    char (*at)(const struct string_h *, size_t);
    void (*clear)(struct string_h *);
    int (*size)(const struct string_h *);
    int (*compare_s)(const struct string_h *, const struct string_h *);
    int (*compare_c)(const struct string_h *, const char *);
    size_t (*copy)(const struct string_h *, char *, size_t, size_t);
    const char *(*c_str)(const struct string_h *);
    int (*empty)(const struct string_h *);
    int (*find_s)(const struct string_h *, const struct string_h *, size_t);
    int (*find_c)(const struct string_h *, const char *, size_t);
    void (*insert_c)(struct string_h *, size_t, const char *);
    void (*insert_s)(struct string_h *, size_t, const struct string_h *);
    int (*to_int)(const struct string_h *);
} string_t;

void string_init(string_t *, const char *);
void string_destroy(string_t *);
void assign_s(string_t *, const string_t *);
void assign_c(string_t *, const char *);
void append_s(string_t *, const string_t *);
void append_c(string_t *, const char *);
char at(const string_t *, size_t);
void clear(string_t *);
int size(const string_t *);
int compare_s(const string_t *, const string_t *);
int compare_c(const string_t *, const char *);
size_t copy(const string_t *, char *, size_t, size_t);
const char *c_str(const string_t *);
int empty(const string_t *);
int find_s(const string_t *, const string_t *, size_t);
int find_c(const string_t *, const char *, size_t);
void insert_c(string_t *, size_t, const char *);
void insert_s(string_t *, size_t, const string_t *);
int to_int(const string_t *);

#endif /* !STRING_H_ */
