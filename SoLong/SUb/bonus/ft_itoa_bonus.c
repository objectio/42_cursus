/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 21:30:35 by younjkim          #+#    #+#             */
/*   Updated: 2022/03/27 21:30:41 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	*ft_strdup(char *s1)
{
	size_t	len;
	char	*arr;

	len = ft_strlen(s1) + 1;
	arr = (char *)malloc(len);
	if (arr == NULL)
		return (NULL);
	ft_strlcpy(arr, s1, len);
	return (arr);
}

static size_t	ft_digitlen(int n)
{
	size_t	i;
	int		f;

	f = n;
	i = 0;
	while (f / 10 != 0)
	{
		f = f / 10;
		i++;
	}
	return (i + 1);
}

static char	*ft_result(char *digit, int i, long n)
{
	size_t	j;
	size_t	size;

	j = 0;
	size = 1;
	while (j < ft_digitlen(n) - 1)
	{
		size *= 10;
		j++;
	}
	while (size > 0)
	{
		digit[i] = ('0' + n / size);
		n %= size;
		size /= 10;
		i++;
	}
	digit[i] = '\0';
	return (digit);
}

char	*ft_itoa(int n)
{
	char	*digit;
	size_t	i;
	long	nn;

	i = 0;
	nn = n;
	if (n == 0)
		return (ft_strdup("0"));
	digit = ft_calloc(ft_digitlen(nn) + 2, sizeof(char));
	if (digit == NULL)
		return (NULL);
	if (nn < 0)
	{
		digit[i] = '-';
		i++;
		nn = -nn;
	}
	ft_result(digit, i, nn);
	return (digit);
}
