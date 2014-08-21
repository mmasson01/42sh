/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasson <mmasson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/27 16:45:13 by mmasson           #+#    #+#             */
/*   Updated: 2014/03/13 14:47:34 by mmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

t_shell		*init_shell_struct(char **env)
{
	t_shell		*op_shell;

	op_shell = (t_shell*)malloc(sizeof(t_shell));
	if (op_shell)
	{
		op_shell->exit = STAY;
		op_shell->exit_value = 0;
		op_shell->g_myenv = ft_getenv(env);
		tcgetattr(0, &op_shell->term);
		ft_initterm(op_shell->term);
	}
	else
		ft_puterror("42sh: Malloc for struct shell return -1.\n");
	return (op_shell);
}

void		ft_free_struct(void)
{
	ft_freetable(shell->g_myenv);
	if (shell)
		free(shell);
}
