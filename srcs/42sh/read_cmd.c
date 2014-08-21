/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmery <jmery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/19 16:14:40 by jmery             #+#    #+#             */
/*   Updated: 2014/03/19 16:14:41 by jmery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

char	*ft_stockcmd(char buf[], int ret)
{
	char	*cmd;

	if (ret == 0 || buf[ret - 1] != '\n')
	{
		ft_putchar('\n');
		ret++;
	}
	cmd = (char *)malloc(sizeof(*cmd) * ret);
	if (cmd)
		ft_strncpy(cmd, buf, ret - 1);
	ft_tab_to_space(cmd);
	return (cmd);
}
