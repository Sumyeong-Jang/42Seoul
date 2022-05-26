#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int main()
{
	char	c = 'a';
	char	C = 'A';
	char	*str = "hello";
	int		n = 42;
	void	*p = &n;

	ft_printf("%c\n", c);
	ft_printf("%s\n", str);
	ft_printf("%p\n", p);
	ft_printf("%d\n", n);
	ft_printf("%i\n", n);
	ft_printf("%u\n", n);
	ft_printf("%x\n", c);
	ft_printf("%X\n", C);
	ft_printf("%%\n");
}
