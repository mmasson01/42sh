/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyevent2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/04 21:22:58 by mery              #+#    #+#             */
/*   Updated: 2014/02/04 21:25:35 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

int		cpylen;
char	cpy[BUF_SIZE];

void	ft_eventcpy(char buf[], t_cmd *data)
{
	int				j;
	int				i;
	char			read_char[5] = {0};

	i = data->i;
	j = 0;
	while ((*(unsigned int *)read_char != KEY_ENTRY)
			&& (*(unsigned int *)read_char != 27) && data->i <= data->len)
	{
		ft_bzero(read_char, 5);
		char_read(shell->fdy, read_char, 4);
		if (*(unsigned int *)read_char == KEY_LEFT && data->i > 0)
			j = ft_movecursor(data->i, data->i - 1, data);
		else if (*(unsigned int *)read_char == KEY_RIGHT && data->i < data->len)
			j = ft_movecursor(data->i, data->i + 1, data);
		else
			tputs(tgetstr("bl", NULL), 1, ft_putchar);
		ft_printinvbuf(buf, data, i, j);
	}
	ft_printinvbuf(buf, data , 0, 0);
	if (j != i && *(unsigned int *)read_char != 27)
	{
		ft_bufncpy(cpy, buf, i, j);
		cpylen = ft_abs(i, j);
	}
}

size_t	ft_toeventcut(char buf[], t_cmd *data)
{
	int				j;
	int				i;
	char			read_char[5] = {0};

	i = data->i;
	j = 0;
	while ((*(unsigned int *)read_char != KEY_ENTRY)
			&& (*(unsigned int *)read_char != 27) && data->i <= data->len)
	{
		ft_bzero(read_char, 5);
		char_read(shell->fdy, read_char, 4);
		if (*(unsigned int *)read_char == KEY_LEFT && data->i > 0)
			j = ft_movecursor(data->i, data->i - 1, data);
		else if (*(unsigned int *)read_char == KEY_RIGHT && data->i < data->len)
			j = ft_movecursor(data->i, data->i + 1, data);
		else
			tputs(tgetstr("bl", NULL), 1, ft_putchar);
		ft_printinvbuf(buf, data, i, j);
	}
	if (j != i && *(unsigned int *)read_char != 27)
	{
		ft_bufncpy(cpy, buf, i, j);
		return (cpylen = ft_abs(i, j));
	}
	return (0);
}

void	ft_eventcut(char buf[], t_cmd *data)
{
	unsigned int	tmplen;
	unsigned int	tmpi;

	if (!data)
		return ;
	tmpi = data->i;
	tmplen = ft_toeventcut(buf, data);
	if (tmplen != 0)
	{
		ft_delstrinbuf(buf, ft_min(tmpi, data->i), tmplen, data);
		data->len = data->len - tmplen;
		ft_movecursor(data->i, 0, NULL);
		tputs(tgetstr("cd", NULL), 1, ft_putchar);
		ft_printbuf(buf, 0, data->len);
		ft_movecursor(data->len, data->i, data);
		if (tmpi < data->i)
		{
			ft_movecursor(tmplen, 0, data);
			data->i += tmpi;
		}
	}
	else
		ft_printinvbuf(buf, data , 0, 0);
}

void	ft_eventpaste(char buf[], t_cmd *data)
{
	char	buftmp[BUF_SIZE];
	int		tmplen;

	if (!data)
		return ;
	if (cpy[0] && cpylen)
	{
		tputs(tgetstr("cd", NULL), 1, ft_putchar);
		ft_bufncpy(buftmp, buf, data->i, data->len);
		tmplen = data->len - data->i;
		ft_bufncat(buf, cpy, data->i, cpylen);
		ft_bufncat(buf, buftmp, cpylen + data->i, tmplen);
		data->i = cpylen + data->i + tmplen;
		data->len = data->i;
		ft_printbuf(buf, data->i - cpylen - tmplen, data->len);
		ft_movecursor(data->i, data->i - tmplen, data);
	}
}