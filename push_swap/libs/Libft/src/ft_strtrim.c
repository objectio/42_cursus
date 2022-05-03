/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 18:21:55 by younjkim          #+#    #+#             */
/*   Updated: 2022/04/23 18:21:56 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_start(char const *s1, char const *set, int start)
{
	int	j;
	int	count;

	while (s1[start])
	{
		j = 0;
		count = 0;
		while (set[j])
		{
			if (set[j] == s1[start])
				count++;
			j++;
		}
		if (count == 0)
			break ;
		start++;
	}
	return (start);
}

static int	ft_final(char const *s1, char const *set, int final)
{
	int	j;
	int	count;

	while (s1[final])
	{
		j = 0;
		count = 0;
		while (set[j])
		{
			if (set[j] == s1[final])
				count++;
			j++;
		}
		if (count == 0)
			break ;
		final--;
	}
	return (final);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	final;

	if (!s1)
		return (NULL);
	start = 0;
	final = ft_strlen(s1) - 1;
	start = ft_start(s1, set, start);
	if (start == ft_strlen(s1))
		return (ft_substr(s1, start, 0));
	final = ft_final(s1, set, final);
	return (ft_substr(s1, start, final - start + 1));
}
