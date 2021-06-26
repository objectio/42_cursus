/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 10:14:34 by younjkim          #+#    #+#             */
/*   Updated: 2021/06/12 10:19:45 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(int n)
{
	int		len;

	if (n <= 0)
		len = 1;
	else
		len = 0;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	int			len;
	int			sign;
	char		*ret;
	long long	tmp;

	if (n < 0)
		sign = -1;
	else
		sign = 1;
	len = ft_len(n);
	if (!(ret = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	ret[len] = 0;
	len--;
	tmp = n < 0 ? -(long long)n : (long long)n;
	while (len >= 0)
	{
		ret[len] = '0' + tmp % 10;
		tmp /= 10;
		len--;
	}
	if (sign == -1)
		ret[0] = '-';
	return (ret);
}
