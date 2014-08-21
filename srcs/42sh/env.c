/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasson <mmasson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/26 16:13:39 by xyou              #+#    #+#             */
/*   Updated: 2014/02/27 19:33:33 by mmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

int		ft_iskey(char *s1, char *key)
{
	char	*tmp;
	int		keylen;

	if (!s1 || !key)
		return (EXIT_FAILURE);
	keylen = ft_strlen(key);
	tmp = (char*)malloc(sizeof(tmp) * (keylen + 1));
	if (tmp)
	{
		ft_strncpy(tmp, s1, keylen);
		if (ft_strcmp(tmp, key) == 0 && s1[keylen] == '=')
		{
			free(tmp);
			return (EXIT_SUCCESS);
		}
		free(tmp);
	}
	return (EXIT_FAILURE);
}

int		ft_isakey(char *key)
{
	int		i;
	int		find;

	i = 0;
	find = EXIT_FAILURE;
	while (shell->g_myenv[i] && find == EXIT_FAILURE)
	{
		if (ft_iskey(shell->g_myenv[i], key) == EXIT_SUCCESS)
			find = EXIT_SUCCESS;
		i++;
	}
	return (find);
}

char	*ft_getkey(char *key)
{
	int		i;
	char	*content;

	i = 0;
	content = NULL;
	if (!shell->g_myenv || !key)
		return (NULL);
	while (shell->g_myenv[i] && content == NULL)
	{
		if (ft_iskey(shell->g_myenv[i], key) == EXIT_SUCCESS)
			content = shell->g_myenv[i] + ft_strlen(key) + 1;
		i++;
	}
	return (content);
}

char	**ft_getenv(char **env)
{
	int		tablerange;
	char	**myenv;

	tablerange = ft_tablerange(env);
	myenv = (char**)malloc(sizeof(myenv) * (tablerange + 1));
	if (myenv)
		ft_tablencpy(myenv, env, tablerange);
	return (myenv);
}
