/*
** EPITECH PROJECT, 2020
** Cthulhu
** File description:
** ex00
*/

#ifndef EX00_H_
#define EX00_H_

typedef struct cthulhu_s
{
    int m_power;
    char *m_name;
} cthulhu_t;

typedef struct koala_s
{
    struct cthulhu_s m_parent;
    char m_is_a_legend;
}koala_t;

struct cthulhu_s *new_cthulhu(void);
void print_power(struct cthulhu_s*);
void attack(struct cthulhu_s*);
void sleeping(struct cthulhu_s*);
struct koala_s *new_koala(char *, char);
void eat(struct koala_s*);

#endif /* !EX00_H_ */
