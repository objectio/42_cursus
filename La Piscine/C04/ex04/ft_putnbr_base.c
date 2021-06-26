/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 18:43:06 by younjkim          #+#    #+#             */
/*   Updated: 2021/04/10 12:28:21 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		is_valid(char *str)
{
	char	*ptr;
	int		i;
	int		j;

	ptr = str;
	if (str == 0 || ft_strlen(str) <= 1)
		return (0);
	while (*ptr)
	{
		if (*ptr == ' ' || *ptr == '\n' || *ptr == '\t' || *ptr == '\v'
			|| *ptr == '\f' || *ptr == '\r' || *ptr == '+' || *ptr == '-')
			return (0);
		ptr++;
	}
	i = 0;
	while (i < ptr - str)
	{
		j = i + 1;
		while (j < ptr - str)
			if (str[i] == str[j++])
				return (0);
		i++;
	}
	return (1);
}

void	base_recursive(int nbr, char *base, int len)
{
	if (nbr == -2147483648)
	{
		base_recursive(nbr / len, base, len);
		write(1, &base[-(nbr % len)], 1);
		return ;
	}
	if (nbr < 0)
	{
		write(1, "-", 1);
		base_recursive(-nbr, base, len);
		return ;
	}
	if (nbr > len - 1)
		base_recursive(nbr / len, base, len);
	write(1, &base[nbr % len], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int len;

	if (is_valid(base) == 0)
		return ;
	len = ft_strlen(base);
	base_recursive(nbr, base, len);
}
