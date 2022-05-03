/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mid_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 19:17:12 by younjkim          #+#    #+#             */
/*   Updated: 2022/04/23 13:34:06 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_solved(t_ps *data)
{
	int	i;

	i = 0;
	while (data->a[i] != NULL && data->a[i + 1] != NULL)
	{
		if (ft_atoi(data->a[i]) > ft_atoi(data->a[i + 1]))
			return (-1);
		i++;
	}
	return (1);
}
