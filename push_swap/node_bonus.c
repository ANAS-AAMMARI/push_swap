/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:27:39 by aaammari          #+#    #+#             */
/*   Updated: 2022/12/09 16:30:00 by aaammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_nb_stack	*last_node(t_nb_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
}

t_nb_stack	*new_node(int s, int index)
{
	t_nb_stack	*new;

	new = malloc(sizeof(t_nb_stack));
	if (!new)
		return (NULL);
	new->nb = s;
	new->index = index;
	new->next = NULL;
	return (new);
}

void	free_node(t_nb_stack *node)
{
	t_nb_stack	*tmp;

	if (!node)
		return ;
	while (node)
	{
		tmp = node;
		node = node->next;
		free(tmp);
	}
	free(node);
}

int	add_first(t_nb_stack **stack, int nbr, int index)
{
	t_nb_stack	*new;

	if (!stack)
		return (0);
	new = new_node(nbr, index);
	if (!new)
		return (0);
	if (!*stack)
	{
		*stack = new;
		return (1);
	}
	new->next = *stack;
	*stack = new;
	return (1);
}

void	fill_stack_a(t_nb_stack **stack, char **av, int len)
{
	int	number;

	if ((len + 1) > 0 && valid_numbers(av))
	{
		while (len >= 0)
		{
			if (!check_nbrs((char *)av[len]))
				print_errors();
			number = ft_atoi(av[len]);
			if (number < -2147483648 || number > 2147483647)
				print_errors();
			if (!check_exist_nbr(stack, number)
				|| !add_first(stack, ft_atoi(av[len]), get_nb_index(av, len)))
			{
				free_node(*stack);
				print_errors();
			}
			len--;
		}
	}
	else
		print_errors();
}
