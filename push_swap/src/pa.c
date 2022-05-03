/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 13:53:56 by younjkim          #+#    #+#             */
/*   Updated: 2022/04/23 13:36:20 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	stack_del_top_b(t_ps *data)
{
	int		i;
	char	**temp;

	i = 0;
	while (data->b[i] != NULL)
		i++;
	temp = (char **)malloc(sizeof(char *) * i);
	if (!temp)
		error("Error: Failed temp malloc\n");
	i = 1;
	while (data->b[i] != NULL)
	{
		temp[i - 1] = data->b[i];
		i++;
	}
	temp[i - 1] = NULL;
	free(data->b);
	data->b = temp;
}

static void	stack_add_top_a(t_ps *data, char *s)
{
	int		i;
	char	**temp;

	i = 0;
	while (data->a[i] != NULL)
		i++;
	temp = (char **)malloc(sizeof(char *) * (i + 2));
	temp[0] = s;
	i = 0;
	while (data->a[i] != NULL)
	{
		temp[i + 1] = data->a[i];
		i++;
	}
	temp[i + 1] = NULL;
	free(data->a);
	data->a = temp;
}

void	pa(t_ps *data)
{
	char	*temp;

	temp = data->b[0];
	stack_del_top_b(data);
	stack_add_top_a(data, temp);
	write(1, "pa\n", 3);
}
