/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 18:20:16 by younjkim          #+#    #+#             */
/*   Updated: 2022/04/23 18:20:17 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t n)
{
	size_t	i;
	char	*d;

	i = 0;
	d = (char *)b;
	while (i < n)
	{
		*d = c;
		d++;
		i++;
	}
	return (b);
}
