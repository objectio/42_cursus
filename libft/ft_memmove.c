/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 12:57:08 by younjkim          #+#    #+#             */
/*   Updated: 2021/06/12 13:32:18 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*s;
	unsigned char	*d;

	if (dst == src || !len)
		return (dst);
	s = (unsigned char*)src;
	d = (unsigned char*)dst;
	if (dst < src)
		while (len--)
			*d++ = *s++;
	else
		while (len--)
			*(d + len) = *(s + len);
	return (dst);
}
