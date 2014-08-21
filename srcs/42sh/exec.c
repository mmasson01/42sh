/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 13:01:34 by jmery             #+#    #+#             */
/*   Updated: 2014/03/18 12:07:08 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

int		ft_exec_tree5(t_node *tree, int fd_entry)
{
	int		fd;

	fd = -1;
	if (ft_strcmp(tree->cmd, "&&") == 0)
	{
		fd = ft_exec_tree(tree->left, fd_entry);
		if (fd != -1)
		{
			if (ft_printcmd(fd))
				fd = ft_exec_tree(tree->right, fd_entry);
		}
	}
	else
		fd = ft_exec_tree6(tree, fd_entry);
	return (fd);
}

int		ft_exec_tree4(t_node *tree, int fd_entry)
{
	int		fd;
	char	*name;

	fd = -1;
	name = NULL;
	if (ft_strcmp(tree->cmd, ">>") == 0)
	{
		name = ft_strtrim(tree->right->cmd);
		if (tree->left->cmd[0] == '\0' && name)
			fd = 0;
		else if (name)
			fd = ft_exec_tree(tree->left, fd_entry);
		else
			fd = ft_puterror("42sh: parse error near: '>>'\n");
		if (name)
			ft_appendfile(name, fd);
		if (name)
			free(name);
	}
	else
		fd = ft_exec_tree5(tree, fd_entry);
	return (fd);
}

int		ft_exec_tree3(t_node *tree, int fd_entry)
{
	int		fd;

	fd = -1;
	if (ft_strcmp(tree->cmd, "|") == 0)
	{
		if (tree->left && tree->left->cmd && tree->left->cmd[0])
			fd = ft_exec_tree(tree->left, fd_entry);
		else
			fd = ft_puterror("42sh: parse error near: '|'\n");
		if (tree->right && tree->right->cmd && tree->right->cmd[0] && fd != -1)
			fd = ft_exec_tree(tree->right, fd);
		else if (fd != -1)
			fd = ft_puterror("42sh: parse error near: '|'\n");
	}
	else
		fd = ft_exec_tree4(tree, fd_entry);
	return (fd);
}

int		ft_exec_tree2(t_node *tree, int fd_entry)
{
	int		fd;
	char	*name;

	fd = -1;
	name = NULL;
	if (ft_strcmp(tree->cmd, ">") == 0)
	{
		name = ft_strtrim(tree->right->cmd);
		if (tree->left->cmd[0] == '\0' && name)
			fd = shell->fdy;
		else if (name)
			fd = ft_exec_tree(tree->left, fd_entry);
		else
			fd = ft_puterror("42sh: parse error near: '>'\n");
		if (name)
			ft_writefile(name, fd);
		if (name)
			free(name);
	}
	else
		fd = ft_exec_tree3(tree, fd_entry);
	return (fd);
}

int		ft_exec_tree(t_node *tree, int fd_entry)
{
	int		fd;
	char	*name;

	fd = -1;
	name = NULL;
	if (tree == NULL || fd_entry == -1)
		return (-1);
	if (ft_strcmp(tree->cmd, "<") == 0)
	{
		name = ft_strtrim(tree->right->cmd);
		if (name)
		{
			fd_entry = ft_open_file(name);
			if (fd_entry != -1)
				fd = ft_exec_tree(tree->left, fd_entry);
			ft_close_file(fd_entry);
		}
		else
			fd = ft_puterror("42sh: parse error near: '<'\n");
		if (name)
			free(name);
	}
	else
		fd = ft_exec_tree2(tree, fd_entry);
	return (fd);
}

