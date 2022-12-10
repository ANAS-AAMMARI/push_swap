/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_helper3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:59:11 by aaammari          #+#    #+#             */
/*   Updated: 2022/12/10 14:43:59 by aaammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	large_number(t_nb_stack *lst)
{
	t_nb_stack	*t;
	int			large;
	int			i;

	i = 0;
	t = lst;
	large = lst->nb;
	if (!lst)
		return (-1);
	while (lst)
	{
		if (lst->nb > large)
			large = lst->nb;
		lst = lst->next;
	}
	while (t)
	{
		if (large == t->nb)
			break ;
		t = t->next;
		i++;
	}
	return (i);
}

int	get_nb_index(char *av[], int len)
{
	int	j;
	int	length;

	j = 0;
	length = len_nbr(av);
	while (av[j])
	{
		if (ft_atoi(av[len]) < ft_atoi(av[j]))
			length--;
			j++;
	}
	return (length);
}

void	free_2d(char **sp)
{
	int	i;

	i = 0;
	if (!sp)
		return ;
	while (sp[i])
		free(sp[i++]);
	free(sp);
}

void	check_empty_string_param(char **av)
{
	int			i;
	int			j;

	i = 0;
	if (!av)
		return ;
	while (av[i])
	{
		j = 0;
		while (av[i][j] && av[i][j] == ' ')
			j++;
		if (av[i][j] == '\0')
			print_errors();
		i++;
	}	
}
