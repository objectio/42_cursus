/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 18:21:51 by younjkim          #+#    #+#             */
/*   Updated: 2022/04/23 18:21:51 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*d;

	i = ft_strlen(s);
	d = (char *)s;
	while (i >= 0)
	{
		if (s[i] == (char)c)
		{
			d += i;
			return (d);
		}
		i--;
	}
	return (NULL);
}
