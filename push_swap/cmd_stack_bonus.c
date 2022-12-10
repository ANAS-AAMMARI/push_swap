/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_stack_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 13:20:30 by aaammari          #+#    #+#             */
/*   Updated: 2022/12/09 14:05:53 by aaammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	swap_ab(t_nb_stack **head)
{
	int	tmp;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	tmp = (*head)->nb;
	(*head)->nb = (*head)->next->nb;
	(*head)->next->nb = tmp;
}

void	ss(t_nb_stack **a, t_nb_stack **b)
{
	swap_ab(a);
	swap_ab(b);
}

void	push_ab(t_nb_stack **in, t_nb_stack **out)
{
	t_nb_stack	*tmp;

	if (*out == NULL)
		return ;
	tmp = (*out)->next;
	(*out)->next = *in;
	*in = *out;
	*out = tmp;
}

void	rotate_ab(t_nb_stack **x)
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
}

void	rr(t_nb_stack **a, t_nb_stack **b)
{
	rotate_ab(a);
	rotate_ab(b);
}
