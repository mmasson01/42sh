/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tablecpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xyou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/19 18:50:55 by xyou              #+#    #+#             */
/*   Updated: 2014/03/19 18:50:59 by xyou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh_tools.h"

void	ft_tablecpy(char **new_table, char **old_table)
{
	int		i;

	i = 0;
	if (old_table)
	{
		while (old_table[i])
		{
			new_table[i] = old_table[i];
			i++;
		}
	}
}
