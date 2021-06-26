/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 16:01:35 by younjkim          #+#    #+#             */
/*   Updated: 2021/03/31 20:41:39 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		numberof(int d)
{
	int n;

	n = 0;
	while (d > 0)
	{
		if (d != 0)
		{
			d /= 10;
			n++;
		}
	}
	return (n);
}

void	print(int d[], int size)
{
	int i;

	i = 0;
	while (i <= size)
	{
		ft_putchar(d[i] + '0');
		i++;
	}
}

void	ft_putnbr(int nb)
{
	int i;
	int n;
	int digit[10];

	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb == 0)
		write(1, "0", 1);
	if (nb < 0)
	{
		nb = nb * -1;
		write(1, "-", 1);
	}
	i = numberof(nb) - 1;
	n = numberof(nb) - 1;
	while (i >= 0)
	{
		digit[i] = nb % 10;
		nb = nb / 10;
		i--;
	}
	print(digit, n);
}
