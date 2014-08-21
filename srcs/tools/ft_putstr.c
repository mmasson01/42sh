/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xyou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/19 18:46:05 by xyou              #+#    #+#             */
/*   Updated: 2014/03/19 18:46:07 by xyou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh_tools.h"

void	ft_putstr(char *str)
{
	int		i;

	if (str == NULL)
		return ;
	i = -1;
	while (str[++i])
		ft_putchar(str[i]);
}
