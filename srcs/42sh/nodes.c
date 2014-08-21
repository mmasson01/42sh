/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmery <jmery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 13:01:48 by jmery             #+#    #+#             */
/*   Updated: 2014/03/13 13:01:48 by jmery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

void		ft_freetree(t_node *tree)
{
	if (tree == NULL)
		return ;
	ft_freetree(tree->left);
	ft_freetree(tree->right);
	if (tree->left)
	{
		free(tree->left->cmd);
		free(tree->left);
	}
	if (tree->right)
	{
		free(tree->right->cmd);
		free(tree->right);
	}
}

t_node	*ft_new_node(char *cmd, t_node *left, t_node *right)
{
	t_node		*node;

	node = (t_node*)malloc(sizeof(*node));
	if (node)
	{
		node->cmd = cmd;
		node->position = -1;
		node->left = left;
		node->right = right;
	}
	return (node);
}
