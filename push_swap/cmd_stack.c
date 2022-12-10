/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 13:20:30 by aaammari          #+#    #+#             */
/*   Updated: 2022/12/09 14:09:20 by aaammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_ab(t_nb_stack **head, char *c)
{
	int	tmp;

	if (!head || *head == NULL || (*head)->next == NULL)
		return ;
	tmp = (*head)->nb;
	(*head)->nb = (*head)->next->nb;
	(*head)->next->nb = tmp;
	ft_putendl_fd(c, 1);
}

void	ss(t_nb_stack **a, t_nb_stack **b)
{
	swap_ab(a, "");
	swap_ab(b, "ss");
}

void	push_ab(t_nb_stack **in, t_nb_stack **out, char *c)
{
	t_nb_stack	*tmp;

	if (*out == NULL)
		return ;
	tmp = (*out)->next;
	(*out)->next = *in;
	*in = *out;
	*out = tmp;
	ft_putendl_fd(c, 1);
}

void	rotate_ab(t_nb_stack **x, char *c)
{
	t_nb_stack	*first;	
	t_nb_stack	*last;

	if (!x || !*x || !(*x)->next)
		return ;
	first = *x;
	last = last_node(*x);
	(*x) = (*x)->next;
	last->next = first;
	first->next = NULL;
	ft_putendl_fd(c, 1);
}

void	rr(t_nb_stack **a, t_nb_stack **b)
{
	rotate_ab(a, "");
	rotate_ab(b, "rr");
}
