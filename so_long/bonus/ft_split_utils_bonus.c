/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 21:28:29 by younjkim          #+#    #+#             */
/*   Updated: 2022/03/27 21:28:35 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*arr;
	size_t	memory_size;

	memory_size = count * size;
	arr = malloc(memory_size);
	if (arr)
		ft_bzero(arr, memory_size);
	return (arr);
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	char	*arr;

	arr = b;
	i = 0;
	while (i < len)
	{
		arr[i] = c;
		i++;
	}
	return (b);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t		i;
	char		*arrnew;
	const char	*arrold;

	i = 0;
	arrnew = dst;
	arrold = src;
	if (dstsize == 0)
		return (ft_strlen((char *)src));
	while (i < dstsize - 1)
	{	
		if (arrold[i] == '\0')
			break ;
		arrnew[i] = arrold[i];
		i++;
	}
	if (dstsize != 0)
		arrnew[i] = '\0';
	return (ft_strlen((char *)src));
}
