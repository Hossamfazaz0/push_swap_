#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

typedef struct s_stack
{
    int data;
    int index;
    struct s_stack *next;
} t_stack;


int		ft_strlen(char *str);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char *str, char c);
char	**ft_join_args(char **argv);

#endif