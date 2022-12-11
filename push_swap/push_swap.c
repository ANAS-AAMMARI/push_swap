/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 14:40:04 by aaammari          #+#    #+#             */
/*   Updated: 2022/12/11 09:57:53 by aaammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_nb_stack *stack)
{
	while (stack)
	{
		printf("%d\n", stack->nb);
		stack = stack->next;
	}
}

int	main(int ac, char *av[])
{
	t_nb_stack	*a;
	t_nb_stack	*b;
	char		**numbers;

	if (ac > 1)
	{
		numbers = get_nbr(av);
		fill_stack_a(&a, numbers, len_nbr(numbers));
		check_sorted(a);
		final_sort(&a, &b);
		free_node(a);
		free_node(b);
		free_2d(numbers);
	}
	return (0);
}
