/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/03 15:49:23 by jmery             #+#    #+#             */
/*   Updated: 2014/02/07 14:40:21 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

unsigned int	KEY[15] =
				{	BUF_SIZE, KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT,
					KEY_DEL, CTRL_D, KEY_HOME, KEY_END,
					KEY_SH_LEFT, KEY_SH_RIGHT, KEY_SH_UP, KEY_CT_LEFT,
					KEY_CT_RIGHT, KEY_SH_ERROR};

void	ft_checkkey2(char read_char[], char buf[], t_cmd *data)
{
	if (*(unsigned int *)read_char == KEY_SH_LEFT && hist->histo)
		ft_eventcpy(buf, data);
	else if (*(unsigned int *)read_char == KEY_SH_UP && hist->histo)
		ft_eventcut(buf, data);
	else if (*(unsigned int *)read_char == KEY_SH_RIGHT && hist->histo)
		ft_eventpaste(buf, data);
	else if (*(unsigned int *)read_char == CTRL_D)
		data->exit_cmd = 1;
	else if (*(unsigned int *)read_char != KEY_SH_ERROR)
		tputs(tgetstr("bl", NULL), 1, ft_putchar);
}

void	ft_checkkey(char read_char[], char buf[], t_cmd *data)
{
	if (!data)
		return ;
	if (*(unsigned int *)read_char == KEY_RIGHT && data->i < data->len)
		ft_movecursor(data->i, data->i + 1, data);
	else if (*(unsigned int *)read_char == KEY_LEFT && data->i != 0)
		ft_movecursor(data->i, data->i - 1, data);
	else if (*(unsigned int *)read_char == KEY_DEL && data->i != 0)
		ft_eventkeydel(buf, data);
	else if (*(unsigned int *)read_char == KEY_UP && hist->histo)
		ft_eventkeyup(buf, data);
	else if (*(unsigned int *)read_char == KEY_DOWN && hist->histo)
		ft_eventkeydown(buf, data);
	else if (*(unsigned int *)read_char == KEY_HOME && data->i != 0)
		ft_movecursor(data->i, 0, data);
	else if (*(unsigned int *)read_char == KEY_END && data->i < data->len)
		ft_movecursor(data->i, data->len, data);
	else if (*(unsigned int *)read_char == KEY_CT_LEFT && data->i != 0)
		ft_eventshiftleft(buf, data);
	else if (*(unsigned int *)read_char == KEY_CT_RIGHT && data->i < data->len)
		ft_eventshiftright(buf, data);
	else
		ft_checkkey2(read_char, buf, data);
}

int		ft_isonekey(char read_char[])
{
	int		i;

	i = 0;
	while (KEY[i])
	{
		if (*(unsigned int *)read_char == KEY[i])
			return (1);
		i++;
	}
	if (!ft_isprintable(*read_char))
		return (1);
	return (0);
}

size_t	ft_movecursor(unsigned int i, unsigned int j, t_cmd *data)
{
	if (i > j)
	{
		while (i > j)
		{
			tputs(tgetstr("le", NULL), 1, ft_putchar);
			i--;
		}
		if (data)
			data->i = j;
	}
	else if (i < j)
	{
		while (i < j)
		{
			tputs(tgetstr("nd", NULL), 1, ft_putchar);
			i++;
		}
		if (data)
			data->i = j;
	}
	return (j);
}