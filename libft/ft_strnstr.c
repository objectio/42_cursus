/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 23:03:12 by younjkim          #+#    #+#             */
/*   Updated: 2021/06/13 01:04:06 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	hay_len;
	size_t	needle_len;
	size_t	i;

	if (!*needle)
		return ((char*)haystack);
	i = 0;
	hay_len = ft_strlen(haystack);
	needle_len = ft_strlen(needle);
	if ((hay_len < needle_len) || (len < needle_len))
		return (0);
	while (needle_len + i <= len)
	{
		if (haystack[i] == *needle && \
				!(ft_strncmp(haystack + i, needle, needle_len)))
			return ((char*)haystack + i);
		i++;
	}
	return (0);
}
