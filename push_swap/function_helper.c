/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:44:35 by aaammari          #+#    #+#             */
/*   Updated: 2022/12/10 18:52:26 by aaammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_exist_nbr(t_nb_stack **stack, int number)
{
	t_nb_stack	*tmp;

	tmp = *stack;
	while (tmp != NULL)
	{
		if (tmp->nb == number)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	len_nbr(char **sp)
{
	int		i;

	i = 0;
	while (sp[i])
		i++;
	return (i - 1);
}

void	join_str1(char **str, void *buf)
{
	char	*tmp;

	tmp = ft_strjoin(*str, buf);
	if (str != NULL && *str != NULL)
	{
		free(*str);
		*str = NULL;
	}
	*str = tmp;
	return ;
}

char	**get_nbr(char *av[])
{
	char		**split;
	char		*str;

	check_empty_string_param(av);
	str = str_join(av);
	if (!str)
		return (NULL);
	split = ft_split(str, ' ');
	if (!split)
	{
		free(str);
		return (NULL);
	}
	free(str);
	return (split);
}

void	print_errors(void)
{
	ft_putendl_fd("Error", 2);
	exit(1);
}
