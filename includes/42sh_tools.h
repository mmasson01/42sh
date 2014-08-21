/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   42sh_tools.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 16:24:14 by mmasson           #+#    #+#             */
/*   Updated: 2014/03/18 12:12:40 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __42SH_TOOLS_H__
# define __42SH_TOOLS_H__

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "42sh.h"

/*
** ft_printf.c
*/
int		ft_printf(const char *format, ...);
int		ft_count(int n);

/*
** ft_printf_format.c
*/
int	ft_format_s(va_list ap, char *p);
int	ft_format_d(va_list ap, int n);
int	ft_format_c(va_list ap);
int	ft_format_cent(void);

int		ft_atoi(const char *str);
void	ft_freetable(char **table);
int		ft_isdigit(int c);
int		ft_isspace(int c);
void	ft_printtable(char **table);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr(char *str);
void	ft_putstr_fd(char *str, int fd);
void	ft_putstr_without(char *str, char c);
void	ft_putnbr(int nbr);
char	**ft_stock_table(char *tmp, char **table);
int		ft_strcmp(char *s1, char *s2);
int		ft_strncmp(char *s1, char *s2, size_t n);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strncpy(char *dest, char *src, size_t n);
char	*ft_strdup(char *str);
char	*ft_strndup(char *src, int n);
char	*ft_strncat(char *s1, char *s2, size_t n);
int		ft_strnbchr(char *str, char c);
size_t	ft_strlen(char *str);
char	**ft_strsplit(char *str, char c);
char	*ft_strtrim(char *s);
void	ft_tablecpy(char **new_table, char **old_table);
char	**ft_tablencpy(char **tabledest, char **tablesrc, int n);
int		ft_tablerange(char **table);
void	ft_bzero(void *s, size_t n);
int		ft_isprintable(int c);
int		ft_isascii(int c);
size_t	ft_min(unsigned int i, unsigned int j);
size_t	ft_abs(unsigned int i, unsigned int j);

#endif
