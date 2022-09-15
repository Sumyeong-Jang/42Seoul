#ifndef EXECUTOR_H
# define EXECUTOR_H

# define READ 0
# define WRITE 1

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdio.h>
# include <readline/readline.h>

# include "struct.h"
# include "utiles.h"
# include "builtin.h"

void	executor(t_cmd *cmd, t_env *env_head, char *envp[]);
void	redirect(t_cmd *cmd);
int		heredoc(t_cmd *cmd);
void	close_unused_fd(t_cmd *cmd, pid_t pid);
int		check_valid_syntax(t_cmd *cmd_head);
void	wait_child(void);
int		is_need_fork(t_cmd *cmd);
void	restore_redirection_char(t_cmd *cmd);

char	*get_cmd_path(t_cmd *cmd, t_env *env_head);

int		io_file_open(t_cmd *cmd, t_env *env_head);
void	trim_cmd_argv(t_cmd *cmd, const char *set, int direction);

char	*get_tmp_file_name(void);
void	delete_tmp_file(void);
int		init_heredoc(t_cmd *cmd);
void	clear_cmd(t_cmd *cmd_head);

void		*ft_free(void *ptr);
t_cmd		*ft_list_init(void);
void		ft_free_list(t_cmd *cmd);

#endif