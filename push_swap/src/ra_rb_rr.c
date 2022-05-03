/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 15:08:29 by younjkim          #+#    #+#             */
/*   Updated: 2022/04/23 13:26:11 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_ps *data)
{
	ra(data, 0);
	rb(data, 0);
	write(1, "rr\n", 3);
}

void	ra(t_ps *data, int mode)
{
	char	*temp;
	int		i;

	i = 0;
	temp = data->a[0];
	while (data->a[i] != NULL && data->a[i + 1] != NULL)
	{
		data->a[i] = data->a[i + 1];
		i++;
	}
	data->a[i] = temp;
	if (mode != 0)
		write(1, "ra\n", 3);
}

void	rb(t_ps *data, int mode)
{
	char	*temp;
	int		i;

	i = 0;
	temp = data->b[0];
	while (data->b[i] != NULL && data->b[i + 1] != NULL)
	{
		data->b[i] = data->b[i + 1];
		i++;
	}
	data->b[i] = temp;
	if (mode != 0)
		write(1, "rb\n", 3);
}
