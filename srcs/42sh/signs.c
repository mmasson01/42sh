/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 10:38:22 by mery              #+#    #+#             */
/*   Updated: 2014/03/18 11:59:57 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

char	sign[3] = {'<', '|', '>'};
char	doublesign[4] = {'>', '&', '|', '<'};

int		ft_is_sign(char c)
{
	int		i;
	int		is;

	i = 0;
	is = 0;
	while (i < 3 && is == 0)
	{
		if (c == sign[i])
			is = 1;
		i++;
	}
	return (is);
}

int		ft_is_doublesign(char c)
{
	int		i;
	int		is;

	i = 0;
	is = 0;
	while (i < 4 && is == 0)
	{
		if (c == doublesign[i])
			is = 1;
		i++;
	}
	return (is);
}

int		ft_str_with_sign(char *str)
{
	unsigned int	i;
	int				with;

	i = 0;
	with = 0;
	if (!str)
		return (with);
	while (str[i] && with == 0)
	{
		if (ft_is_sign(str[i]))
			with = 1;
		else if (str[i + 1] && ft_is_doublesign(str[i]))
		{
			if (str[i] == str[i + 1])
				with = 1;
		}
		i++;
	}
	return (with);
}

char	*ft_get_position_last_sign(char *str)
{
	unsigned int	i;
	char			*p;

	i = 0;
	p = NULL;
	if (!str)
		return (p);
	while (str[i])
	{
		if (ft_is_doublesign(str[i]) && str[i] == str[i + 1])
		{
			p = str + i;
			i++;
		}
		else if (ft_is_sign(str[i]))
			p = str + i;
		i++;
	}
	return (p);
}

char	*ft_get_last_sign(char *str)
{
	char	*p;
	char	*sign;

	p = NULL;
	sign = NULL;
	p = ft_get_position_last_sign(str);
	if (p)
	{
		if (p[0])
		{
			if (p[0] == p[1])
				sign = ft_strndup(p, 2);
			else
				sign = ft_strndup(p, 1);
		}
	}
	return (sign);
}
