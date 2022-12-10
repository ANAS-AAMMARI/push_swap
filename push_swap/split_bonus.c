/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 10:08:20 by aaammari          #+#    #+#             */
/*   Updated: 2022/12/08 10:36:54 by aaammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	ft_count_word(char const *tosplit, char delim)
{
	int	lenstr;
	int	nword;

	lenstr = 0;
	nword = 0;
	while (tosplit[lenstr])
	{
		if (tosplit[lenstr] != delim
			&& (tosplit[lenstr + 1] == delim || tosplit[lenstr + 1] == '\0'))
			nword++;
		lenstr++;
	}
	return (nword);
}

static char	**free_alloc(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	i;

	if (!s)
		return (0);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	i = 0;
	sub = malloc((len + 1) * (sizeof(char)));
	if (!sub)
		return (NULL);
	while (i < len)
	{
		sub[i] = s[start];
		start++;
		i++;
	}
		sub[i] = '\0';
	return (sub);
}

char	**ft_split(char const *s, char c)
{
	char		**tab;
	size_t		i;
	size_t		len;

	i = 0;
	if (!s)
		return (0);
	tab = (char **)malloc((ft_count_word(s, c) + 1) * sizeof(char *));
	if (!tab)
		return (tab);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		len = 0;
		while (s[len] && s[len] != c)
			len++;
		if (len != 0)
			tab[i++] = ft_substr(s, 0, len);
		if (!tab[i - 1] && len != 0)
			return (free_alloc(tab));
		s += len;
	}
	tab[i] = NULL;
	return (tab);
}
