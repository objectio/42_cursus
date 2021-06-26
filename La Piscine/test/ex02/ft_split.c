/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 19:19:13 by younjkim          #+#    #+#             */
/*   Updated: 2021/04/15 06:23:18 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void			ft_strcpy(char *dest, char *src, char *upto)
{
	while (src < upto)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = 0;
}

int				is_in(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

long long		charset_len(char *str, char *charset)
{
	long long i;

	i = 0;
	while (*str)
	{
		if (!is_in(*str, charset))
		{
			i++;
			while (*str && !is_in(*str, charset))
				str++;
		}
		str++;
	}
	return (i);
}

char			**ft_split(char *str, char *charset)
{
	char		**result;
	long long	i;
	char		*f_len;

	result = (char**)malloc(sizeof(char*) * charset_len(str, charset) + 1);
	i = 0;
	while (*str)
	{
		if (!is_in(*str, charset))
		{
			f_len = str;
			while (*str && !is_in(*str, charset))
				str++;
			result[i] = (char*)malloc(str - f_len + 1);
			ft_strcpy(result[i++], f_len, str);
		}
		str++;
	}
	result[i] = 0;
	return (result);
}
