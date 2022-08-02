#include "../include/push_swap.h"

long long	ft_atoll(const char *str);
static int	is_space(char c);
int	ft_isNum(const char *s);

long long	ft_atoll(const char *str)
{
	int			i;
	int			minus;
	long long	n;

	i = 0;
	while (is_space(str[i]))
		i++;
	minus = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			minus = -1;
		i++;
	}
    n = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		n = (n * 10) + (str[i] - '0');
        if (minus == -1 && n > -(unsigned long long)INT_MIN)
			ft_exit("Error\n");
		if (minus == 1 && n > (unsigned long long)INT_MAX)
			ft_exit("Error\n");
        /*
		if (minus * n > 2147483647 || minus * n < -2147483648)
			break ;
        */
		i++;
	}
    if (str[i] != '\0')
        ft_exit("Error\n");
	return (minus * n);
}

static int	is_space(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r')
		return (1);
	if (c == ' ')
		return (1);
	return (0);
}

int	ft_isNum(const char *s)
{
	int	i;

	i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	if (s[i] == '\0')
		return (0);
	while (s[i] != '\0')
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_numlen(long long n)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

int	get_top(t_list *list)
{
	return (list->top->index);
}