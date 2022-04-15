/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 09:55:57 by younjkim          #+#    #+#             */
/*   Updated: 2022/01/20 16:13:26 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check(char format)
{
	char	*param;
	int		i;

	i = 0;
	param = "cspdiuxX%";
	while (param[i])
	{
		if (format == param[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_task(char format, va_list *args)
{
	int		len;

	len = 0;
	if (format == 's')
		len += ft_putstr(va_arg(*args, char *));
	if (format == 'd' || format == 'i')
		len += ft_putnbr(va_arg(*args, int));
	if (format == 'c')
		len += ft_putchar(va_arg(*args, int));
	if (format == 'x')
		len += ft_hexdecimal(va_arg(*args, int));
	if (format == 'X')
		len += ft_hedecimal(va_arg(*args, int));
	if (format == 'u')
		len += ft_unsigned(va_arg(*args, int));
	if (format == 'p')
		len += ft_pointer(va_arg(*args, void *));
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		len;

	count = 0;
	len = 0;
	va_start (args, format);
	while (format[count])
	{
		if (format[count] == '%' && ft_check(format[count + 1]) == 1)
		{
			if (format[count + 1] == '%')
				len += ft_putchar('%');
			else
				len += ft_task(format[count + 1], &args);
			count++;
		}
		else
			len += ft_putchar(format[count]);
		count++;
	}
	va_end (args);
	return (len);
}
