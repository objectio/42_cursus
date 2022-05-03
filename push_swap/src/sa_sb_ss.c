/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb_ss.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 14:27:39 by younjkim          #+#    #+#             */
/*   Updated: 2022/04/23 13:23:50 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_ps *data)
{
	char	*tmp;

	tmp = data->a[0];
	data->a[0] = data->a[1];
	data->a[1] = tmp;
	write(1, "sa\n", 3);
}

void	sb(t_ps *data)
{
	char	*tmp;

	tmp = data->b[0];
	data->b[0] = data->b[1];
	data->b[1] = tmp;
	write(1, "sb\n", 3);
}

void	ss(t_ps *data)
{
	sa(data);
	sb(data);
	write(1, "ss\n", 3);
}
