/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_helper2_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 10:39:31 by aaammari          #+#    #+#             */
/*   Updated: 2022/12/08 10:37:30 by aaammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t		i;

	i = 0;
	if (dstsize > 0)
	{
		while (i < dstsize - 1 && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

int	ft_list_size(t_nb_stack *lst)
{
	int	i;

	if (!lst)
		return (0);
	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

int	small_number(t_nb_stack *lst)
{
	t_nb_stack	*t;
	int			small;
	int			i;

	i = 0;
	t = lst;
	small = lst->nb;
	if (!lst)
		return (-1);
	while (lst)
	{
		if (lst->nb < small)
			small = lst->nb;
		lst = lst->next;
	}
	while (t)
	{
		if (small == t->nb)
			break ;
		t = t->next;
		i++;
	}
	return (i);
}

void	remove_last(t_nb_stack **stack)
{
	t_nb_stack	*tmp;

	if (!stack || !*stack)
		return ;
	if (!(*stack)->next)
	{
		free(*stack);
		*stack = NULL;
		return ;
	}
	tmp = *stack;
	while (tmp->next->next)
		tmp = tmp->next;
	free(tmp->next);
	tmp->next = NULL;
}
