/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 22:51:05 by younjkim          #+#    #+#             */
/*   Updated: 2021/04/04 22:54:30 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		check_exception(int **conditions, int argc)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i <= 3)
	{
		while (j <= 3)
		{
			if (conditions[i][j] < 1 || 4 < conditions[i][j])
				return (1);
			j++;
		}
		j = 0;
		i++;
	}
	if (argc != 2)
	{
		return (1);
	}
	return (0);
}
