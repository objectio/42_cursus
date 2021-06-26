/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 19:04:15 by younjkim          #+#    #+#             */
/*   Updated: 2021/04/15 05:56:01 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int *dest;
	int len;

	if (min >= max)
		return (0);
	len = max - min;
	*range = (int *)malloc(sizeof(int) * len);
	if (!*range)
		return (-1);
	dest = *range;
	while (min < max)
	{
		*dest = min++;
		dest++;
	}
	return (len);
}
