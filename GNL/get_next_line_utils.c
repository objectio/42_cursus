/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 04:59:43 by younjkim          #+#    #+#             */
/*   Updated: 2021/11/28 18:49:28 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	index;

	index = 0;
	while (s[index])
		index++;
	return (index);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	len_s1;
	size_t	len_s2;
	char	*ret;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	ret = malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		ret[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		ret[i + j] = s2[j];
		j++;
	}
	ret[i + j] = 0;
	return (ret);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == ((char)c))
			return ((char *)s);
		s++;
	}
	if (!c)
		return ((char *)s);
	return (0);
}

char	*ft_strdup(const char *s1)
{
	char	*dst;
	int		len;

	len = 0;
	while (s1[len])
		len++;
	dst = (char *)malloc(len + 1);
	if (dst == NULL)
		return (0);
	dst[len] = 0;
	while (--len >= 0)
		dst[len] = s1[len];
	return (dst);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	len_s;
	char	*ret;

	len_s = ft_strlen(s);
	if (len_s < len)
		len = len_s;
	ret = (char *)malloc(sizeof(char) * (len - start + 1));
	if (ret == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		if (i >= start)
			ret[i - start] = s[i];
		i++;
	}
	ret[i - start] = 0;
	return (ret);
}
