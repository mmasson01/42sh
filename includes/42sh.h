/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   42sh.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasson <mmasson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/26 15:52:15 by jmery             #+#    #+#             */
/*   Updated: 2014/03/23 01:36:07 by mmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __42SH_H__
# define __42SH_H__

# define BUF_SIZE 1024

# define NOW_QUIT 1
# define STAY 0
# define POSITION_DEFAULT "PARIS"

# define BLANC "29"
# define ROUGE "31"
# define VERT "32"
# define JAUNE "33"
# define BLEU "34"
# define TURQUOISE "36"
# define couleur(param) ft_printf("\e[1;%sm",param)

# define KEY_UP 4283163
# define KEY_DOWN 4348699
# define KEY_LEFT 4479771
# define KEY_RIGHT 4414235
# define KEY_DEL 127
# define KEY_ENTRY 10
# define CTRL_D 4
# define KEY_HOME 4741915
# define KEY_END 4610843
# define KEY_SH_LEFT 17458
# define KEY_SH_RIGHT 17202
# define KEY_SH_UP 16690
# define KEY_CT_LEFT 17462
# define KEY_CT_RIGHT 17206
# define KEY_SH_ERROR 993090331

# include "42sh_tools.h"

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <time.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <termios.h>
# include <termcap.h>
# include <term.h>

typedef struct	s_node
{
	char 			*cmd;
	int				position;
	struct s_node	*left;
	struct s_node	*right;
}				t_node;

typedef struct	s_echo
{
	char 			*word;
	struct s_echo 	*next;
}				t_echo;

typedef struct	s_shell
{
	char			**g_myenv;
	struct termios 	term;
	int				fdy;
	int				exit;
	int				exit_value;
}				t_shell;

typedef struct	s_cmd
{
	unsigned int	i;
	unsigned int	len;
	unsigned int	exit_cmd;
}				t_cmd;

typedef struct	s_hist
{
	int		current;
	char	**histo;
}				t_hist;

t_shell			*shell;
extern t_cmd	*data;
extern t_hist 	*hist;

/*
** prompt.c
*/
void	aff_prompt(void);

/*
** 42sh_parser.c
*/
void	ft_parser(char *cmd);
char	*ft_new_cmd_line(void);

/*
** 42sh_echo_list.c
*/
t_echo	*add_to_end_list(t_echo *echo, char *word);
void	aff_struct_echo(t_echo *echo);
void	free_struct_echo(t_echo *echo);


/*
** 42sh_is_empty_line.c
*/
int		ft_is_empty_line(char *cmd);
void	aff_exit_value(void);

/*
** 42sh_echo.c
*/
void	ft_echo(char **arg);

/*
** 42sh_tab_to_space.c
*/
void	ft_tab_to_space(char *str);

/*
** 42sh_builtins.c
*/
char	**ft_unsetmyenv(char *var, char **env);
void	ft_setenv(char *var, char *value_to_set);
char	**ft_setmyenv(char *var, char *value_to_set, char **env);
char	*ft_create_var(char *var, char *value_to_set);
char	**ft_stock_table(char *tmp, char **table);

/*
** 42sh_change_directory.c
*/
void	ft_change_directory(char *path);
char	*ft_get_home(void);
char	*ft_get_return(void);

/*
** 42sh_init_struct.c
*/
t_shell	*init_shell_struct(char **env);
void	ft_free_struct(void);

/*
** 42sh_fork.c
*/
int		ft_execcmd(char **cmd, char **env);
void	ft_exeinenv(char **arg, char **env);
char	*ft_topath(char *cmd, char *path);

/*
** 42sh_env.c
*/
char	**ft_getenv(char **env);
int		ft_iskey(char *s1, char *key);
char	*ft_getkey(char *key);
int		ft_isakey(char *key);

/*
** 42sh_error.c
*/
int		ft_puterror(char *str);

/*
** 42sh_getcmd.c
*/
int		ft_getcmd(char *cmd);
int		ft_check_isnot_builtin(char *cmd);

