/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bufplaytools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/04 15:33:10 by mery              #+#    #+#             */
/*   Updated: 2014/02/07 14:41:12 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

void	ft_delstrinbuf(char buf[], unsigned int i, unsigned int len, t_cmd *d)
{
	unsigned int	k;

	k = i;
	while ((k + len) < d->len)
	{
		buf[k] = buf[k + len];
		k++;
	}
	while (k < d->len)
	{
		buf[k] = '\0';
		k++;
	}
}

void	ft_cleanbuf(char buf[], unsigned int len)
{
	unsigned int	i;

	i = 0;
	while (i < len)
	{
		buf[i] = '\0';
		i++;
	}
}

void	ft_printinvbuf(char buf[], t_cmd *data, unsigned int i, unsigned int j)
{
	unsigned int	k;

	k = 0;
	ft_movecursor(data->i, 0, NULL);
	while (k < data->len)
	{
		if (((k >= i && k <= j) || (j < k && k < i)) && j != i)
			tputs(tgetstr("mr", NULL), 1, ft_putchar);
		ft_putchar(buf[k]);
		tputs(tgetstr("me", NULL), 1, ft_putchar);
		k++;
	}
	ft_movecursor(data->len, data->i, NULL);
}

size_t	ft_bufncpy(char buf1[], char buf2[], unsigned int i, unsigned int j)
{
	unsigned int	k;
	unsigned int	l;

	k = 0;
	l = 0;
	while (k < data->len)
	{
		if ((k >= i && k <= j) || (j <= k && k <= i))
		{
			buf1[l] = buf2[k];
			l++;
		}
		k++;
	}
	buf1[l] = '\0';
	return (l);
}

size_t	ft_bufncat(char buf1[], char buf2[], unsigned int l1, unsigned int l2)
{
	unsigned int	k;
	unsigned int	l;

	k = 0;
	l = l1;
	while (k < l2)
	{
		buf1[l] = buf2[k];
		l++;
		k++;
	}
	buf1[l] = '\0';
	return (l);
}