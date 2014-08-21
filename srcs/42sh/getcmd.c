/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getcmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/12 12:44:18 by mmasson           #+#    #+#             */
/*   Updated: 2014/03/23 14:05:11 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

int		ft_check_builtins_part_3(char **arg)
{
	if (ft_strcmp(arg[0], "unsetenv") == 0)
	{
		if (!arg[1])
			ft_puterror("42sh: unsetenv:\nusage: unsetenv <key>\n");
		else if (arg[2])
			ft_puterror("42sh: unsetenv: too many arguments\n");
		else if (ft_isakey(arg[1]) == EXIT_FAILURE)
			ft_puterror("42sh: unsetenv: key not found\n");
		else
			shell->g_myenv = ft_unsetmyenv(arg[1], shell->g_myenv);
		return (EXIT_FAILURE);
	}
	else if (ft_strcmp(arg[0], "history") == 0)
	{
		if (arg[1])
			ft_puterror("42sh: history: no arguments required\n");
		else
			ft_printhistory();
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int 	ft_check_builtins_part_2(char **arg)
{
	if (ft_strcmp(arg[0], "setenv") == 0)
	{
		if (arg[1] && arg[2] && arg[3])
			ft_puterror("42sh: setenv: too many arguments\n");
		else
			ft_setenv(arg[1], arg[2]);
		return (EXIT_FAILURE);
	}
	else if (ft_strcmp(arg[0], "env") == 0)
	{
		ft_env(arg, shell->g_myenv);
		return (EXIT_FAILURE);
	}
	else if (ft_strcmp(arg[0], "man") == 0 && arg[1])
	{
		if (ft_strcmp(arg[1], "42shell") == 0)
		{
			ft_strcpy(arg[0], "cat");
			ft_execcmd(arg, shell->g_myenv);
			return (EXIT_FAILURE);
		}
	}
	if (ft_check_builtins_part_3(arg) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int		ft_check_builtins(char **arg, char *cmd)
{
	if (!arg || !cmd)
		return (EXIT_SUCCESS);
	else if (ft_strcmp(arg[0], "exit") == 0)
	{
		shell->exit = NOW_QUIT;
		if (arg[1])
			shell->exit_value = ft_atoi(arg[1]);
		return (EXIT_FAILURE);
	}
	else if (ft_strcmp(arg[0], "echo") == 0)
	{
		ft_echo(arg);
		return (EXIT_FAILURE);
	}
	else if (ft_strcmp(arg[0], "cd") == 0)
	{
		ft_change_directory(arg[1]);
		return (EXIT_FAILURE);
	}
	else if (ft_check_builtins_part_2(arg) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int		ft_check_isnot_builtin(char *cmd)
{
	int		ret;
	char	**arg;

	ret = EXIT_SUCCESS;
	if (!cmd)
		return (ret);
	arg = ft_strsplit(cmd, ' ');
	if (arg)
	{
		if (arg[0])
		{
			if (ft_check_builtins(arg, cmd) == EXIT_FAILURE)
				ret = EXIT_FAILURE;
		}
		ft_freetable(arg);
	}
	return (ret);
}

int		ft_getcmd(char *cmd)
{
	char	**arg;

	if (!cmd)
		return (EXIT_FAILURE);
	arg = ft_strsplit(cmd, ' ');
	if (arg)
	{
		if (arg[0])
			ft_execcmd(arg, shell->g_myenv);
		ft_freetable(arg);
	}
	return (EXIT_SUCCESS);
}
