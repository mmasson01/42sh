/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   histotools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/04 12:36:36 by mery              #+#    #+#             */
/*   Updated: 2014/02/04 12:37:30 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

int		ft_isarchivable(char buf[], unsigned int size)
{
	unsigned int	i;
	int				arch;

	i = 0;
	arch = 0;
	while (i < size && arch == 0)
	{
		if (ft_isascii(buf[i]) && buf[i] != '\n' && buf[i] != ' '
			&& buf[i] != '\t' && buf[i] != '\0')
			arch = 1;
		i++;
	}
	return (arch);
}

void	ft_printhistory(void)
{
	int		i;

	if (!hist->histo)
		return ;
	i = ft_tablerange(hist->histo);
	if (i > 16)
		i -= 17;
	else
		i = 0;
	while (hist->histo[i])
	{
		if (hist->histo[i + 1])
			ft_putstr(hist->histo[i]);
		i++;
	}
}