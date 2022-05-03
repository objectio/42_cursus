/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 18:20:48 by younjkim          #+#    #+#             */
/*   Updated: 2022/04/23 18:20:49 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		slen;
	char	*d;

	slen = ft_strlen(s1);
	d = malloc(sizeof(char) * slen + 1);
	if (!d)
		return (NULL);
	ft_bzero(d, slen + 1);
	ft_strlcpy(d, s1, slen + 1);
	return (d);
}
