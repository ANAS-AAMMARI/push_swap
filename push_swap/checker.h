/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 10:06:07 by aaammari          #+#    #+#             */
/*   Updated: 2022/12/10 14:47:36 by aaammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include<unistd.h>
# include<stdlib.h>
# include <stdio.h>

typedef struct st_number
{
	int					nb;
	int					index;
	struct st_number	*next;
}t_nb_stack;

void		check_empty_string_param(char **av);
char		*get_next_line(int fd);
int			get_nb_index(char *av[], int len);
int			large_number(t_nb_stack *lst);
int			small_number(t_nb_stack *lst);
int			ft_list_size(t_nb_stack *lst);
void		rr(t_nb_stack **a, t_nb_stack **b);
void		rotate_ab(t_nb_stack **x);
void		push_ab(t_nb_stack **in, t_nb_stack **out);
void		ss(t_nb_stack **a, t_nb_stack **b);
void		swap_ab(t_nb_stack **head);
void		rrr(t_nb_stack **a, t_nb_stack **b);
void		rr(t_nb_stack **a, t_nb_stack **b);
void		rev_rotate(t_nb_stack **a);
t_nb_stack	*last_node(t_nb_stack *stack);
void		remove_last(t_nb_stack **stack);
int			add_first(t_nb_stack **stack, int nbr, int index);
int			check_nbrs(char *str);
void		free_node(t_nb_stack *node);
void		check_sorted(t_nb_stack *stack_a);
char		**get_nbr(char *av[]);
void		fill_stack_a(t_nb_stack **stack, char **av, int len);
int			check_exist_nbr(t_nb_stack **stack, int number);
int			valid_numbers(char **av);
void		print_errors(void);
int			len_nbr(char **sp);
char		*str_join(char *av[]);
void		join_str1(char **str, void *buf);
char		*ft_strdup(const char *s1);
char		**ft_split(char const *s, char c);
size_t		ft_strlen(const char *s);
char		*ft_strdup(const char *s1);
char		*ft_strjoin(char const *s1, char const *s2);
long		ft_atoi(const char *str);
void		ft_putendl_fd(char *s, int fd);
int			ft_isdigit(int c);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
#endif