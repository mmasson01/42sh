/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writefile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 19:08:43 by jmery             #+#    #+#             */
/*   Updated: 2014/03/18 12:14:55 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

int		ft_open_file(char *name)
{
	int		fd;

	if (!name)
		return (-1);
	fd = open(name, O_RDONLY);
	if (fd == -1)
	{
		ft_puterror("42sh: ");
		ft_puterror(name);
		ft_puterror(": ");
		return (ft_puterror("No such file\n"));
	}
	return (fd);
}

void	ft_close_file(int fd)
{
	if (fd != -1)
	{
		if (close(fd) == -1)
			ft_puterror("42sh: Error closing file\n");
	}
}

int		ft_writefile(char *name, int fdf)
{
	int		fd;
	int		ret;
	char	buf[BUF_SIZE];
	char	*toprint;

	fd = creat(name, S_IRWXU);
	if (fdf == -1)
		fdf = shell->fdy;
	if (fd == -1)
		return (ft_puterror("42sh: Error creating file\n"));
	ret = ft_read(fdf, buf, BUF_SIZE);
	while (ret)
	{
		toprint = ft_strndup(buf, ret);
		ft_putstr_fd(toprint, fd);
		if (ret < BUF_SIZE)
			ret = 0;
		else
			ret = ft_read(fdf, buf, BUF_SIZE);
		if (toprint)
			free(toprint);
	}
	if (close(fd) == -1)
		return (ft_puterror("42sh: Error closing file\n"));
	return (1);
}

int		ft_appendfile(char *name, int fdf)
{
	int		fd;
	int		ret;
	char	buf[BUF_SIZE];
	char	*toprint;

	fd = open(name, O_CREAT|O_WRONLY|O_APPEND, S_IRWXU);
	if (fdf == -1)
		fdf = shell->fdy;
	if (fd == -1)
		return (ft_puterror("42sh: Error opening file\n"));
	ret = ft_read(fdf, buf, BUF_SIZE);
	while (ret)
	{
		toprint = ft_strndup(buf, ret);
		ft_putstr_fd(toprint, fd);
		if (ret < BUF_SIZE)
			ret = 0;
		else
			ret = ft_read(fdf, buf, BUF_SIZE);
		if (toprint)
			free(toprint);
	}
	if (close(fd) == -1)
		return (ft_puterror("42sh: Error closing file\n"));
	return (1);
}
