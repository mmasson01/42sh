/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   historique.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/03 16:43:47 by jmery             #+#    #+#             */
/*   Updated: 2014/02/04 19:32:33 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

static int	bl;
t_hist		*hist;

void	ft_inithistorique(void)
{
	hist = (t_hist*)malloc(sizeof(*hist));
	if (hist)
	{
		hist->current = 0;
		hist->histo = (char **)malloc(sizeof(hist->histo));
		if (hist->histo)
			hist->histo[0] = NULL;
	}
}

size_t	ft_getpreviouscmd(char buf[])
{
	if (!hist->histo)
		return (0);
	if (!bl)
		bl = 0;
	if (hist->current < ft_tablerange(hist->histo))
			hist->current++;
	if (hist->histo[hist->current])
	{
		bl = 0;
		ft_strtobuf(buf, hist->histo[hist->current]);
		return (ft_strlen(hist->histo[hist->current]));
	}
	else
	{
		ft_strtobuf(buf, "");
		if (bl == 1)
			tputs(tgetstr("bl", NULL), 1, ft_putchar);
		bl = 1;
		return (1);
	}
	return (1);
}

size_t	ft_getnextcmd(char buf[])
{
	if (!bl)
		bl = 0;
	if (!hist->histo)
		return (0);
	if (hist->current > 0)
		hist->current--;
	if (hist->current != 0)
		bl = 0;
	if (hist->histo[hist->current])
	{
		if (bl == 1)
			tputs(tgetstr("bl", NULL), 1, ft_putchar);
		bl = 0;
		if (hist->current == 0)
			bl = 1;
		ft_strtobuf(buf, hist->histo[hist->current]);
		return (ft_strlen(hist->histo[hist->current]));
	}
	tputs(tgetstr("bl", NULL), 1, ft_putchar);
	return (1);
}

void	ft_addtohistorique(char cmd[], unsigned int size)
{
	char	*archive;

	archive = NULL;
	if (!hist)
		ft_inithistorique();
	if (ft_isarchivable(cmd, size))
	{
		archive = (char *)malloc(sizeof(*archive) * (size + 1));
		if (archive)
		{
			ft_strncpy(archive, cmd, size);
			hist->histo = ft_stock_table(archive, hist->histo);
			hist->current = ft_tablerange(hist->histo);
		}
	}
}

int		ft_printhistorique(void)
{
	int		i;

	i = 0;
	if (hist->histo)
	{
		while (hist->histo[i])
		{
			ft_putstr(hist->histo[i]);
			i++;
		}
	}
	return (0);
}