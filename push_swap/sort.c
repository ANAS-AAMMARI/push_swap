/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 09:10:34 by aaammari          #+#    #+#             */
/*   Updated: 2022/12/10 10:09:33 by aaammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_nb_stack *a)
{
	t_nb_stack	*tmp;

	if (a == NULL)
		return (0);
	tmp = a;
	while (tmp->next)
	{
		if (tmp->next->nb < tmp->nb)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	sort_tree(t_nb_stack **a)
{
	int	sz;

	sz = ft_list_size(*a);
	if (sz < 2)
		return ;
	else if (sz == 2)
		swap_ab(a, "sa");
	else if (sz == 3)
	{
		if (large_number(*a) == 0)
			rotate_ab(a, "ra");
		if (large_number(*a) == 1)
			rev_rotate(a, "rra");
		if (!is_sorted(*a))
			swap_ab(a, "sa");
	}
}

void	sort_five(t_nb_stack **a, t_nb_stack **b)
{
	int	sz;
	int	idx;
	int	i;

	i = 0;
	if (ft_list_size(*a) == 5 || ft_list_size(*a) == 4)
	{
		while (i++ < 2)
		{
			sz = ft_list_size(*a);
			idx = small_number(*a);
			if (idx <= (sz - 1) / 2)
				while (idx-- > 0)
					rotate_ab(a, "ra");
			else if (idx > (sz - 1) / 2)
				while (sz-- > idx)
					rev_rotate(a, "rra");
			push_ab(b, a, "pb");
		}
		sort_tree(a);
		while (i-- > 0)
			push_ab(a, b, "pa");
	}
}

void	partof_final_sort(t_nb_stack **a, t_nb_stack **b)
{
	int	start_part;
	int	end_part;

	start_part = 0;
	end_part = 0.0525 * ft_list_size(*a) + 8.75;
	while (*a)
	{
		if ((*a)->index < end_part && (*a)->index > start_part)
		{
			push_ab(b, a, "pb");
			end_part++;
			start_part++;
		}
		else if ((*a)->index < start_part || (*a)->index < end_part)
		{
			push_ab(b, a, "pb");
			rotate_ab(b, "rb");
			end_part++;
			start_part++;
		}
		else
			rotate_ab(a, "ra");
	}
}

void	final_sort(t_nb_stack **a, t_nb_stack **b)
{
	int	max_index;
	int	size;

	if (ft_list_size(*a) <= 3)
		sort_tree(a);
	else if (ft_list_size(*a) <= 5)
		sort_five(a, b);
	else
	{	
		partof_final_sort(a, b);
		while (*b)
		{
			size = ft_list_size(*b);
			max_index = large_number(*b);
			if (max_index <= (size - 1) / 2)
				while (max_index-- > 0)
					rotate_ab(b, "rb");
			else if (max_index > (size - 1) / 2)
				while (size-- > max_index)
					rev_rotate(b, "rrb");
			push_ab(a, b, "pa");
		}
	}
}
