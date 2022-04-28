/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 13:52:02 by aaammari          #+#    #+#             */
/*   Updated: 2022/04/28 03:04:34 by aaammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include<unistd.h>
# include<stdlib.h>
# include<stdio.h>

typedef struct st_number
{
	int					nb;
	int					index;
	struct st_number	*next;
}t_nb_stack;

char		*ft_strjoin(char const *s1, char const *s2);
long		ft_atoi(const char *str);
size_t		ft_strlen(const char *s);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		**ft_split(char const *s, char c);
char		*ft_strdup(const char *s1);
int			check_valid(int ac, char **av, int i, int j);
void		check_sorted(t_nb_stack *stack_a);
void		check_nbr(char **split);
t_nb_stack	*fill(char **split, int len);
char		**free_alloc(char **str);
t_nb_stack	*first_node(t_nb_stack *node);
t_nb_stack	*last_node(t_nb_stack *node);
void		free_node(t_nb_stack *node);
t_nb_stack	*new_node(char *s, int index);
int			ft_lstsize(t_nb_stack *lst);
void		add_back(t_nb_stack **old, t_nb_stack *node);
t_nb_stack	*check_all(int ac, char *av[]);
void		swap(t_nb_stack **head, char *s);
void		put_char(char c[2]);
void		ss(t_nb_stack **a, t_nb_stack **b);
void		push_ab(t_nb_stack **b, t_nb_stack **a, char *s);
void		rotate(t_nb_stack **a, char *s);
void		rr(t_nb_stack **a, t_nb_stack **b);
void		rev_rotate(t_nb_stack **a, char *s);
void		rrr(t_nb_stack **a, t_nb_stack **b);
void		sort_tree(t_nb_stack **a);
int			nb_max(t_nb_stack *a);
char		*ft_strtrim(char *s1, char *set);
char		*ft_strchr(char *s, int c);

#endif