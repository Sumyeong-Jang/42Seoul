#include "../include/libft.h"

void	ft_perror_exit(char *s)
{
	perror(s);
	exit(EXIT_FAILURE);
}