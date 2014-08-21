/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_directory.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/27 17:26:56 by mmasson           #+#    #+#             */
/*   Updated: 2014/03/18 12:13:41 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

void	ft_change_directory(char *path)
{
	int		ret;
	char	buf[BUF_SIZE];

	if (path == NULL || path[0] == '~')
	{
		path = ft_get_home();
		if (path == NULL)
			return ;
	}
	if (path[0] == '-')
		path = ft_get_return();
	getcwd(buf, BUF_SIZE);
	ret = chdir(path);
	if (ret == -1)
	{
		ft_puterror("42sh: cd: no such file or directory: ");
		ft_puterror(path);
		ft_puterror("\n");
	}
	else
	{
		ft_setenv("OLDPWD", buf);
		ft_setenv("PWD", getcwd(buf, BUF_SIZE));
	}
}

char	*ft_get_return(void)
{
	int		i;
	int		find;
	char	*path_return;

	find = 0;
	i = 0;
	while (shell->g_myenv[i] || find == 0)
	{
		if (ft_iskey(shell->g_myenv[i], "OLDPWD") == EXIT_SUCCESS)
		{
			path_return = shell->g_myenv[i];
			path_return = path_return + 7;
			find = 1;
		}
		i++;
	}
	if (find == 0)
	{
		ft_puterror("42sh: OLDPWD variable is unset for cd-, return NULL.\n");
		return (NULL);
	}
	return (path_return);
}

char	*ft_get_home(void)
{
	char	*path_home;
	int		i;
	int		find;

	i = 0;
	find = 0;
	while (shell->g_myenv[i] != NULL || find == 0)
	{
		if (ft_iskey(shell->g_myenv[i], "HOME") == EXIT_SUCCESS)
		{
			path_home = shell->g_myenv[i];
			path_home = path_home + 5;
			find = 1;
		}
		i++;
	}
	if (find == 0)
	{
		ft_puterror("42sh: HOME variable is undefined.\n");
		return (NULL);
	}
	return (path_home);
}