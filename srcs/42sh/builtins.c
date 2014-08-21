/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 13:09:33 by mmasson           #+#    #+#             */
/*   Updated: 2014/03/18 12:12:55 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

char	**ft_unsetmyenv(char *var, char **env)
{
	int		i;
	int		j;
	char	**newenv;

	if (!var || !env)
		return (env);
	newenv = (char**)malloc(sizeof(newenv) * ft_tablerange(env));
	if (newenv)
	{
		i = -1;
		j = 0;
		while (env[++i])
		{
			if (ft_iskey(env[i], var) == EXIT_SUCCESS)
				free(env[i]);
			else
			{
				newenv[j] = env[i];
				j++;
			}
		}
		newenv[j] = NULL;
	}
	free(env);
	return (newenv);
}

void	ft_setenv(char *var, char *value_to_set)
{
	int		i;
	char	*tmp;

	i = -1;
	tmp = NULL;
	if (var == NULL || value_to_set == NULL)
	{
		ft_puterror("42sh: Usage <setenv variable value_to_set>\n");
		return ;
	}
	while (shell->g_myenv[++i] && tmp == NULL)
	{
		if (ft_iskey(shell->g_myenv[i], var) == EXIT_SUCCESS)
		{
			tmp = ft_create_var(var, value_to_set);
			if (tmp)
			{
				free(shell->g_myenv[i]);
				shell->g_myenv[i] = tmp;
			}
		}
	}
	if (tmp == NULL)
		shell->g_myenv = ft_stock_table(ft_create_var(var, value_to_set), \
			shell->g_myenv);
}

char	**ft_setmyenv(char *var, char *value_to_set, char **env)
{
	int		i;
	char	*tmp;

	i = -1;
	tmp = NULL;
	if (var == NULL || value_to_set == NULL)
		return (env);
	if (env)
	{
		while (env[++i] && tmp == NULL)
		{
			if (ft_iskey(env[i], var) == EXIT_SUCCESS)
			{
				tmp = ft_create_var(var, value_to_set);
				if (tmp)
				{
					free(env[i]);
					env[i] = tmp;
				}
			}
		}
	}
	if (tmp == NULL)
		return (ft_stock_table(ft_create_var(var, value_to_set), env));
	return (env);
}

char	*ft_create_var(char *var, char *value_to_set)
{
	char	*tmp;

	tmp = (char*)malloc(sizeof(tmp) * (ft_strlen(var) + \
	ft_strlen(value_to_set) + 2));
	if (tmp)
	{
		ft_strcpy(tmp, var);
		ft_strncat(tmp, "=", 1);
		ft_strncat(tmp, value_to_set, ft_strlen(value_to_set));
	}
	return (tmp);
}