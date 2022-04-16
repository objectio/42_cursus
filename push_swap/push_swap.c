/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 18:28:08 by younjkim          #+#    #+#             */
/*   Updated: 2022/04/16 21:12:09 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int

static void push_swap(t_ps *data)
{
	if (check_solve(data) == 1)
		return ;
	if (data->argc < 4)
		sa(data);
	else if (data->argc < 5)
		easy(data);
	else if (data->argc < 7)
		mid(data);
	else
		hard(data);
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
