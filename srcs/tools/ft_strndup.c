/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xyou <xyou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/19 18:57:20 by xyou              #+#    #+#             */
/*   Updated: 2014/03/19 18:57:22 by xyou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh_tools.h"

char	*ft_strndup(char *src, int n)
{
	char	*dup;

	dup = NULL;
	if (src == NULL)
		return (NULL);
	dup = (char*)malloc(sizeof(dup) * (n + 1));
	if (dup)
		ft_strncpy(dup, src, n);
	return (dup);
}
