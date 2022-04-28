/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 17:13:28 by aaammari          #+#    #+#             */
/*   Updated: 2022/04/28 00:51:23 by aaammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"
#include<stdio.h>

void	sort_tree(t_nb_stack **a)
{
	int	pos;
	int	sz;

	sz = ft_lstsize(*a);
	if (sz == 2)
	{
		if ((*a)->nb > (*a)->next->nb)
			swap(a, "sa");
	}
	else if (sz == 1)
		return ;
	else
	{
		pos = nb_max(*a);
		if (pos == 0)
			rotate(a, "ra");
		else if (pos == 1)
			rev_rotate(a, "rra");
		if ((*a)->nb > (*a)->next->nb)
			swap(a, "sa");
	}
}
