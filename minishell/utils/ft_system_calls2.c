#include "../include/utiles.h"

int	    ft_write(int fd, const void *buf, size_t byte);
void	*ft_malloc(size_t size, size_t n);
void	ft_execve(const char *file, char *const *argv, char *const *envp);
char	*ft_getcwd(char *buf, size_t size);

int	ft_write(int fd, const void *buf, size_t byte)
{
	int	ret;

	ret = write(fd, buf, byte);
	if (ret == -1)
		exit_with_err("write()", strerror(errno), EXIT_FAILURE);
	return (ret);
}

void	*ft_malloc(size_t size, size_t n)
{
	void	*ret;

	ret = malloc(size * n);
	if (ret == NULL)
		exit_with_err("malloc()", strerror(errno), EXIT_FAILURE);
	return (ret);
}

void	ft_execve(const char *file, char *const *argv, char *const *envp)
{
	if (execve(file, argv, envp) == -1)
		exit_with_err("execve()", strerror(errno), 126);
	return ;
}

char	*ft_getcwd(char *buf, size_t size)
{
	char	*pwd;

	pwd = getcwd(buf, size);
	if (pwd == NULL)
		exit_with_err("getcwd()", strerror(errno), EXIT_FAILURE);
	return (pwd);
}