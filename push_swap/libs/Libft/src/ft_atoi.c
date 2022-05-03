/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 18:16:42 by younjkim          #+#    #+#             */
/*   Updated: 2022/04/23 18:16:47 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long int	ft_atoi(const char *str)
{
	int				count;
	long long int	aux;

	count = 1;
	aux = 0;
	while (*str && (*str == ' ' || *str == '\f' || *str == '\n'
			|| *str == '\r' || *str == '\t' || *str == '\v'))
		str++;
	if (*str && (*str == '-' || *str == '+'))
	{
		if (*str == '-')
			count = -1;
		str++;
	}
	while ('0' <= *str && *str <= '9')
	{
		aux = (aux * 10) + (*str - '0');
		str++;
	}	
	aux = aux * count;
	return (aux);
}
