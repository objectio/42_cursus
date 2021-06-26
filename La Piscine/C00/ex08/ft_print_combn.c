/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 17:54:52 by younjkim          #+#    #+#             */
/*   Updated: 2021/03/31 20:43:21 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print(int n, int numb[])
{
	int i;

	i = 0;
	while (i < n)
	{
		ft_putchar(48 + numb[i]);
		i++;
	}
	i = n - 1;
	while (i >= 0)
	{
		if (numb[i] != 10 - (n - i))
		{
			ft_putchar(',');
			ft_putchar(' ');
			break ;
		}
		i--;
	}
}

void	recursive(int now, int n, int numb[], int printnumber)
{
	int i;

	if (now == n)
		ft_print(n, numb);
	else
	{
		i = printnumber + 1;
		while (i <= 10 - (n - now))
		{
			numb[now] = i;
			recursive(now + 1, n, numb, i);
			i++;
		}
	}
}

void	ft_print_combn(int n)
{
	int numb[10];
	int i;

	i = 0;
	while (i < n)
	{
		numb[i] = 0;
		i++;
	}
	recursive(0, n, numb, -1);
}
