/*
** EPITECH PROJECT, 2019
** my_strlen
** File description:
** Task 03
*/

int my_strlen(char const *str)
{
    int b = 0;

    while (str[b] != '\0') {
        b++;
    }
    return (b);
}
