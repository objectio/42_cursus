/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 18:21:28 by younjkim          #+#    #+#             */
/*   Updated: 2022/04/23 18:21:28 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlcpy(char *dst, const char *src, unsigned long int n)
{
	char		*d;
	char		*e;
	const char	*s;

	d = dst;
	e = dst + n;
	s = src;
	while (*s != '\0' && d < e)
		*d++ = *s++;
	if (d < e)
		*d = 0;
	else if (n > 0)
		d[-1] = 0;
	while (*s != '\0')
		s++;
	return (s - src);
}
