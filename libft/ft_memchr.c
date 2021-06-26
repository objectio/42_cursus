/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 15:06:03 by younjkim          #+#    #+#             */
/*   Updated: 2021/06/12 15:36:22 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *ptr;

	if (!n)
		return (0);
	ptr = (unsigned char*)s;
	while (n--)
	{
		if (*ptr == ((unsigned char)c))
			return (ptr);
		else
			ptr++;
	}
	return (0);
}
