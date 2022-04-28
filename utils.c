/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 14:13:41 by aaammari          #+#    #+#             */
/*   Updated: 2022/04/28 03:10:40 by aaammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	len(char **sp)
{
	int	i;

	i = 0;
	while (sp[i])
		i++;
	return (i);
}

t_nb_stack	*check_all(int ac, char *av[])
{
	int				i;
	int				j;
	char			*join;
	static char		**split;

	i = 0;
	j = 0;
	join = malloc(1);
	if (check_valid(ac, av, i, j))
	{
		while (++i < ac)
		{
			join = ft_strjoin(join, av[i]);
			join = ft_strjoin(join, " ");
		}
		split = ft_split(join, ' ');
		free(join);
		check_nbr(split);
	}
	else
	{
		write(2, "Error\n", 7);
		exit(1);
	}
	return (fill(split, len(split)));
}

void	put_char(char c[3])
{
	if (c[0] == '\0')
		return ;
	write(1, &c[0], 1);
	write(1, &c[1], 1);
	write(1, &c[2], 1);
	write(1, "\n", 1);
}

int	nb_max(t_nb_stack *a)
{
	t_nb_stack	*tmp;
	int			pos;
	int			sz;

	if (!a)
		return (-1);
	tmp = a;
	pos = 0;
	sz = ft_lstsize(a) - 1;
	while (tmp->index != sz && ++pos && tmp->next != NULL)
		tmp = tmp->next;
	return (pos);
}

// int	check_space(char *s)
// {
// 	int	i;

// 	i = 0;
// 	if (!s)
// 		return (0);
// 	while (s[i])
// 	{
// 		if (ft_strchr(s, ' '))
// 		{
// 			/* code */
// 		}
		
// 	}
	
// }
