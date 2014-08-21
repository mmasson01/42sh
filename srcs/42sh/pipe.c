/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 11:32:38 by mery              #+#    #+#             */
/*   Updated: 2014/03/18 12:01:17 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

void	ft_pipecmd(char *cmd, int fd_entry, int fd_exit)
{
	int		pid;

	pid = fork();
	if (pid < 0)
		ft_puterror("42sh: Fork error\n");
	else if (pid == 0)
	{
		dup2(fd_entry, 0);
		dup2(fd_exit, 1);
		ft_getcmd(cmd);
		_exit(1);
	}
	else
		waitpid(pid, 0, 0);
}

int		ft_pipeentry(char *cmd, int fd_entry)
{
	int		pfd3[2];

	if (fd_entry == -1)
		return (-1);
	if (pipe(pfd3) == -1)
		ft_puterror("42sh: Pipe error\n");
	ft_pipecmd(cmd, fd_entry, pfd3[1]);
	close(pfd3[1]);
	return (pfd3[0]);
}

int		ft_printcmd(int fd)
{
	int		ret;
	char	buf[BUF_SIZE];
	char	*toprint;

	if (fd == shell->fdy)
		return (-1);
	ret = ft_read(fd, buf, BUF_SIZE);
	if (ret == -1)
		return (ft_puterror("42sh: Error reading fd\n"));
	if (ret == 0)
		return (0);
	while (ret)
	{
		toprint = ft_strndup(buf, ret);
		ft_putstr(toprint);
		if (toprint)
			free(toprint);
		if (ret < BUF_SIZE)
			ret = 0;
		else
			ret = ft_read(fd, buf, BUF_SIZE);
	}
	return (1);
}
