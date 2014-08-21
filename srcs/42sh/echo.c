/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 17:58:31 by mmasson           #+#    #+#             */
/*   Updated: 2014/03/18 12:14:08 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

void	ft_putarg(char *arg)
{
	int		j;

	j = 0;
	while (arg[j])
	{
		if (arg[j] == '$' && arg[j + 1])
		{
			if (ft_isakey(arg + j + 1) == EXIT_SUCCESS)
				ft_putstr(ft_getkey(arg + j + 1));
			j = ft_strlen(arg);
		}
		else
		{
			ft_putchar(arg[j]);
			j++;
		}
	}
}

void	ft_echo(char **arg)
{
	int		i;

	i = 1;
	if (!arg)
		return ;
	while (arg[i])
	{
		ft_putarg(arg[i]);
		i++;
		if (arg[i])
			ft_putchar(' ');
	}
	ft_putchar('\n');
}
