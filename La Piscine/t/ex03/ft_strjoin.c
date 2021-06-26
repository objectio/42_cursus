/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 19:41:26 by younjkim          #+#    #+#             */
/*   Updated: 2021/04/15 03:04:53 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

long long	ft_strlen(char *str)
{
	long long i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char		*ft_strcat(char *dest, char *src)
{
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	return (dest);
}

char		*ft_strjoin(int size, char **strs, char *sep)
{
	char		*dest;
	char		*temp;
	long long	len;
	int			i;

	if (size == 0)
	{
		dest = ((char *)malloc(1));
		dest[0] = 0;
		return (dest);
	}
	len = 0;
	i = 0;
	while (i < size)
		len += ft_strlen(strs[i++]);
	dest = (char *)malloc(len + (size - 1) * ft_strlen(sep) + 1);
	temp = ft_strcat(dest, strs[0]);
	i = 1;
	while (i < size)
	{
		temp = ft_strcat(temp, sep);
		temp = ft_strcat(temp, strs[i++]);
	}
	*temp = 0;
	return (dest);
}
