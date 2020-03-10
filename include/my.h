/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** my.h
*/

#ifndef MY_H_
#define MY_H_

#include "struct.h"

#define BIG(x, y) ((x) >= (y) ? (x) : (y))
#define ABS(value) ((value) > 0 ? (value) : -(value))

char *my_revstr(char *str);
int my_strlen(char const *str);
int infin_add(add_t *add);
int my_putstr(char const *str);
void my_putchar(char c);
int set_struct(char *str, char *src, add_t *add);
char *my_strdup(char const *str);
int my_strcmp(char const *s1, char const *s2);

#endif
