/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/12 16:10:22 by mmasson           #+#    #+#             */
/*   Updated: 2014/03/23 14:01:11 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

t_node	*ft_strsplit_to_node(char *cmd, char *sign)
{
	unsigned int	len;
	unsigned int	find;
	t_node			*node;

	node = NULL;
	len = ft_strlen(cmd);
	find = 0;
	while (len > 0 && find == 0 && sign)
	{
		len--;
		if (cmd[len] == sign[0])
		{
			if (cmd[len + 1] == sign[1] || ft_strlen(sign) == 1)
			{
				node = ft_new_node(sign, NULL, NULL);
				node->left = ft_new_node(ft_strndup(cmd, len), NULL, NULL);
				node->right = ft_new_node(ft_strdup(cmd + len + \
					ft_strlen(sign)), NULL, NULL);
				find = 1;
			}
		}
	}
	return (node);
}

t_node	*ft_search_in_left(t_node *node, char *cmd)
{
	t_node	*current;
	char	*tmp;

	node = ft_strsplit_to_node(cmd, ft_get_last_sign(cmd));
	current = node;
	while (ft_str_with_sign(current->left->cmd))
	{
		tmp = ft_strdup(current->left->cmd);
		if (current->left)
		{
			free(current->left->cmd);
			free(current->left);
		}
		current->left = ft_strsplit_to_node(tmp, ft_get_last_sign(tmp));
		current = current->left;
		if (tmp)
			free(tmp);
	}
	return (node);
}

t_node	*ft_to_tree(char *cmd)
{
	t_node	*node;

	node = NULL;
	if (ft_str_with_sign(cmd))
		node = ft_search_in_left(node, cmd);
	else
		node = ft_new_node(ft_strdup(cmd), NULL, NULL);
	return (node);
}

int		ft_checktree(t_node *tree)
{
	t_node	*current;
	int		error;

	error = 0;
	current = tree;
	while (current && error == 0)
	{
		if (ft_strcmp(current->cmd, ">") == 0 \
			|| ft_strcmp(current->cmd, "<") == 0 \
			|| ft_strcmp(current->cmd, ">>") == 0)
		{
			if (current->right)
			{
				if (ft_strlen(current->right->cmd) > 32)
				{
					ft_puterror("42sh: ");
					ft_puterror(ft_strtrim(current->right->cmd));
					ft_puterror(": Filename to long\n");
					error = 1;
				}
			}
		}
		current = current->left;
	}
	return (error);
}

void	ft_parser(char *cmd)
{
	char	**tab_cmd;
	t_node	*tree;
	int		fd;
	int		i;

	i = -1;
	if (cmd)
	{
		tab_cmd = ft_strsplit(cmd, ';');
		while (tab_cmd[++i])
		{
			tree = ft_to_tree(tab_cmd[i]);
			if (!ft_checktree(tree) && tree)
			{
				tree->position = 1;
				if ((fd = ft_exec_tree(tree, shell->fdy)) != -1)
					ft_printcmd(fd);
			}
			ft_freetree(tree);
			if (tree->cmd)
				free(tree->cmd);
			if (tree)
				free(tree);
		}
		ft_freetable(tab_cmd);
	}
}