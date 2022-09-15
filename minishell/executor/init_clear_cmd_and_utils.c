#include "../include/executor.h"

void	clear_cmd(t_cmd *cmd_head);
int	init_heredoc(t_cmd *cmd);
int	is_need_fork(t_cmd *cmd);
void	restore_redirection_char(t_cmd *cmd);
void	wait_child(void);

void	clear_cmd(t_cmd *cmd_head)
{
	t_cmd	*cur;

	cur = cmd_head;
	while (cur)
	{
		if (cur->fd[READ] > 0)
			ft_close(cur->fd[READ]);
		if (cur->infile > 0)
			ft_close(cur->infile);
		if (cur->outfile > 0)
			ft_close(cur->outfile);
		if (cur->cmd_path != NULL)
			cur->cmd_path = ft_free(cur->cmd_path);
		cur = cur->next;
	}
	delete_tmp_file();
}

int	init_heredoc(t_cmd *cmd)
{
	t_cmd	*cur;

	cur = cmd;
	while (cur)
	{
		if (heredoc(cur) == -1)
			return (-1);
		cur = cur->next;
	}
	return (0);
}

int	is_need_fork(t_cmd *cmd)
{
	if (cmd->prev != NULL)
		return (1);
	if (cmd->is_pipe == true)
		return (1);
	if (cmd->infile != -2)
		return (1);
	if (cmd->outfile != -2)
		return (1);
	if (!ft_strcmp(cmd->argv[0], "cd"))
		return (0);
	if (!ft_strcmp(cmd->argv[0], "export"))
		return (0);
	if (!ft_strcmp(cmd->argv[0], "unset"))
		return (0);
	if (!ft_strcmp(cmd->argv[0], "exit"))
		return (0);
	return (1);
}

void	restore_redirection_char(t_cmd *cmd)
{
	int		i;
	int		j;

	i = 0;
	while (cmd->argv[i])
	{
		j = 0;
		while (cmd->argv[i][j])
		{
			if (cmd->argv[i][j] == -74)
				cmd->argv[i][j] = '<';
			else if (cmd->argv[i][j] == -76)
				cmd->argv[i][j] = '>';
			++j;
		}
		++i;
	}
}

void	wait_child(void)
{
	int		status;
	int		signo;

	while (wait(&status) != -1)
	{
		if (WIFSIGNALED(status))
		{
			signo = WTERMSIG(status);
			if (signo == SIGINT)
				ft_putstr_fd("^C\n", STDERR_FILENO);
			else if (signo == SIGQUIT)
				ft_putstr_fd("^\\Quit: 3\n", STDERR_FILENO);
			g_exit_code = 128 + signo;
		}
		else
			g_exit_code = WEXITSTATUS(status);
	}
}