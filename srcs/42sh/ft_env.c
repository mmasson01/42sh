/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmery <jmery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/20 18:17:07 by jmery             #+#    #+#             */
/*   Updated: 2014/03/20 18:18:37 by jmery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

int		ft_containcar(char *str, char c)
{
	unsigned int	i;
	int				find;

	i = 0;
	find = 0;
	while (str[i] && find == 0)
	{
		if (str[i] == c)
			find = 1;
		else
			i++;
	}
	if (str[i] == '\0')
		i = 0;
	return (i);
}

void	ft_makechoice(char **tmpenv, char **arg, int ready)
{
	if (ready == 1 || tmpenv == NULL)
		ft_execcmd(arg, tmpenv);
	else if (tmpenv)
		ft_printtable(tmpenv);
}

char	**ft_tosetmyenv(char **arg, int len, char **tmpenv, int i)
{
	char	*var;
	char	*key;

	var = ft_strndup(arg[i], len);
	key = ft_strdup(arg[i] + len + 1);
	tmpenv = ft_setmyenv(var, key, tmpenv);
	if (var)
		free(var);
	if (key)
		free(key);
	return (tmpenv);
}

char	**ft_makeenv(char **arg, char **myenv)
{
	unsigned int	i;
	char			**tmpenv;
	int				len;
	int				ready;

	i = 0;
	ready = 0;
	tmpenv = myenv;
	while (arg[i] && ready == 0)
	{
		if (ft_strcmp(arg[i], "-i") == 0)
		{
			ft_freetable(tmpenv);
			tmpenv = NULL;
		}
		else if ((len = ft_containcar(arg[i], '=')) != 0)
			tmpenv = ft_tosetmyenv(arg, len, tmpenv, i);
		else
			ready = 1;
		i++;
	}
	ft_makechoice(tmpenv, arg + i - 1, ready);
	return (tmpenv);
}

void	ft_env(char **arg, char **env)
{
	char	**myenv;

	myenv = ft_getenv(env);
	if (!arg[1] && env)
	{
		if (env[0])
			ft_printtable(env);
		else
			ft_puterror("42sh: env: env is empty\n");
	}
	else
		myenv = ft_makeenv(arg + 1, myenv);
	ft_freetable(myenv);
}
