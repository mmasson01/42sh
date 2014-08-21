/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tablencpy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xyou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/19 18:51:09 by xyou              #+#    #+#             */
/*   Updated: 2014/03/19 18:51:13 by xyou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh_tools.h"

char	**ft_tablencpy(char **tabledest, char **tablesrc, int n)
{
	int		i;
	char	*str;

	i = 0;
	while (tablesrc[i] && i < n)
	{
		str = (char *)malloc(sizeof(*str) * (ft_strlen(tablesrc[i]) + 1));
		if (str)
		{
			ft_strcpy(str, tablesrc[i]);
			tabledest[i] = str;
		}
		i++;
	}
	tabledest[i] = NULL;
	while (i < n)
	{
		tabledest[i] = NULL;
		i++;
	}
	return (tabledest);
}
