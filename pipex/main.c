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
char	**get_envp_path(char **envp);
int		parse_argv(char **argv, t_arg **arg);
char	*get_argv_cmd(char **path, char *arg_cmd);

int	main(int argc, char **argv, char **envp)
{
	t_arg	*arg;

	arg->exit_code = arg_init(argc, argv, envp, &arg);
	if (arg->exit_code == -1)
		ft_exit(NULL, 1);
	if ((pipe(arg->pipe_fd)) == -1)
		ft_exit("pipe error", 1);
	arg->pid = fork();
	if (arg->pid == -1)
		ft_exit("fork error", 1);
	if (pipex(arg, envp) == -1)
		ft_exit(NULL, 1);
	return (0);
}

int	arg_init(int argc, char **argv, char **envp, t_arg **arg)
{
	if (argc != 5)
		ft_exit(NULL, 1);
	(*arg) = (t_arg *)malloc(sizeof(t_arg));
	if ((*arg) == NULL)
		return (-1);
	(*arg)->infile = ft_strdup(argv[1]);
	if ((*arg)->infile == NULL)
		ft_exit("infile", 1);
	(*arg)->outfile = ft_strdup(argv[argc - 1]);
	if ((*arg)->outfile == NULL)
		ft_exit("outfile", 1);
	(*arg)->path = get_envp_path(envp);
	if ((*arg)->path == NULL)
		ft_exit(NULL, 1);
	(*arg)->exit_code = parse_argv(argv, arg);
	if ((*arg)->exit_code == -1)
		return (-1);
	return ((*arg)->exit_code);
}

char	**get_envp_path(char **envp)
{
	char	*path;

	while (*envp && ft_strncmp("PATH=", *envp, 5))
		envp++;
	if (*envp == NULL)
		ft_exit("PATH error", 127);
	path = *envp + 5;
	return (ft_split(path, ':'));
}

int	parse_argv(char **argv, t_arg **arg)
{
	(*arg)->exit_code = 1;
	(*arg)->cmd_arg1 = ft_split(argv[2], ' ');
	if ((*arg)->cmd_arg1 == NULL)
		return (-1);
	(*arg)->cmd_arg2 = ft_split(argv[3], ' ');
	if ((*arg)->cmd_arg2 == NULL)
		return (-1);
	(*arg)->cmd1 = get_argv_cmd((*arg)->path, (*arg)->cmd_arg1[0]);
	(*arg)->cmd2 = get_argv_cmd((*arg)->path, (*arg)->cmd_arg2[0]);
	if ((*arg)->cmd1 == NULL || (*arg)->cmd2 == NULL)
	{
		(*arg)->exit_code = 127;
		perror("command not found");
	}
	return ((*arg)->exit_code);
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
