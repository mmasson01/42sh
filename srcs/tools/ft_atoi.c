/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xyou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/19 18:42:20 by xyou              #+#    #+#             */
/*   Updated: 2014/03/19 18:42:25 by xyou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh_tools.h"

int		ft_atoi(const char *str)
{
	int		sign;
	int		n;

	n = 0;
	sign = 1;
	while (*str && ft_isspace(*str))
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (ft_isdigit(*str))
	{
		n *= 10;
		n += *str - '0';
		str++;
	}
	return (n * sign);
}
