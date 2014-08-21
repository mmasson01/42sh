/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xyou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/19 18:45:12 by xyou              #+#    #+#             */
/*   Updated: 2014/03/19 18:54:24 by xyou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh_tools.h"

char	*ft_getWord(char **p, char c)
{
	unsigned int	len;
	char			*s;
	char			*tmp;

	len = 0;
	s = *p;
	while (s[len] != (char)c && s[len] != '\0')
		len++;
	tmp = (char*)malloc(sizeof(tmp) * (len + 1));
	if (tmp)
	{
		tmp = ft_strncpy(tmp, s, len);
		tmp[len] = '\0';
	}
	*p = s + len;
	return (tmp);
}

size_t	ft_count_word(char *s, char c)
{
	unsigned int	i;
	unsigned int	nb;

	i = 0;
	nb = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] != c)
		{
			nb++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	if (s[i] == '\0' && c == '\0')
		nb = 1;
	return (nb);
}

char	**ft_strsplit(char *str, char c)
{
	char	*p;
	char	*tmp;
	char	**v;
	int		j;

	j = 0;
	p = (char *)str;
	v = (char **)malloc(sizeof(char**) * (ft_count_word(p, c) + 1));
	if (!p || !v)
		return (NULL);
	while (*p != '\0')
	{
		if (*p != (char)c)
		{
			tmp = p;
			v[j] = ft_getWord(&tmp, c);
			p = tmp;
			j++;
		}
		else
			p++;
	}
	v[j] = NULL;
	return (v);
}
