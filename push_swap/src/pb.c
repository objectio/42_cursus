/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 14:19:53 by younjkim          #+#    #+#             */
/*   Updated: 2022/04/23 13:36:39 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	stack_del_top_a(t_ps *data)
{
	int		i;
	char	**temp;

	i = 0;
	while (data->a[i] != NULL)
		i++;
	temp = (char **)malloc(sizeof(char *) * i);
	if (!temp)
		error("Error: Failed temp malloc\n");
	i = 1;
	while (data->a[i] != NULL)
	{
		temp[i - 1] = data->a[i];
		i++;
	}
	temp[i - 1] = NULL;
	free(data->a);
	data->a = temp;
}

static void	stack_add_top_b(t_ps *data, char *s)
{
	int		i;
	char	**temp;

	i = 0;
	while (data->b[i] != NULL)
		i++;
	temp = (char **)malloc(sizeof(char *) * (i + 2));
	temp[0] = s;
	i = 0;
	while (data->b[i] != NULL)
	{
		temp[i + 1] = data->b[i];
		i++;
	}
	temp[i + 1] = NULL;
	free(data->b);
	data->b = temp;
}

int	pb(t_ps *data)
{
	char	*temp;

	temp = data->a[0];
	stack_del_top_a(data);
	stack_add_top_b(data, temp);
	write(1, "pb\n", 3);
	return (0);
}
