/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** infin_add
*/

#include <stdlib.h>
#include <stddef.h>
#include "struct.h"
#include "my.h"

int check_error(int ac, char *str, char *src)
{
    if (ac != 3)
        return (-1);
    for (int i = 0; str[i] != '\0'; i++)
        if ((str[i] < '0' || str[i] > '9') && str[i] != '-' && str[i] != '+')
            return (-1);
    for (int i = 0; src[i] != '\0'; i++)
        if ((src[i] < '0' || src[i] > '9') && src[i] != '-' && src[i] != '+')
            return (-1);
    return (0);
}

int main(int ac, char **av)
{
    add_t add;

    if (check_error(ac, av[1], av[2]) == -1)
        return (84);
    if (set_struct(av[1], av[2], &add) == -1)
        return (84);
    infin_add(&add);
    free(add.dest);
    return (0);
}
