/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 15:32:31 by aaammari          #+#    #+#             */
/*   Updated: 2022/04/27 22:25:37 by aaammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

t_nb_stack	*last_node(t_nb_stack *node)
{
	if (!node)
		return (NULL);
	while (node->next)
		node = node->next;
	return (node);
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

t_nb_stack	*new_node(char *s, int index)
{
	t_nb_stack	*new;

	if (!s)
		return (NULL);
	new = malloc(sizeof(t_nb_stack));
	if (!new)
		return (NULL);
	new->nb = ft_atoi(s);
	new->index = index;
	new->next = NULL;
	return (new);
}

void	add_back(t_nb_stack **old, t_nb_stack *node)
{
	t_nb_stack	*last;

	if (!node)
		return ;
	if (!*old)
		*old = node;
	else
	{
		last = last_node(*old);
		last->next = node;
		node->next = NULL;
	}
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
