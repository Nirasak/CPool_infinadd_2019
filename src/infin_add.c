/*
** EPITECH PROJECT, 2019
** infin_add.c
** File description:
** infin_add
*/

#include "my.h"
#include "struct.h"

int my_value(add_t *s)
{
    s->r_one = (s->str[s->j] - '0');
    s->r_two = (s->src[s->k] - '0')  * s->s_two * s->s_one;
    if (s->src[s->k] == '\0')
        s->r_two = 0;
    return (0);
}

int my_add(add_t *s)
{
    if (s->r_one + s->r_two + s->ret < 0) {
        s->dest[s->i] = ABS(s->r_one + s->r_two + s->ret + 10) % 10 + '0';
        s->ret = -1;
        return (0);
    }
    s->dest[s->i] = ABS(s->r_one + s->r_two + s->ret) % 10 + '0';
    s->ret = (s->r_one + s->r_two + s->ret) / 10;
    return (0);
}

int infin_add_end(add_t *s)
{
    int z = 0;

    if (s->ret != 0) {
        s->dest[s->i] = '1';
        s->i++;
    }
    s->dest[s->i] = '\0';
    for (; s->dest[z] != '\0'; z++);
    z--;
    for (; s->dest[z] == '0' && z > 0; z--) {
        s->dest[z] = '\0';
        s->i--;
    }
    if (s->s_one < 0) {
        s->dest[s->i] = '-';
        s->i++;
    }
    s->dest[s->i] = '\0';
    return (0);
}

int infin_add(add_t *s)
{
    if (my_strcmp(s->str, s->src) == 0 && s->s_one < 0) {
        my_putstr("0\n");
        s->dest[0] = '0';
        return (0);
    }
    for (; s->str[s->j] != '\0'; s->i++) {
        my_value(s);
        my_add(s);
        if (s->src[s->k] != '\0')
            s->k++;
        s->j++;
    }
    infin_add_end(s);
    my_putstr(my_revstr(s->dest));
    my_putchar('\n');
    return (0);
}
