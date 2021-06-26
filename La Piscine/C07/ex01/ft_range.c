/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 18:12:32 by younjkim          #+#    #+#             */
/*   Updated: 2021/04/12 19:03:33 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int *dest;
	int len;
	int i;

	if (min >= max)
		return (NULL);
	len = max - min;
	dest = (int *)malloc(sizeof(int) * len);
	i = 0;
	while (i < len)
	{
		dest[i] = min + i;
		i++;
	}
	return (dest);
}
