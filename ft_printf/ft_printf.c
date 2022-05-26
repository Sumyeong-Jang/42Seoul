/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjang <sumjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 14:25:40 by sumjang           #+#    #+#             */
/*   Updated: 2022/05/26 14:25:41 by sumjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print(char c, va_list ap, int *i);
int		ft_printf(const char *format, ...);

void	print(char c, va_list ap, int *i)
{
	if (c == '%')
		(*i) += ft_putchar('%');
	else if (c == 'd' || c == 'i')
		(*i) += ft_putnbr(va_arg(ap, int));
	else if (c == 'c')
		(*i) += ft_putchar(va_arg(ap, int));
	else if (c == 's')
		(*i) += ft_putstr(va_arg(ap, char *));
	else if (c == 'x')
		(*i) += ft_hexa(va_arg(ap, unsigned int), 1);
	else if (c == 'X')
		(*i) += ft_hexa(va_arg(ap, unsigned int), 0);
	else if (c == 'p')
	{
		ft_putstr("0x");
		(*i) += 2;
		(*i) += ft_hexa(va_arg(ap, unsigned long), 1);
	}
	else if (c == 'u')
		(*i) += ft_unsigned(va_arg(ap, unsigned int));
	else
		(*i) += ft_putchar(c);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	ap;

	i = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				return (i);
			print(*format, ap, &i);
		}
		else
		{
			ft_putchar(*format);
			i++;
		}
		format++;
	}
	va_end(ap);
	return (i);
}
