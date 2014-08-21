/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bufplay.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/03 16:39:15 by jmery             #+#    #+#             */
/*   Updated: 2014/02/04 20:57:55 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

void	ft_printbuf(char buf[], unsigned int i, unsigned int len)
{
	unsigned int	j;

	j = i;
	while (j < len)
	{
		if (buf[j])
			ft_putchar(buf[j]);
		j++;
	}
}

void	ft_insertinbuf(char buf[], char c, unsigned int i, unsigned int len)
{
	unsigned int	j;

	j = len;
	while (j > i)
	{
		buf[j] = buf[j - 1];
		j--;
	}
	buf[i] = c;
}

void	ft_delinbuf(char buf[], unsigned int i, unsigned int len)
{
	unsigned int	j;

	j = i;
	while (j < len)
	{
		buf[j] = buf[j + 1];
		j++;
	}
}

void	ft_strtobuf(char buf[], char *str)
{
	int		i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		buf[i] = str[i];
		i++;
	}
	buf[i] = '\0';
}

size_t	ft_makebuf(char c, char buf[], t_cmd *data)
{
	ft_putchar(c);
	if (data->i < data->len && c != '\n')
	{
		ft_insertinbuf(buf, c, data->i, data->len + 1);
		ft_printbuf(buf, data->i + 1, data->len + 1);
		ft_movecursor(data->len + 1, data->i + 1, NULL);
	}
	if (data->i == data->len)
		buf[data->i] = c;
	data->len++;
	data->i++;
	return (1);
}
