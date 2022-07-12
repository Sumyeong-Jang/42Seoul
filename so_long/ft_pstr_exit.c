#include "../include/libft.h"

void	ft_pstr_exit(char *s)
{
	ft_putendl_fd(s, STDERR_FILENO);
	exit(EXIT_FAILURE);
}