/*
** 42sh_nodes.c
*/
void	ft_freetree(t_node *tree);
t_node	*ft_new_node(char *cmd, t_node *left, t_node *right);

/*
** 42sh_exec.c
*/
int		ft_exec_tree(t_node *tree, int fd_entry);

/*
** 42sh_exec2.c
*/
int		ft_exec_tree6(t_node *tree, int fd_entry);

/*
** 42sh_writefile.c
*/
int		ft_writefile(char *name, int fdf);
int		ft_appendfile(char *name, int fdf);
int		ft_open_file(char *name);
void	ft_close_file(int fd);

/*
** 42sh_parser.c
*/
t_node	*ft_strsplit_to_node(char *cmd, char *sign);

/*
** 42sh_signs.c
*/
int		ft_is_sign(char c);
int		ft_str_with_sign(char *str);
char	*ft_get_last_sign(char *str);

/*
** 42sh_pipe.c
*/
void	ft_pipecmd(char *cmd, int fd_entry, int fd_exit);
int		ft_pipeentry(char *cmd, int fd_entry);
int		ft_printcmd(int fd);

/*
** 42sh_read_cmd.c
*/
char	*ft_stockcmd(char buf[], int ret);

/*
** ft_env.c
*/
void  ft_env(char **arg, char **env);

/*
** term.c
*/
void	ft_initterm(struct termios term);
void	ft_endterm(struct termios term);
size_t	my_read(char buf[], size_t size);
t_cmd	*ft_initdata(char buf[]);

/*
** term2.c
*/
size_t	ft_movecursor(unsigned int i, unsigned int j, t_cmd *data);
void	ft_checkkey(char read_char[], char buf[], t_cmd *data);
int		ft_isonekey(char read_char[]);

/*
** historique.c
*/
void	ft_inithistorique(void);
size_t	ft_getpreviouscmd(char buf[]);
size_t	ft_getnextcmd(char buf[]);
void	ft_addtohistorique(char cmd[], unsigned int size);
int		ft_printhistorique(void);

/*
** histotools.c
*/
int		ft_isarchivable(char buf[], unsigned int size);
void	ft_printhistory(void);

/*
** bufplay.c
*/
void	ft_strtobuf(char buf[], char *str);
size_t	ft_makebuf(char c, char buf[], t_cmd *data);
void	ft_printbuf(char buf[], unsigned int i, unsigned int len);
void	ft_insertinbuf(char buf[], char c, unsigned int i, unsigned int len);
void	ft_delinbuf(char buf[], unsigned int i, unsigned int len);

/*
** bufplaytools.c
*/
void	ft_delstrinbuf(char buf[], unsigned int i, unsigned int len, t_cmd *d);
void	ft_cleanbuf(char buf[], unsigned int len);
void	ft_printinvbuf(char buf[], t_cmd *data, unsigned int i, unsigned int j);
size_t	ft_bufncpy(char buf1[], char buf2[], unsigned int i, unsigned int j);
size_t	ft_bufncat(char buf1[], char buf2[], unsigned int l1, unsigned int l2);

/*
** keyevent.c
*/
void	ft_eventkeydel(char buf[], t_cmd *data);
void	ft_eventkeyup(char buf[], t_cmd *data);
void	ft_eventkeydown(char buf[], t_cmd *data);
void	ft_eventshiftright(char buf[], t_cmd*data);
void	ft_eventshiftleft(char buf[], t_cmd*data);

/*
** keyevent.2c
*/
void	ft_eventcpy(char buf[], t_cmd *data);
size_t	ft_toeventcut(char buf[], t_cmd *data);
void	ft_eventcut(char buf[], t_cmd *data);
void	ft_eventpaste(char buf[], t_cmd *data);

int		ft_putchar(int c);

/*
** signaux.c
*/
void	ft_initsignal(void);
void	ft_sighandler(int sig);

/*
** read.c
*/
int		ft_tofileread(char buf[], size_t size);
int		ft_read(int fd, char buf[], int size);
int		char_read(int fd, char read_char[], size_t len);

#endif
