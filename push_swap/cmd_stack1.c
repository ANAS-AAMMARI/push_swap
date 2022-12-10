/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_stack1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 18:18:31 by aaammari          #+#    #+#             */
/*   Updated: 2022/12/06 11:39:08 by aaammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate(t_nb_stack **a, char *s)
{
	t_nb_stack	*tmp;

	if (!a || !*a || !(*a)->next)
		return ;
	tmp = *a;
	while (tmp->next)
		tmp = tmp->next;
	add_first(a, tmp->nb, tmp->index);
	remove_last(a);
	ft_putendl_fd(s, 1);
}

void	rrr(t_nb_stack **a, t_nb_stack **b)
{
	rev_rotate(a, "");
	rev_rotate(b, "rrr");
}
