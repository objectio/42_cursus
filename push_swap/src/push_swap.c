/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 18:28:08 by younjkim          #+#    #+#             */
/*   Updated: 2022/04/23 13:21:58 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_data(t_ps *data)
{
	free(data->aint);
	free(data->a);
	free(data->b);
	free(data);
}

static int	check_solved(t_ps *data)
{
	int	i;

	i = 0;
	while (data->a[i] != NULL && data->a[i + 1] != NULL)
	{
		if (ft_atoi(data->a[i]) > ft_atoi(data->a[i + 1]))
			return (0);
		i++;
	}
	return (1);
}

static void	push_swap(t_ps *data)
{
	if (check_solved(data) == 1)
		return ;
	if (data->argc < 4)
		sa(data);
	else if (data->argc < 5)
		solve_easy(data);
	else if (data->argc < 7)
		solve_med(data);
	else
		solve_hard(data);
	free_data(data);
}

int	main(int argc, char **argv)
{
	t_ps	*data;

	if (argc == 1)
		return (0);
	if (argc < 2)
		error("Error\n");
	data = (t_ps *)malloc(sizeof(t_ps));
	data->argc = argc;
	if (!check_argv(data, argv))
		error("Error\n");
	push_swap(data);
}
