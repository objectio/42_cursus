/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 19:17:46 by younjkim          #+#    #+#             */
/*   Updated: 2021/06/13 06:48:27 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	int		i;

	if (size == 0 || count == 0)
		return (0);
	i = count;
	if ((ptr = (char*)malloc(count * size)) == NULL)
		return (0);
	while (i > 0)
	{
		ptr[--i] = 0;
	}
	return (ptr);
}
