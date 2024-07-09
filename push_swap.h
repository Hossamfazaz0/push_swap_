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
void   ft_add_front(t_stack **stack, t_stack *new);
void	ft_add_back(t_stack **stack, t_stack *new);
void rotate_a(t_stack **sa);
void rotate_b(t_stack **sb);
void rotate_ab(t_stack **sa, t_stack **sb);
void rotate_reverse_a(t_stack **sa);
void print_stack(t_stack *stack);
void rotate_reverse_b(t_stack **sb);
void rotate_reverse_ab(t_stack **sa, t_stack **sb);
void push_a(t_stack**sa,t_stack**sb);
void push_b(t_stack **sb,t_stack **sa);
void swap_a(t_stack **sa);
void swap_b(t_stack **sb);
void swap_ab(t_stack **sa, t_stack **sb);
void sort_three(t_stack **sa);
void sort_four(t_stack **sa, t_stack **sb);
void init_stack(t_stack **sa, char **matrix);
#endif