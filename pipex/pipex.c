/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjang <sumjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 15:25:33 by sumjang           #+#    #+#             */
/*   Updated: 2022/06/27 15:25:35 by sumjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int		pipex(t_arg *arg, char **envp);
void	redirect_out(char *file_path);
void	redirect_in(char *file_path);

int	pipex(t_arg *arg, char **envp)
{
	if (arg->pid > 0)
	{
		close(arg->pipe_fd[1]);
		if (dup2(arg->pipe_fd[0], STDIN_FILENO) == -1)
			ft_exit("dup2 fail", 1);
		redirect_out(arg->outfile);
		close(arg->pipe_fd[0]);
		waitpid(arg->pid, NULL, WNOHANG);
		if (execve(arg->cmd2, arg->cmd_arg2, envp) == -1)
			ft_exit("execve fail", arg->exit_code);
	}
	else if (arg->pid == 0)
	{
		close(arg->pipe_fd[0]);
		redirect_in(arg->infile);
		if (dup2(arg->pipe_fd[1], STDOUT_FILENO) == -1)
			ft_exit("dup2 fail", 1);
		close(arg->pipe_fd[1]);
		if (execve(arg->cmd1, arg->cmd_arg1, envp) == -1)
			ft_exit("execve fail", arg->exit_code);
	}
	return (-1);
}

void	redirect_out(char *file_path)
{
	int	fd;

	fd = open(file_path, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		perror(file_path);
		ft_exit(NULL, 1);
	}
	if (dup2(fd, STDOUT_FILENO) == -1)
		ft_exit("dup2 fail", 1);
	close(fd);
}

void	redirect_in(char *file_path)
{
	int	fd;

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
	{
		perror(file_path);
		ft_exit(NULL, 1);
	}
	if (dup2(fd, STDIN_FILENO) == -1)
		ft_exit("dup2 fail", 1);
	close(fd);
}
