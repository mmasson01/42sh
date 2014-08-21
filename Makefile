#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmery <jmery@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/26 15:51:24 by jmery             #+#    #+#              #
#    Updated: 2014/02/26 15:51:24 by jmery            ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = 42sh

ECHO = echo

ENV = env

FLAG = -g -Wall -Wextra -Werror

SRCS = 	srcs/main.c \
		srcs/tools/ft_atoi.c \
		srcs/tools/ft_putnbr.c \
		srcs/tools/ft_strdup.c \
		srcs/tools/ft_strsplit.c \
		srcs/tools/ft_freetable.c \
		srcs/tools/ft_putstr.c \
		srcs/tools/ft_strlen.c \
		srcs/tools/ft_strtrim.c \
		srcs/tools/ft_isdigit.c \
		srcs/tools/ft_putstr_fd.c \
		srcs/tools/ft_strnbchr.c \
		srcs/tools/ft_tablecpy.c \
		srcs/tools/ft_isspace.c \
		srcs/tools/ft_putstr_without.c \
		srcs/tools/ft_strncat.c \
		srcs/tools/ft_tablencpy.c \
		srcs/tools/ft_printtable.c \
		srcs/tools/ft_stock_table.c \
		srcs/tools/ft_strncmp.c \
		srcs/tools/ft_tablerange.c \
		srcs/tools/ft_strcmp.c \
		srcs/tools/ft_strncpy.c \
		srcs/tools/ft_putchar_fd.c \
		srcs/tools/ft_strcpy.c \
		srcs/tools/ft_strndup.c \
		srcs/tools/ft_printf.c \
		srcs/tools/ft_printf_format.c \
		srcs/tools/ft_abs.c \
		srcs/tools/ft_min.c \
		srcs/tools/ft_bzero.c \
		srcs/tools/ft_isprintable.c \
		srcs/tools/ft_isascii.c \
		srcs/42sh/fork.c \
		srcs/42sh/error.c \
		srcs/42sh/env.c \
		srcs/42sh/init_struct.c \
		srcs/42sh/change_directory.c \
		srcs/42sh/builtins.c \
		srcs/42sh/tab_to_space.c \
		srcs/42sh/echo.c \
		srcs/42sh/is_empty_line.c \
		srcs/42sh/getcmd.c \
		srcs/42sh/read_cmd.c \
		srcs/42sh/parser.c \
		srcs/42sh/exec.c \
		srcs/42sh/exec2.c \
		srcs/42sh/nodes.c \
		srcs/42sh/writefile.c \
		srcs/42sh/signs.c \
		srcs/42sh/pipe.c \
		srcs/42sh/ft_env.c \
		srcs/42sh/term.c \
		srcs/42sh/term2.c \
		srcs/42sh/historique.c \
		srcs/42sh/histotools.c \
		srcs/42sh/bufplay.c \
		srcs/42sh/bufplaytools.c \
		srcs/42sh/keyevent.c \
		srcs/42sh/keyevent2.c \
		srcs/42sh/signaux.c \
		srcs/42sh/prompt.c \
		srcs/42sh/read.c

OBJS = $(SRCS:.c=.o)


all: $(NAME) run

$(NAME):$(OBJS)
	gcc $(FLAG) -o $(NAME) $(OBJS) -ltermcap

%.o:%.c
	gcc $(FLAG) -o $@ -c $< -I includes

run:
	@echo "\n"
	./$(NAME)

clean:
	rm -rf $(OBJS)

fclean:clean
	rm -rf $(NAME)

re: fclean all
