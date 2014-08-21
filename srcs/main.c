/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasson <mmasson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/26 16:13:26 by xyou              #+#    #+#             */
/*   Updated: 2014/03/23 01:36:30 by mmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

char	*ft_new_cmd_line(void)
{
	char*	cmd;
	char	buf[BUF_SIZE];
	int		ret;

	aff_prompt();
	if ((ret = my_read(buf, BUF_SIZE)) == -1)
		return (NULL);
	cmd = ft_stockcmd(buf, ret);
	if (cmd)
	{
		if (ft_is_empty_line(cmd) == EXIT_SUCCESS)
			return (cmd);
	}
	return (cmd);
}

int		main(int argc, char **argv, char **env)
{
	char	buffer[2048];
	char	*cmd;

	shell = NULL;
	ft_initsignal();
	if (tgetent(buffer, getenv("TERM")) < 1)
		return (-1);
	shell = init_shell_struct(env);
	ft_setenv("POSITION", POSITION_DEFAULT);
	if (argc)
		argv++;
	while (shell->exit != NOW_QUIT)
	{
		cmd = ft_new_cmd_line();
		ft_parser(cmd);
		if (cmd)
			free(cmd);
	}
	ft_endterm(shell->term);
	aff_exit_value();
	ft_free_struct();
	return (shell->exit_value);
}
