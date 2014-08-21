/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_without.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xyou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/19 18:55:16 by xyou              #+#    #+#             */
/*   Updated: 2014/03/19 18:55:17 by xyou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh_tools.h"

void	ft_putstr_without(char *str, char c)
{
	int		i;

	if (str == NULL)
		return ;
	i = -1;
	while (str[++i])
	{
		if (str[i] != c)
			ft_putchar(str[i]);
	}
}
