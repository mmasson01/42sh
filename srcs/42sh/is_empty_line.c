/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_empty_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 20:22:39 by mmasson           #+#    #+#             */
/*   Updated: 2014/03/18 12:14:34 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

void	aff_exit_value(void)
{
	ft_putstr("42sh: Exit: ");
	ft_putnbr(shell->exit_value & 255);
	ft_putchar('\n');
}

int		ft_is_empty_line(char *cmd)
{
	int		i;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i] != ' ')
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}