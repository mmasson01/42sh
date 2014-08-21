/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmery <jmery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/21 15:16:00 by jmery             #+#    #+#             */
/*   Updated: 2014/03/21 15:16:02 by jmery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh_tools.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned int	i;
	char			*p;

	i = 0;
	p = (char*)s;
	while (i < n)
	{
		p[i] = '\0';
		i++;
	}
}