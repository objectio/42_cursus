/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 23:03:12 by younjkim          #+#    #+#             */
/*   Updated: 2021/07/04 14:45:00 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *needle, size_t len)
{
	size_t	hay_len;
	size_t	needle_len;
	size_t	i;

	if (!*needle)
		return ((char*)hay);
	i = 0;
	hay_len = ft_strlen(hay);
	needle_len = ft_strlen(needle);
	if ((hay_len < needle_len) || (len < needle_len))
		return (0);
	while (needle_len + i <= len)
	{
		if (hay[i] == *needle && \
				!(ft_strncmp(hay + i, needle, needle_len)))
			return ((char*)hay + i);
		i++;
	}
	return (0);
}
