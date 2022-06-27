/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjang <sumjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 13:49:43 by sumjang           #+#    #+#             */
/*   Updated: 2022/06/27 13:49:45 by sumjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int		arg_init(int argc, char **argv, char **envp, t_arg **arg);
char	**get_envp_path(char **envp);	// *envp[]
int		parse_argv(char **argv, t_arg *arg);
char	*get_argv_cmd(char **path, char *arg_cmd);

int	main(int argc, char **argv, char **envp)
{
	t_arg	*arg;
	int		fd[2];
	pid_t	pid;

	if (arg_init(argc, argv, envp, &arg) == ERROR)
		ft_exit(NULL, 1);
	if ((pipe(fd)) == ERROR)
		ft_exit("pipe error", 1);
	pid = fork();
	if (pipex(arg, fd, envp, &pid) == ERROR)
		ft_exit(NULL, 1);
	return (0);
}

int	arg_init(int argc, char **argv, char **envp, t_arg **arg)
{
	if (argc < 5)
		ft_exit("argument error", 1);
	(*arg) = (t_arg *)malloc(sizeof(t_arg));
	if ((*arg) == NULL)
		return (ERROR);
	(*arg)->infile = ft_strdup(argv[1]);
	if ((*arg)->infile == NULL)
		ft_exit("infile error", 1);
	(*arg)->outfile = ft_strdup(argv[argc - 1]);
	if ((*arg)->outfile == NULL)
		ft_exit("outfile error", 1);
	(*arg)->path = get_envp_path(envp);
	if ((parse_argv(argv, *arg)) == ERROR)
		return (ERROR);
	return (0);
}

char	**get_envp_path(char **envp)
{
	char	*path;

	while (*envp && ft_strncmp("PATH=", *envp, 5))
		envp++;
	if (*envp == NULL)
		ft_exit("PATH error", 127);
	printf("envp 출력\n%s\n", *envp);
	path = *envp + 5;
	return (ft_split(path, ':'));
}

int	parse_argv(char **argv, t_arg *arg)
{
	arg->cmd_arg1 = ft_split(argv[2], ' ');
	if (arg->cmd_arg1 == NULL)
		return (ERROR);
	arg->cmd_arg2 = ft_split(argv[3], ' ');
	if (arg->cmd_arg2 == NULL)
		return (ERROR);
	arg->cmd1 = get_argv_cmd(arg->path, arg->cmd_arg1[0]);
	arg->cmd2 = get_argv_cmd(arg->path, arg->cmd_arg2[0]);
	if (arg->cmd1 == NULL)
	{
		write(1, "zsh: command not found: ", 24);
		write(1, arg->cmd_arg1[0], (ft_strlen(arg->cmd_arg1[0])));
		write(1, "\n", 1);
	}
	if (arg->cmd2 == NULL)
	{
		write(1, "zsh: command not found: ", 24);
		write(1, arg->cmd_arg2[0], (ft_strlen(arg->cmd_arg2[0])));
		write(1, "\n", 1);
	}
	return (0);
}

char	*get_argv_cmd(char **path, char *arg_cmd)
{
	int		i;
	int		fd;
	char	*path_cmd;
	char	*tmp;

	fd = access(arg_cmd, X_OK);
	if (fd != -1)
		return (arg_cmd);
	path_cmd = ft_strjoin("/", arg_cmd);
	i = 0;
	while (path[i])
	{
		tmp = ft_strjoin(path[i], path_cmd);
		fd = access(tmp, X_OK);
		if (fd != -1)
		{
			free(path_cmd);
			return (tmp);
		}
		close(fd);
		free(tmp);
		i++;
	}
	free(path_cmd);
	return (NULL);
}
