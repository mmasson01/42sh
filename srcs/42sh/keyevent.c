/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyevent.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/04 21:22:58 by mery              #+#    #+#             */
/*   Updated: 2014/02/04 21:25:35 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

void	ft_eventkeydel(char buf[], t_cmd *data)
{
	if (!data)
		return ;
	if (data->i != 0)
	{
		if (buf[data->i - 1] != '\n')
		{
			ft_movecursor(data->i, data->i - 1, data);
			tputs(tgetstr("dc", NULL), 1, ft_putchar);
			ft_delinbuf(buf, data->i, data->len);
			data->len--;
		}
	}
}

void	ft_eventkeyup(char buf[], t_cmd *data)
{
	if (!data)
		return ;
	ft_movecursor(data->i, 0, data);
	tputs(tgetstr("cd", NULL), 1, ft_putchar);
	data->len = ft_getnextcmd(buf) - 1;
	ft_printbuf(buf, 0, data->len);
	data->i = data->len;
}

void	ft_eventkeydown(char buf[], t_cmd *data)
{
	if (!data)
		return ;
	ft_movecursor(data->i, 0, data);
	tputs(tgetstr("cd", NULL), 1, ft_putchar);
	data->len = ft_getpreviouscmd(buf) - 1;
	ft_printbuf(buf, 0, data->len);
	data->i = data->len;
}

void	ft_eventshiftright(char buf[], t_cmd*data)
{
	unsigned int	i;
	unsigned int	j;
	int				find;

	if (!data)
		return ;
	find = 0;
	i = data->i;
	j = data->i;
	while (i < data->len && find == 0)
	{
		if (buf[i] == ' ')
			find = 1;
		i++;
	}
	if (find == 1)
		ft_movecursor(j, i, data);
	else
		ft_movecursor(j, data->len, data);
}

void	ft_eventshiftleft(char buf[], t_cmd*data)
{
	unsigned int	i;
	unsigned int	j;
	int				find;

	if (!data)
		return ;
	if (data->i > 1)
		i = data->i - 2;
	else
		i = 0;
	j = data->i;
	find = 0;
	while (i > 0 && find == 0)
	{
		if (buf[i] == ' ')
			find = 1;
		i--;
	}
	if (find == 1)
		ft_movecursor(j, i + 2, data);
	if (i == 0)
		ft_movecursor(j, 0, data);
}