/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasson <mmasson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/26 15:55:19 by jmery             #+#    #+#             */
/*   Updated: 2014/03/23 01:35:36 by mmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

int		ft_execcmd(char **cmd, char **env)
{
	int		pid;

	if ((pid = fork()) == -1)
	{
		ft_puterror("42sh: fork fail, return -1.\n");
		return (EXIT_FAILURE);
	}
	if (pid > 0)
		waitpid(pid, 0, 0);
	if (pid == 0)
	{
		execve(cmd[0], cmd, env);
		if (env)
			ft_exeinenv(cmd, env);
		ft_puterror("42sh: command not found: ");
		ft_puterror(cmd[0]);
		ft_puterror("\n");
		_exit(1);
	}
	return (EXIT_SUCCESS);
}

void	ft_exeinenv(char **arg, char **env)
{
	int		i;
	int		find;
	char	**paths;
	char	*path;

	i = -1;
	find = 0;
	while (env[++i] != NULL && find == 0)
	{
		if (ft_iskey(env[i], "PATH") == EXIT_SUCCESS)
		{
			path = env[i]+ 5;
			find = 1;
		}
	}
	i = -1;
	paths = ft_strsplit(path, ':');
	while (paths[++i] != NULL)
	{
		path = ft_topath(arg[0], paths[i]);
		execve(path, arg, env);
		if (path)
			free(path);
	}
	ft_freetable(paths);
}

char	*ft_topath(char *cmd, char *path)
{
	char	*cmdb;

	cmdb = (char*)malloc(sizeof(cmdb) * (ft_strlen(cmd) + ft_strlen(path) + 2));
	if (cmdb)
	{
		ft_strcpy(cmdb, path);
		ft_strncat(cmdb, "/", 1);
		ft_strncat(cmdb, cmd, ft_strlen(cmd));
	}
	return (cmdb);
}