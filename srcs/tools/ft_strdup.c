/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xyou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/19 18:45:00 by xyou              #+#    #+#             */
/*   Updated: 2014/03/19 18:45:04 by xyou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh_tools.h"

char	*ft_strdup(char *str)
{
	char	*tmp;

	tmp = NULL;
	if (!str)
		return (NULL);
	tmp = (char *)malloc(sizeof(*tmp) * (ft_strlen(str) + 1));
	if (tmp)
		ft_strcpy(tmp, str);
	return (tmp);
}
