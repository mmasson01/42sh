/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signaux.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmery <jmery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 17:59:50 by jmery             #+#    #+#             */
/*   Updated: 2014/03/22 17:59:51 by jmery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

void	ft_initsignal(void)
{
	signal(SIGQUIT, ft_sighandler);
	signal(SIGCONT, ft_sighandler);
	signal(SIGINT, ft_sighandler);
}

void	ft_sighandler(int sig)
{
	char	buffer[2048];

	if (sig == SIGCONT)
	{
		aff_prompt();
		if (tgetent(buffer, getenv("TERM")) < 1)
			exit(EXIT_FAILURE);
		tcgetattr(0, &shell->term);
		ft_initterm(shell->term);
	}
	if (sig == SIGQUIT)
	{
		ft_putchar('\n');
		ft_endterm(shell->term);
		aff_exit_value();
		ft_free_struct();
		exit(shell->exit_value);
	}
	if (sig == SIGINT)
		data->exit_cmd = 1;
}