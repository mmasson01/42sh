/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xyou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/19 18:53:36 by xyou              #+#    #+#             */
/*   Updated: 2014/03/19 18:53:45 by xyou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh_tools.h"

char	*ft_strncpy(char *dest, char *src, size_t n)
{
	unsigned int	i;

	i = 0;
	if (!dest || !src)
		return (NULL);
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
