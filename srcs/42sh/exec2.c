/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 11:12:39 by mery              #+#    #+#             */
/*   Updated: 2014/03/18 12:07:11 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

int		ft_exec_tree6(t_node *tree, int fd_entry)
{
	int		fd;

	fd = -1;
	if (ft_strcmp(tree->cmd, "||") == 0)
	{
		fd = ft_exec_tree(tree->left, fd_entry);
		if (fd != -1)
		{
			if (!ft_printcmd(fd))
				fd = ft_exec_tree(tree->right, fd_entry);
			else
				fd = -1;
		}
	}
	else if (ft_check_isnot_builtin(tree->cmd) == EXIT_SUCCESS)
	{
		if (tree->position == 1)
			ft_pipecmd(tree->cmd, fd_entry, shell->fdy);
		else
			fd = ft_pipeentry(tree->cmd, fd_entry);
	}
	return (fd);
}