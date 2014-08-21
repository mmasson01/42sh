/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasson <mmasson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/23 01:34:07 by mmasson           #+#    #+#             */
/*   Updated: 2014/03/23 01:35:35 by mmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

void	aff_day_of_week(struct tm d)
{
	if (d.tm_wday == 1)
		ft_putstr("Monday");
	if (d.tm_wday == 2)
		ft_putstr("Tuesday");
	if (d.tm_wday == 3)
		ft_putstr("Wednesday");
	if (d.tm_wday == 4)
		ft_putstr("Thursday");
	if (d.tm_wday == 5)
		ft_putstr("Friday");
	if (d.tm_wday == 6)
		ft_putstr("Saturday");
	if (d.tm_wday == 0)
		ft_putstr("Sunday");
}

int		get_position(void)
{
	char	*position;

	position = ft_getkey("POSITION");
	if (!position)
		return (1);
	if (ft_strcmp(position, "PARIS") == 0)
		return (1);
	if (ft_strcmp(position, "NEW-YORK") == 0)
		return (-4);
	if (ft_strcmp(position, "LONDON") == 0)
		return (0);
	if (ft_strcmp(position, "SAN-FRANCISCO") == 0)
		return (-7);
	if (ft_strcmp(position, "SHANGHAI") == 0)
		return (8);
	if (ft_strcmp(position, "TOKYO") == 0)
		return (9);
	return (0);
}

void	aff_correct_value(struct tm d)
{
	if (d.tm_min < 10 && d.tm_hour < 10)
		ft_printf(" %d 0%d:0%d", d.tm_mday, (d.tm_hour + \
		(get_position()) + 24)%24, d.tm_min);
	if (d.tm_min < 10 && d.tm_hour > 10)
		ft_printf(" %d %d:0%d", d.tm_mday, (d.tm_hour + \
		(get_position()) + 24)%24, d.tm_min);
	if (d.tm_min > 10 && d.tm_hour < 10)
		ft_printf(" %d 0%d:%d", d.tm_mday, (d.tm_hour + \
		(get_position()) + 24)%24, d.tm_min);
	else
		ft_printf(" %d %d:%d", d.tm_mday, (d.tm_hour + \
		(get_position()) + 24)%24, d.tm_min);
}

void	aff_prompt(void)
{
	time_t		my_time;
	struct tm	d;

	time(&my_time);
	d = *gmtime(&my_time);
	ft_putstr("[");
	couleur(BLEU);
	ft_printf("42sh ");
	couleur(ROUGE);
	aff_day_of_week(d);
	aff_correct_value(d);
	couleur("0");
	ft_printf("]> ");
}