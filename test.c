#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int to_skip(char c) {
    if (c == ' ' || c == '\t' || c == '-' || c == '+')
        return 1;
    else
        return 0;
}
int check_sign(const char *str) {
    int i = 0;
    while (str[i]) {
        if ((str[i] == '-' || str[i] == '+') && (str[i + 1] == '-' || str[i+ 1] == '+'))
            return 1;
        i++;
    }
    return 0;
}
int is_no_digit(const char *str) {
    int i = 0;
    int len = strlen(str);

    while (len > 0 && to_skip(str[len - 1])) {
        len--;
    }

    if (len == 0 || check_sign(str))
        return 1;

    while (i < len) {
        if (to_skip(str[i])) {
            i++;
        } else if (str[i] < '0' || str[i] > '9') {
            return 1;
        } else {
            i++;
        }
    }
    return 0;
}
int check(char **str)
{
    int i = 1;
    while (str[i])
    {
        if (is_no_digit(str[i]))
            return 0;
        i++;
    }
    return 1;
}
int main(int ac, char **av)
{
    printf("%d\n",check(av));
}