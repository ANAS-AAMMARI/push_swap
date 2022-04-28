/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 18:23:06 by aaammari          #+#    #+#             */
/*   Updated: 2022/04/27 16:03:41 by aaammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	swap(t_nb_stack **head, char *s)
{
	int	tmp;	

	if (head == NULL || (*head)->next == NULL)
		return ;
	tmp = (*head)->nb;
	(*head)->nb = (*head)->next->nb;
	(*head)->next->nb = tmp;
	put_char(s);
}

void	ss(t_nb_stack **a, t_nb_stack **b)
{
	swap(a, "");
	swap(b, "ss");
}

void	push_ab(t_nb_stack **b, t_nb_stack **a, char *s)
{
	t_nb_stack	*tmp;

	tmp = *b;
	if (*b == NULL)
		return ;
	add_back(a, *b);
	*b = tmp->next;
	put_char(s);
}

void	rotate(t_nb_stack **a, char *s)
{
	t_nb_stack	*first;
	t_nb_stack	*lst;

	if (!*a || !(*a)->next)
		return ;
	first = *a;
	lst = last_node(*a);
	lst->next = first;
	*a = first->next;
	first->next = NULL;
	put_char(s);
}

void	rr(t_nb_stack **a, t_nb_stack **b)
{
	rotate(a, "");
	rotate(b, "rr");
}
