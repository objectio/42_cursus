/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 18:22:01 by younjkim          #+#    #+#             */
/*   Updated: 2022/04/23 18:22:02 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*d;
	int		i;
	int		slen;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (slen < (int)start)
		return ((char *)ft_calloc(1, sizeof(char)));
	d = malloc(sizeof(char) * len + 1);
	if (!d)
		return (NULL);
	i = 0;
	ft_bzero(d, len + 1);
	if (!d)
		return (NULL);
	while (i < (int)len)
	{
		d[i] = s[start + i];
		i++;
	}
	return (d);
}
