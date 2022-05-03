/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 18:21:46 by younjkim          #+#    #+#             */
/*   Updated: 2022/04/23 18:21:47 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*d;

	i = -1;
	if (!needle[i + 1])
		return ((char *)haystack);
	while (++i < len && haystack[i])
	{
		if (haystack[i] == needle[0])
		{
			d = (char *)&haystack[i];
			j = 0;
			while (needle[j] && (i + j) <= len)
			{
				if (needle[j] == haystack[i + j])
					j++;
				else
					break ;
				if (needle[j] == '\0')
					return (d);
			}
		}
	}
	return (NULL);
}
