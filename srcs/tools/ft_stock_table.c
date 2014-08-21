/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_table.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xyou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/19 18:54:37 by xyou              #+#    #+#             */
/*   Updated: 2014/03/19 18:54:40 by xyou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh_tools.h"

char	**ft_stock_table(char *tmp, char **table)
{
	int			range;
	char		**new_table;

	range = ft_tablerange(table);
	new_table = (char**)malloc(sizeof(new_table) * (range + 2));
	if (new_table)
	{
		ft_tablecpy(new_table, table);
		new_table[range] = tmp;
		new_table[range + 1] = NULL;
	}
	if (table)
		free(table);
	return (new_table);
}
