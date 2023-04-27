#include <unistd.h>
#include <stdarg.h>

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	len = 0;

	if (!str)
		str = "(null)";
	while (*str)
		len += write(1, str++, 1);
	return (len);
}

int	ft_putnbr(int nb)
{
	long long	n = nb;
	int			len = 0;

	if (n < 0)
	{
		len += write(1, "-", 1);
		n = -n;
	}
	if (n > 9)
	{
		len += ft_putnbr(n / 10);
		len += ft_putnbr(n % 10);
	}
	else
		len += ft_putchar(n + 48);
	return (len);
}

int	ft_puthex(unsigned int n)
{
	int	len = 0;

	if (n > 15)
	{
		len += ft_puthex(n / 16);
		len += ft_puthex(n % 16);
	}
	else if (n > 9)
		len += ft_putchar(n + 87);
	else
		len += ft_putchar(n + 48);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int			i = -1;
	int			len = 0;
	va_list		ptr;

	va_start(ptr, format);
	while (format[++i])
	{
		if (format[i] != '%')
			len += write(1, &format[i], 1);
		else if (format[i] == '%' && format[i + 1])
		{
			i++;
			if (format[i] == 's')
				len += ft_putstr(va_arg(ptr, char *));
			else if (format[i] == 'x')
				len += ft_puthex(va_arg(ptr, unsigned int));
			else if (format[i] == 'd')
				len += ft_putnbr(va_arg(ptr, int));
		}
	}
	va_end(ptr);
	return (len);
}

#include <stdio.h>

int main()
{
    printf("%d\n", (ft_printf("%s\n", "AVE MARIA")));
    printf("%d\n", (printf("%s\n", "AVE MARIA")));
}