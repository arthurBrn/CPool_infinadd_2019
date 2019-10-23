/*
** EPITECH PROJECT, 2019
** infinadd.c
** File description:
** Infinite Add
*/

#include "my.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char *malloc_it(char **argv)
{
    char *str;
    int length = 0;
    if (my_strlen(argv[1]) > my_strlen(argv[2]))
        length = my_strlen(argv[1]);
    else if (my_strlen(argv[1]) <  my_strlen(argv[2]))
        length = my_strlen(argv[2]);
    if (my_strlen(argv[1]) == my_strlen(argv[2]))
        length = my_strlen(argv[1]);
    return (str = malloc(sizeof(char) * length + 1));
}

char *add(char **argv)
{
    int arg_one = my_strlen(argv[1]);
    int arg_two = my_strlen(argv[2]);
    int retenu = 0;
    int res = 0;
    // We malloc a string that will be the size of the greatest one
    char *str = malloc_it(argv);

    while (arg_one != 0 && arg_two != 0) {
        // We take the two strings last charachters
        res = (argv[1][arg_one] - 48) + (argv[2][arg_two] - 48);
        if (res > 10) {
            retenu = 1;
            res = res - 10;
        }
        arg_one--;
        arg_two--;
    }
    // We'll return a string, mallocked, containning the computed result of both strings
    return (0);
}

int main(int argc, char **argv)
{
    int fst_param = my_strlen(argv[1]);
    int snd_param = my_strlen(argv[2]);

    if (fst_param == snd_param)             // Supposed to return the mallocked string containing our computed results of the two strings
        return my_putstr(add(argv));
    else if (fst_param > snd_param)
        return (0);
    else
        return (0);
    return (0);
}
