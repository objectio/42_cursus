/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 00:35:47 by younjkim          #+#    #+#             */
/*   Updated: 2021/04/07 02:16:51 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	char *ptr;
	char *s1;
	char *s2;

	ptr = str;
	if (!*to_find)
		return (str);
	while (*ptr)
	{
		s1 = ptr;
		s2 = to_find;
		while (*s1 && *s2 && *s1 == *s2)
		{
			s1++;
			s2++;
		}
		if (!*s2)
			return (ptr);
		ptr++;
	}
	return (0);
}
