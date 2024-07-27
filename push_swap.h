/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfazaz <hfazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 15:59:01 by hfazaz            #+#    #+#             */
/*   Updated: 2024/07/27 12:38:21 by hfazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <ctype.h>
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
}					t_stack;

int					ft_strlen(char *str);
char				*ft_strdup(const char *s1);
char				*ft_strjoin(char *s1, char *s2);
char				**ft_split(char *str, char c);
char				**ft_join_args(char **argv);
void				ft_add_front(t_stack **stack, t_stack *new);
void				ft_add_back(t_stack **stack, t_stack *new);
double				ft_atoi(const char *str);
void				rotate_a(t_stack **sa);
void				rotate_b(t_stack **sb);
void				rotate_ab(t_stack **sa, t_stack **sb);
void				rotate_reverse_a(t_stack **sa);
void				rotate_reverse_b(t_stack **sb);
void				rotate_reverse_ab(t_stack **sa, t_stack **sb);
void				push_a(t_stack **sa, t_stack **sb);
void				push_b(t_stack **sa, t_stack **sb);
void				swap_a(t_stack **sa);
void				swap_b(t_stack **sb);
void				swap_ab(t_stack **sa, t_stack **sb);
void				sort_three(t_stack **sa);
void				sort_four(t_stack **sa, t_stack **sb);
void				sort(t_stack **sa, t_stack **sb, int *tab, int tab_size);
int					*sort_tab(int *tab, int len);
int					*fill_tab(char **argv);
int					find_max_index(t_stack *sb, int max_val);
void				check_end(int *start, int *end, int tab_size);
void				check_algo(t_stack *sa, t_stack *sb, int *tab, char **argv);
int					check_doubles(int *tab, int len);
void				free_stack(t_stack *sa, t_stack *sb, char **av, int *tab);
void				sort_five(t_stack **sa, t_stack **sb);
void				sort_four(t_stack **sa, t_stack **sb);
void				check_end(int *start, int *end, int tab_size);
int					find_max_index(t_stack *sb, int max_val);
int					list_length(t_stack *stack);
int					get_max(t_stack *stack);
int					check(char **str);
#endif