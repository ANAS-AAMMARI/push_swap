/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 02:37:44 by aaammari          #+#    #+#             */
/*   Updated: 2022/04/28 02:42:02 by aaammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

char	*ft_strchr(char *s, int c)
{
	int	r;
	int	i;

	i = 0;
	r = ft_strlen(s);
	while (i <= r)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char *s1, char *set)
{
	int	b;

	if (!s1)
		return (0);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	b = ft_strlen(s1);
	while (b && ft_strchr(set, s1[b]))
		b--;
	return (ft_substr(s1, 0, b + 1));
}
