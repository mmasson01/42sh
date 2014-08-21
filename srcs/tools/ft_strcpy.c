/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xyou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/19 18:52:40 by xyou              #+#    #+#             */
/*   Updated: 2014/03/19 18:54:15 by xyou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh_tools.h"

char	*ft_strcpy(char *dest, char *src)
{
	unsigned int	i;

	i = 0;
	if (!dest || !src)
		return (NULL);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
