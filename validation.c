/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 16:16:53 by aaammari          #+#    #+#             */
/*   Updated: 2022/04/28 05:44:00 by aaammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	ft_isdigit(int c)
{
	return (c <= '9' && c >= '0');
}

int	check_valid(int ac, char **av, int i, int j)
{
	if (ac < 2)
		exit(1);
	while (++i < ac)
	{
		j = 0;
		if (!ft_isdigit(av[i][j]) && av[i][j] != '-' && av[i][j] != '+' &&
			av[i][j] != ' ')
			return (0);
		if (av[i][j + 1])
			j++;
		while (av[i][j])
		{
			while (av[i][j] == ' ')
				j++;
			if (!ft_isdigit(av[i][j]))
				return (0);
			j++;
		}
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

void	check_nbr(char **split)
{
	int		i;
	int		j;
	long	tmp;

	i = 0;
	while (split[i])
	{
		j = i + 1;
		while (split[j])
		{
			tmp = ft_atoi(split[i]);
			if ((ft_atoi(split[i]) == ft_atoi(split[j]))
				|| (tmp < -2147483648
					|| tmp > 2147483647))
			{
				write(2, "Error\n", 6);
				free_alloc(split);
				exit(1);
			}
			j++;
		}
		i++;
	}
}

t_nb_stack	*fill(char **split, int len)
{
	int			i;
	int			j;
	int			index;
	t_nb_stack	*node;

	i = 0;
	while (split[i])
	{
		j = 0;
		index = len - 1;
		while (split[j])
			if (ft_atoi(split[i]) < ft_atoi(split[j++]))
				index--;
		if (i == 0)
			node = new_node(split[i], index);
		else
			add_back(&node, new_node(split[i], index));
		i++;
	}
	free_alloc(split);
	check_sorted(node);
	return (node);
}
