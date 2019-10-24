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

char *smallest_string(char **argv)
{
    if (my_strlen(argv[1]) > my_strlen(argv[2]))
        return (argv[2]);
    else if (my_strlen(argv[1]) <  my_strlen(argv[2]))
        return (argv[1]);
    else
        return (argv[1]);
}

char *greatest_string(char **argv)
{
    if (my_strlen(argv[1]) > my_strlen(argv[2]))
        return (argv[1]);
    else if (my_strlen(argv[1]) <  my_strlen(argv[2]))
        return (argv[2]);
    else
        return (argv[1]);
}

char *malloc_it(char **argv)
{
    char *str;
    int i = 0;

    // Create a new string, the size of the longest one +1 for the \0
    str = malloc(sizeof(char) * (my_strlen(greatest_string(argv)) + 1));
    // While we havn't reach the end of the function we fill it with zeros
    while (i != my_strlen(greatest_string(argv))) {
        str[i] = '0';
        i++;
    }
    // We end the string by adding a \0
    str[i] = '\0';
    return (str);
}

char *concatenate_zeros(char *string_to_concat, int longest_string)
{
    // We stock the difference between the strings to concact and the length of the longest one
    int diff = longest_string - my_strlen(string_to_concat);
    // On crée une string qui fera la taille de la différence entre la plus grande et plus petite string
    char *str_x = malloc(sizeof(char) * longest_string + 1);
    int i;
    int y;

    // We put 0 in the new string, until i (0) match the difference between longest number and shortest one
    for (i = 0; i < diff; i++) {
        str_x[i] = '0';
    }
    // We go through the shortest string, add all its chars after the 0 we added before
    for (y = 0; y < my_strlen(string_to_concat); y++) {
        str_x[i] = string_to_concat[y];
        i++;
    }
    // We end the string by a \0.
    str_x[i] = '\0';
    return (str_x);
}

char *add(char **argv)
{
    // We store our longest and our shortest string
    char *long_str = greatest_string(argv);
    int long_str_length = my_strlen(long_str);
    int retain = 0;
    int res = 0;
    // There we store the length of the longest string
    int str_length = my_strlen(greatest_string(argv));
    // We create a new string, as long as the longest string
    char *res_str = malloc_it(argv);
    // We place our shortest string, now the size of the longet one, with zero before the regular digits, in a var
    char *concat_str = concatenate_zeros(smallest_string(argv), str_length);
    char *small_str = concat_str;
    int small_str_length = my_strlen(small_str);

    // While the longest string is different to 0
    while (str_length > -1) {
        if (retain > 0) // If there is a retenu
            long_str[long_str_length] = (((long_str[long_str_length] - 48) + 1) + 48); // We had plus one at the next digit
        res = (small_str[small_str_length] - 48) + (long_str[long_str_length] - 48); // We store the compute of both digit inside an int var
        // If our res value exceed two digits
        if (res > 9) {
            // We store one in the retenu value
            retain = 1;
            // We withdraw ten from the res var
            res = res - 10;
        } else {
            // Else we set our retain value to 0
            retain = 0;
        }
        // We place our computed value (turned into a string) at the right index of our string
        res_str[str_length] = (res + 48);
        printf("%s", res_str);
        str_length--;
        small_str_length--;
        long_str_length--;
    }
    return (res_str);
}

int main(int argc, char **argv)
{
    (void)argc;
    // When both string are positiv
    if (argv[1][0] != '-' && argv[2][0] != '-') {
        my_putchar('X');
        my_putstr(add(argv));
        //add(argv);
    }
    // When both string are neg
    if (argv[1][0] == '-' && argv[2][0] == '-')
        add(argv);
    // When fst str is pos and snd str is neg
    if (argv[1][0] != '-' && argv[2][0] == '-')
        add(argv);
    // When fst str is neg and snd str is pos
    if (argv[1][0] == '-' && argv[2][0] != '-')
        add(argv);
}
