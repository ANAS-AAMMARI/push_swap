/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 17:02:23 by aaammari          #+#    #+#             */
/*   Updated: 2022/04/27 16:20:59 by aaammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	rev_rotate(t_nb_stack **a, char *s)
{
	t_nb_stack	*first;
	t_nb_stack	*lst;

	if (!*a)
		return ;
	first = *a;
	lst = last_node(*a);
	lst->next = first;
	first->next->next = NULL;
	*a = lst;
	put_char(s);
}

void	rrr(t_nb_stack **a, t_nb_stack **b)
{
	rev_rotate(a, "");
	rev_rotate(b, "rrr");
}
