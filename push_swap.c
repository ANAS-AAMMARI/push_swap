/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 00:00:48 by aaammari          #+#    #+#             */
/*   Updated: 2022/04/28 03:17:51 by aaammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include<stdio.h>

int	main(int ac, char *av[])
{
	t_nb_stack	*a;
	a = check_all(ac, av);
	// printf("%d\n", a);
	// printf("%d\n", a->next->nb);
	// printf("%d\n", a->next->next->nb);
	sort_tree(&a);
	//printf("%d\n", nb_max(a));
	// printf("-----------------------\n%d\n", a->nb);
	// printf("%d\n", a->next->nb);
	// printf("%d\n", a->next->next->nb);
	return (0);
}
