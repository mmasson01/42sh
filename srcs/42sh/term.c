/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/03 12:00:24 by jmery             #+#    #+#             */
/*   Updated: 2014/02/07 10:39:26 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

t_cmd			*data;

int		ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

void	ft_initterm(struct termios term)
{
	if (shell)
		shell->fdy = open(ttyname(0), O_RDWR);
	term.c_lflag &= ~(ICANON);
	term.c_lflag &= ~(ECHO);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	tcsetattr(0, 0, &term);
}

void	ft_endterm(struct termios term)
{
	if (hist->histo)
		ft_freetable(hist->histo);
	term.c_lflag |= ICANON;
	term.c_lflag |= ECHO;
	tcsetattr(0, 0, &term);
}

t_cmd	*ft_initdata(char buf[])
{
	t_cmd	*data;

	data = (t_cmd*)malloc(sizeof(*data));
	if (data)
	{
		data->i = 0;
		data->len = 0;
		data->exit_cmd = 0;
	}
	ft_bzero(buf, BUF_SIZE);
	ft_addtohistorique(buf, 0);
	return (data);
}

size_t	my_read(char buf[], size_t size)
{
	char			read_char[5] = {0};
	int				len;

	if ((data = ft_initdata(buf)) == NULL)
		return (0);
	while (!(*(unsigned int *)read_char == KEY_ENTRY) && data->i < size \
		&& !shell->exit && !data->exit_cmd)
	{
		ft_bzero(read_char, 5);
		char_read(shell->fdy, read_char, 4);
		if (!ft_isonekey(read_char))
			ft_makebuf(*read_char, buf, data);
		else
			ft_checkkey(read_char, buf, data);
	}
	if (data->exit_cmd)
	{
		data->len = 0;
		ft_bzero(buf, BUF_SIZE);
	}
	else
		ft_addtohistorique(buf, data->len);
	len = data->len;
	free(data);
	return (len);
}