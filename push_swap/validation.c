/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 11:09:41 by aaammari          #+#    #+#             */
/*   Updated: 2022/12/05 10:11:07 by aaammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*str_join(char *av[])
{
	char	*str;
	char	*space;
	int		index;

	index = 1;
	space = " ";
	str = NULL;
	while (av[index])
	{
		if (!str)
			str = ft_strdup(av[index]);
		else
		{
			join_str1(&str, space);
			join_str1(&str, av[index]);
		}
		index++;
	}
	return (str);
}

int	check_nbrs(char *str)
{
	int	index;

	index = 0;
	while (str[index])
	{
		if (str[index] == '-' || str[index] == '+')
		{
			index++;
			if (!ft_isdigit(str[index]))
				return (0);
		}
		else if (!ft_isdigit(str[index]))
			return (0);
		index++;
	}
	return (1);
}

int	valid_numbers(char **av)
{
	int		index;
	char	*ptr;

	index = 1;
	while (av[index])
	{
		ptr = av[index];
		if (ptr[0] == '-' || ptr[0] == '+')
		{
			if (!check_nbrs(++ptr))
				return (0);
		}
		else if (!check_nbrs(ptr))
			return (0);
		index++;
	}
	return (1);
}

void	check_sorted(t_nb_stack *stack_a)
{
	t_nb_stack	*tmp;

	if (stack_a == NULL)
		return ;
	tmp = stack_a;
	while (tmp->next)
	{
		if (tmp->next->nb < tmp->nb)
			return ;
		tmp = tmp->next;
	}
	free_node(stack_a);
	exit(0);
}

int	ft_lstsize(t_nb_stack *lst)
{
	int	i;

	if (!lst)
		return (0);
	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
