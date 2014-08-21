/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasson <mmasson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/21 12:36:36 by mmasson           #+#    #+#             */
/*   Updated: 2014/03/21 12:36:37 by mmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh_tools.h"

int		ft_count(int n)
{
	int		len;

	len = 0;
	while (n >= 10)
	{
		n = n / 10;
		len++;
	}
	return (len + 1);
}

int		ft_check_cent(const char *format, int i, va_list ap)
{
	int		len;
	char	*p;
	int		n;

	p = NULL;
	n = 0;
	len = 0;
	if (format[i] == 's')
		len = ft_format_s(ap, p);
	if (format[i] == 'd' || format[i] == 'i')
		len = ft_format_d(ap, n);
	if (format[i] == 'c')
		len = ft_format_c(ap);
	if (format[i] == '%')
		len = ft_format_cent();
	return (len);
}

int		ft_printf(const char *format, ...)
{
	va_list ap;
	va_start(ap, format);
	int		i;
	size_t	len;

	i = 0;
	len = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			len = len + ft_check_cent(format, i, ap);
		}
		else
		{
			ft_putchar(format[i]);
			len++;
		}
		i++;
	}
	va_end(ap);
	return (len);
}
