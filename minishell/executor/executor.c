#include "../include/executor.h"

void	executor(t_cmd *cmd_head, t_env *env_head, char **envp);
static void	do_cmd(t_cmd *cmd, t_env *env_head, char **envp);
static void	do_fork_cmd(t_cmd *cmd, t_env *env_head, char **envp);
static int	execute_cmd(t_cmd *cmd, t_env *env_head, char **envp);
static int	os_builtins(t_cmd *cmd, t_env *env_head, char **envp);

void	executor(t_cmd_line_list *cmd_line_list)
{
	if (cmd_line_list->size == 1)
		exe_without_pipe(cmd_line_list->cmd_heads[0]);
	else
		exe_with_pipe(cmd_line_list);
}

static void	exec_cmd(t_cmd_node *node)
{
	pid_t		pid;
	int			status;

	if ((node->type == BUILTIN) && (has_redir_in(node) \
	== NULL) && (has_redir_out(node) == NULL))
		exe_builtin_single(node);
	else
	{
		pid = fork();
		if (pid < -1)
			exit(1);
		if (pid == 0)
		{
			exec_single_cmd_without_pipe(node);
			exit(1);
		}
		else
		{
			waitpid(pid, &status, 0);
			if (!WIFSIGNALED(status))
				g_state.exit_status = status / 256;
		}
	}
}







void	executor(t_cmd *cmd_head, t_env *env_head, char **envp)
{
	t_cmd	*cmd_cur;

	cmd_cur = cmd_head;
	if (check_valid_syntax(cmd_head) == -1)
		return (clear_cmd(cmd_head));
	if (init_heredoc(cmd_cur) == -1)
		return (clear_cmd(cmd_head));
	while (cmd_cur)
	{
		if (io_file_open(cmd_cur, env_head) == -1)
		{
			cmd_cur = cmd_cur->next;
			continue ;
		}
		if (is_need_fork(cmd_cur) == true)
			do_fork_cmd(cmd_cur, env_head, envp);
		else
			do_cmd(cmd_cur, env_head, envp);
		cmd_cur = cmd_cur->next;
	}
	wait_child();
	set_signal(SHE, SHE);
	return (clear_cmd(cmd_head));
}

static void	do_cmd(t_cmd *cmd, t_env *env_head, char **envp)
{
	g_exit_code = execute_cmd(cmd, env_head, envp);
	close_unused_fd(cmd, 1);
}

static void	do_fork_cmd(t_cmd *cmd, t_env *env_head, char **envp)
{
	pid_t	pid;
	int		exit_code;

	set_signal(DFL, DFL);
	pid = ft_fork();
	if (pid == 0)
	{
		redirect(cmd);
		close_unused_fd(cmd, pid);
		exit_code = execute_cmd(cmd, env_head, envp);
		exit (exit_code);
	}
	else
	{
		close_unused_fd(cmd, pid);
		set_signal(IGN, IGN);
	}
	return ;
}

static int	execute_cmd(t_cmd *cmd, t_env *env_head, char **envp)
{
	restore_redirection_char(cmd);
	if (!ft_strcmp(cmd->argv[0], "echo"))
		return (ft_echo(cmd->argc, cmd->argv));
	if (!ft_strcmp(cmd->argv[0], "cd"))
		return (ft_cd(cmd->argv[1], env_head));
	if (!ft_strcmp(cmd->argv[0], "pwd"))
		return (ft_pwd());
	if (!ft_strcmp(cmd->argv[0], "export"))
		return (ft_export(cmd->argc, cmd->argv, env_head));
	if (!ft_strcmp(cmd->argv[0], "unset"))
		return (ft_unset(cmd->argc, cmd->argv, env_head));
	if (!ft_strcmp(cmd->argv[0], "env"))
		return (ft_env(env_head));
	if (!ft_strcmp(cmd->argv[0], "exit"))
		return (ft_exit(cmd));
	return (os_builtins(cmd, env_head, envp));
}

static int	os_builtins(t_cmd *cmd, t_env *env_head, char **envp)
{
	char	*env_path;

	env_path = ft_getenv(env_head, "PATH");
	if (env_path == NULL && cmd->cmd_path == NULL)
	{
		print_err3(cmd->argv[0], NULL, "No such file or directory");
		return (127);
	}
	if (env_path != NULL && ft_strlen(env_path) == 0 && cmd->cmd_path == NULL)
	{
		print_err3(cmd->argv[0], NULL, "No such file or directory");
		return (127);
	}
	if (cmd->cmd_path == NULL)
	{
		print_err3(cmd->argv[0], NULL, "command not found");
		return (127);
	}
	ft_execve(cmd->cmd_path, cmd->argv, envp);
	return (EXIT_FAILURE);
}

void	close_unused_fd(t_cmd *cmd, pid_t pid)
{
	if (pid == 0)
	{
		if (cmd->fd[READ] != -2)
			cmd->fd[READ] = ft_close(cmd->fd[READ]);
	}
	else
	{
		if (cmd->fd[WRITE] != -2)
			cmd->fd[WRITE] = ft_close(cmd->fd[WRITE]);
	}
	return ;
}