/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_rrb_rrr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 15:23:46 by younjkim          #+#    #+#             */
/*   Updated: 2022/04/23 13:40:42 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_ps *data)
{
	rra(data, 0);
	rrb(data, 0);
	write(1, "rrr\n", 4);
}

void	rra(t_ps *data, int mode)
{
	char	*temp;
	int		i;

	i = 0;
	while (data->a[i])
		i++;
	i--;
	temp = data->a[i];
	while (i > 0)
	{
		data->a[i] = data->a[i - 1];
		i--;
	}
	data->a[i] = temp;
	if (mode != 0)
		write(1, "rra\n", 4);
}

void	rrb(t_ps *data, int mode)
{
	char	*temp;
	int		i;

	i = 0;
	while (data->b[i])
		i++;
	i--;
	temp = data->b[i];
	while (i > 0)
	{
		data->b[i] = data->b[i - 1];
		i--;
	}
	data->b[i] = temp;
	if (mode != 0)
		write(1, "rrb\n", 4);
}
