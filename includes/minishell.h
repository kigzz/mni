/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpouchep <bpouchep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 14:47:28 by bpouchep          #+#    #+#             */
/*   Updated: 2022/04/26 19:44:06 by dalitt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H

# define MINISHELL_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <sys/wait.h>
# include <dirent.h>
# include <sys/ioctl.h>
# include <errno.h>

# define READ_END 0
# define WRITE_END 1

extern int	g_status;

typedef struct s_prompt
{
	t_list	*cmds;
	char	**envp;
	int		error;
	int		is_heredoc;
}			t_prompt;

typedef struct s_mini
{
	char	**full_cmd;
	char	*full_path;
	int		infile;
	int		outfile;
}			t_mini;

enum	e_mini_error
{
	QUOTE = 1,
	NDIR = 2,
	NPERM = 3,
	NCMD = 6,
	DUPERR = 7,
	FORKERR = 8,
	PIPERR = 9,
	PIPENDERR = 10,
	IS_DIR = 11,
	NOT_DIR = 12
};

int		check_piperr(char **a);
void	ft_replace_tabs_returns(char *str);
int		builtin(t_prompt *prompt, t_list *cmd, int *is_exit, int n);
int		is_builtin(t_mini *n);
int		mini_cd(t_prompt *prompt);
void	cd_error(char **str[2]);
int		mini_pwd(void);
int		mini_echo(t_list *cmd);
int		mini_echo_check(char *str);
int		mini_export(t_prompt *prompt);
int		mini_export_check(char *str);
int		mini_unset(t_prompt *prompt);
int		mini_unset_check(char *str);
int		mini_exit(t_list *cmd, int *is_exit);
void	*check_args(char *out, t_prompt *p);
char	**ft_cmd_trim(char const *s, char *set);
char	**ft_cmd_split(char const *s, char *set);
char	*ft_strtrim_all(char const *s1, int squote, int dquote);
t_list	*fill_nodes(char **args, int i);
int		get_fd(int oldfd, char *path, int flags[2]);
void	get_fd_error(char *path, const int *flags);
t_mini	*get_outfile1(t_mini *node, char **args, int *i);
t_mini	*get_outfile2(t_mini *node, char **args, int *i);
t_mini	*get_infile1(t_mini *node, char **args, int *i);
t_mini	*get_infile2(t_mini *node, char **args, int *i);
void	*exec_cmd(t_prompt *prompt, t_list *cmd);
void	*check_to_fork(t_prompt *prompt, t_list *cmd, int fd[2]);
void	child_builtin(t_prompt *prompt, t_mini *n, int l, t_list *cmd);
void	get_cmd(t_prompt *prompt, t_list *start, char **split_path, char *path);
void	err_cmd(t_prompt *prompt, const t_mini *n);
char	*expand_vars(char *str, int i, int quotes[2], t_prompt *prompt);
int		get_here_doc(char *str[2], char *aux[2]);
void	*mini_perror(int err_type, char *param, int err);
char	*mini_getenv(char	*var, char **envp, int n);
char	**mini_setenv(char *var, char *value, char **envp, int n);
void	free_content(void *content);
void	handle_signal(int sig);
void	handle_sigint_exec(int sig);
void	handle_signal_heredoc(int sig);
void	handle_status(t_prompt *p, int is_exit, int i);
void	sig_and_exec(t_prompt *prompt, t_list *cmd);

#endif
