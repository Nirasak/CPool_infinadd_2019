/*
** EPITECH PROJECT, 2019
** my_revstr.c
** File description:
** my_revstr
*/

#include "my.h"

char *my_revstr(char *str)
{
    char c;
    int j = my_strlen(str) - 1;

    for (int i = 0; i < j; i++) {
        c = str[i];
        str[i] = str[j];
        str[j] = c;
        j--;
    }
    return (str);
}
