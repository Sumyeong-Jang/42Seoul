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

int		pipex(t_arg *arg, int *fd, char **envp, pid_t *pid);
void	redirect_out(char *file_path);
void	redirect_in(char *file_path);

int	pipex(t_arg *arg, int *fd, char **envp, pid_t *pid)
{
	if (*pid > 0)
	{
		waitpid(*pid, NULL, WNOHANG);
		close(fd[0]);
		dup2(fd[1], 1);
		redirect_out(arg->outfile);
		if (execve(arg->cmd2, arg->cmd_arg2, envp) == -1)
			ft_exit("execve fail", 1);
	}
	else if (*pid == 0)
	{
		redirect_in(arg->infile);
		close(fd[0]);
		dup2(fd[1], 1);
		if (execve(arg->cmd1, arg->cmd_arg1, envp) == -1)
			ft_exit("execve fail", 1);
	}
	return (ERROR);
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
