/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 00:51:13 by younjkim          #+#    #+#             */
/*   Updated: 2021/04/14 22:34:42 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int					ft_sizeof(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void				str_cpy(char *dest, char *src)
{
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = 0;
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str		*result;
	int				i;

	result = (t_stock_str*)malloc(sizeof(t_stock_str) * (ac + 1));
	if (result == 0)
		return (0);
	i = 0;
	while (i < ac)
	{
		result[i].size = ft_sizeof(av[i]);
		result[i].str = (char *)malloc(result[i].size + 1);
		result[i].copy = (char *)malloc(result[i].size + 1);
		str_cpy(result[i].str, av[i]);
		str_cpy(result[i].copy, av[i]);
		i++;
	}
	result[i].str = 0;
	return (result);
}
