/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 05:33:07 by younjkim          #+#    #+#             */
/*   Updated: 2021/04/15 05:59:26 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		nbr_size(long long nbr, int base_len);
int		is_valid(char *base, int *len);
int		is_white(char c);

int		atoi_base(char *str, char *base, int base_len)
{
	int ret;
	int sign;
	int i;

	ret = 0;
	sign = 1;
	while (is_white(*str))
		++str;
	while (*str == '+' || *str == '-')
		if (*(str++) == '-')
			sign *= -1;
	while (*str)
	{
		i = -1;
		while (++i < base_len)
		{
			if (*str == base[i])
				break ;
		}
		if (i == base_len)
			break ;
		ret = ret * base_len + (sign * i);
		++str;
	}
	return (ret);
}

char	*putnbr_b(int nbr, char *base, int base_len)
{
	long long	tmp;
	char		*ret;
	int			size;

	if (nbr == 0)
	{
		ret = (char*)malloc(2);
		ret[0] = base[0];
		ret[1] = 0;
		return (ret);
	}
	tmp = nbr;
	size = nbr_size(tmp, base_len);
	ret = (char*)malloc(size + 1);
	ret[size] = 0;
	if (tmp < 0)
		tmp *= -1;
	while (tmp)
	{
		ret[--size] = base[tmp % base_len];
		tmp /= base_len;
	}
	if (nbr < 0)
		ret[0] = '-';
	return (ret);
}

char	*ft_convert_base(char *nbr, char *from, char *to)
{
	int len_f;
	int len_t;

	if (!is_valid(from, &len_f) || !is_valid(to, &len_t))
		return (0);
	return (putnbr_b(atoi_base(nbr, from, len_f), to, len_t));
}
