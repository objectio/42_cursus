/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 10:32:20 by younjkim          #+#    #+#             */
/*   Updated: 2022/01/20 16:15:57 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsigned(int nbr)
{
	int				len;
	unsigned int	n;

	n = nbr;
	len = 0;
	if (n > 9)
	{
		len += ft_putnbr(n / 10);
		len += ft_putchar(n % 10 + '0');
	}
	else
		len += ft_putchar(n + '0');
	return (len);
}

int	ft_pointerhex(unsigned long nbr)
{
	int		len;

	len = 0;
	if (nbr < 16)
	{
		if (nbr < 10)
			len += ft_putchar(nbr + 48);
		else
			len += ft_putchar(nbr + 87);
	}
	if (nbr > 15)
	{
		len += ft_pointerhex(nbr / 16);
		len += ft_pointerhex(nbr % 16);
	}
	return (len);
}

int	ft_pointer(void *ptr)
{
	int		len;

	len = 0;
	len += ft_putstr("0x");
	len += ft_pointerhex((unsigned long)ptr);
	return (len);
}
