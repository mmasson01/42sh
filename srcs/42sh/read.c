/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmery <jmery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/23 18:45:36 by jmery             #+#    #+#             */
/*   Updated: 2014/03/23 18:45:37 by jmery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

int		char_read(int fd, char read_char[], size_t len)
{
	int		ret;

	if ((ret = read(fd, read_char, len)) == -1)
		ft_puterror("42sh: Error reading fd\n");
	return (ret);
}

int		ft_read(int fd, char buf[], int size)
{
	int		ret;

	ret = 0;
	if (fd == shell->fdy)
		return (ft_tofileread(buf, size));
	else
	{
		if ((ret = read(fd, buf, size)) == -1)
			ft_puterror("42sh: Error reading fg\n");
	}
	return (ret);
}

void	ft_checkfilekey(char read_char[], char buf[], t_cmd *data)
{
	if (!data)
		return ;
	if (*(unsigned int *)read_char == KEY_DEL && data->i != 0)
		ft_eventkeydel(buf, data);
}

int		ft_tofileread(char buf[], size_t size)
{
	char			read_char[5] = {0};
	int				len;

	len = 0;
	if ((data = ft_initdata(buf)) == NULL)
		return (0);
	ft_cleanbuf(buf, size);
	while (!(*(unsigned int *)read_char == CTRL_D) && data->i < size \
		&& !shell->exit && !data->exit_cmd)
	{
		ft_bzero(read_char, 5);
		char_read(shell->fdy, read_char, 4);
		if (!ft_isonekey(read_char))
			ft_makebuf(*read_char, buf, data);
		else
			ft_checkfilekey(read_char, buf, data);
	}
	len = data->len;
	if (data)
		free(data);
	ft_putchar('\n');
	return (len);
}