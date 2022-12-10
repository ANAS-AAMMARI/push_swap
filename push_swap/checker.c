/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 14:40:04 by aaammari          #+#    #+#             */
/*   Updated: 2022/12/09 16:31:01 by aaammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	print_stack(t_nb_stack *stack)
{
	while (stack != NULL)
	{
		printf("%d\n", stack->nb);
		stack = stack->next;
	}
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 != '\0' && *s2 != '\0')
	{
		if (*s1 != *s2)
			return (0);
		s1++;
		s2++;
	}
	if (!(*s1) && !(*s2))
		return (1);
	return (0);
}

void	sort(char *cmd, t_nb_stack **a, t_nb_stack **b)
{
	if (ft_strcmp(cmd, "sa\n"))
		swap_ab(a);
	else if (ft_strcmp(cmd, "sb\n"))
		swap_ab(b);
	else if (ft_strcmp(cmd, "ss\n"))
		ss(a, b);
	else if (ft_strcmp(cmd, "rr\n"))
		rr(a, b);
	else if (ft_strcmp(cmd, "ra\n"))
		rotate_ab(a);
	else if (ft_strcmp(cmd, "rb\n"))
		rotate_ab(b);
	else if (ft_strcmp(cmd, "rra\n"))
		rev_rotate(a);
	else if (ft_strcmp(cmd, "rrb\n"))
		rev_rotate(b);
	else if (ft_strcmp(cmd, "rrr\n"))
		rrr(a, b);
	else if (ft_strcmp(cmd, "pa\n"))
		push_ab(a, b);
	else if (ft_strcmp(cmd, "pb\n"))
		push_ab(b, a);
	else
		print_errors();
}

int	is_sortedd(t_nb_stack *a)
{
	t_nb_stack	*tmp;

	if (a == NULL)
		return (0);
	tmp = a;
	while (tmp->next)
	{
		if (tmp->next->nb < tmp->nb)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	main(int ac, char *av[])
{
	t_nb_stack	*a;
	char		**numbers;
	char		*cmd;
	t_nb_stack	*b;
	static int	i;

	cmd = NULL;
	if (ac > 1)
	{
		numbers = get_nbr(av);
		fill_stack_a(&a, numbers, len_nbr(numbers));
		cmd = get_next_line(0);
		while (cmd)
		{
			sort(cmd, &a, &b);
			free(cmd);
			cmd = get_next_line(0);
		}
		if (is_sortedd(a))
			ft_putendl_fd("OK", 1);
		else
			ft_putendl_fd("KO", 1);
		while (numbers[i])
		{
			free(numbers[i++]);
		}
		free(numbers);
		free_node(a);
		free_node(b);
	}
	return (0);
}
