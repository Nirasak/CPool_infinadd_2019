/*
** EPITECH PROJECT, 2019
** set_struct.c
** File description:
** set struct
*/

#include <stdlib.h>
#include "my.h"
#include "struct.h"

char *rmv_end_string(char *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++);
    i--;
    for (; str[i] == '0' && i > 0; i--)
        str[i] = '\0';
    return (str);
}

int sign_number(char *str)
{
    int sign = 1;
    int i = 0;

    for (; str[i] == '+' || str[i] == '-'; i++) {
        if (str[i] == '-')
            sign = -sign;
        str[i] = '0';
    }
    return (sign);
}

int check_size_str(char *str, char *src)
{
    int x = 0;

    for (; str[x] != '\0' && src[x] != '\0'; x++);
    if (str[x] != '\0')
        return (0);
    if (src[x] != '\0')
        return (1);
    for (; x >= 0; x--) {
        if (str[x] > src[x])
            return (0);
        if (src[x] > str[x])
            return (1);
    }
    return (0);
}

int set_struct_two(add_t *add, char *str, char *src)
{
    int check = 0;

    str = rmv_end_string(my_revstr(str));
    src = rmv_end_string(my_revstr(src));
    if (check_size_str(str, src) == 1) {
        add->str = src;
        add->src = str;
        check = add->s_one;
        add->s_one = add->s_two;
        add->s_two = check;
    } else {
        add->str = str;
        add->src = src;
    }
    return (0);
}

int set_struct(char *str, char *src, add_t *add)
{
    add->len = BIG(my_strlen(str), my_strlen(src));
    add->dest = malloc(sizeof(char) * (add->len + 3));
    if (!add->dest)
        return (-1);
    add->ret = 0;
    add->i = 0;
    add->j = 0;
    add->k = 0;
    add->r_one = 0;
    add->r_two = 0;
    add->s_one = sign_number(str);
    add->s_two = sign_number(src);
    set_struct_two(add, str, src);
    return (0);
}
