/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_stack1_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 18:18:31 by aaammari          #+#    #+#             */
/*   Updated: 2022/12/08 15:00:31 by aaammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rev_rotate(t_nb_stack **a)
{
	t_nb_stack	*tmp;

	if (!a || !*a || !(*a)->next)
		return ;
	tmp = *a;
	while (tmp->next)
		tmp = tmp->next;
	add_first(a, tmp->nb, tmp->index);
	remove_last(a);
}

void	rrr(t_nb_stack **a, t_nb_stack **b)
{
	rev_rotate(a);
	rev_rotate(b);
}
