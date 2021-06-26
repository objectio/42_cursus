/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 19:50:12 by younjkim          #+#    #+#             */
/*   Updated: 2021/06/13 01:18:23 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nbr;
	int		i;
	char	digit[20];

	i = 0;
	nbr = (long)n;
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n == 0)
		write(fd, "0", 1);
	if (n < 0)
	{
		nbr = nbr * (-1);
		write(fd, "-", 1);
	}
	while (nbr)
	{
		digit[i++] = ((nbr % 10) + '0');
		nbr /= 10;
	}
	while (--i >= 0)
		write(fd, &digit[i], 1);
}
