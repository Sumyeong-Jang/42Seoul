#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int main()
{
	char	c = 't';
	char	*str = NULL;
	int		n = -42;
	int		nh = -0x2a;
	void	*p = &str;

	ft_printf("%\n", n);
	ft_printf("%s\n", str);
	ft_printf("%p\n", p);
	p = &n;
	str = "hello";
	ft_printf("%sq\n", str);
	ft_printf("%g\n", n);
	ft_printf("%c\n", c);
	ft_printf("%s\n", str);
	ft_printf("%p\n", p);
	ft_printf("%d\n", n);
	ft_printf("%i\n", nh);
	ft_printf("%u\n", -n);
	ft_printf("%x\n", n);
	ft_printf("%X\n", n);
	ft_printf("%%\n");
}
