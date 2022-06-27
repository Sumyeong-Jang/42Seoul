/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjang <sumjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 13:49:55 by sumjang           #+#    #+#             */
/*   Updated: 2022/06/27 13:49:56 by sumjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

# define ERROR -1
# define FD_ENTRY 0
# define FD_EXIT 1

typedef struct s_arg
{
	char	*infile;
	char	*outfile;
	char	**path;
	char	*cmd1;
	char	**cmd_arg1;
	char	*cmd2;
	char	**cmd_arg2;
	int		pipe_fd[2];
	pid_t	pid;
}	t_arg;

int		pipex(t_arg *arg, int *fd, char **envp, pid_t *pid);
void	redirect_out(char *file_path);
void	redirect_in(char *file_path);

void	ft_exit(char *message, int isError);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlcat(char *dest, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize);

#endif
