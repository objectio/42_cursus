/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 18:18:20 by younjkim          #+#    #+#             */
/*   Updated: 2021/06/13 04:34:46 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dst;
	int		len;

	len = 0;
	while (s[len])
		len++;
	if ((dst = (char*)malloc(len + 1)) == NULL)
		return (0);
	dst[len] = 0;
	while (--len >= 0)
		dst[len] = s[len];
	return (dst);
}
