/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_udlr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 22:56:39 by younjkim          #+#    #+#             */
/*   Updated: 2021/04/04 22:57:34 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		check_udlr(int index, int **conditions, int *answer)
{
	if (check_left_right(index, conditions, answer) == 0 || check_up_down(index, conditions, answer) == 0)
		return (0);
	return (1);
}

int		check_up_down(int index, int **conditions, int *answer)
{
	int	up_value;
	int	down_value;

	if (index / N == 3)
	{
		get_down_value(index, conditions, answer, &down_value);
		get_up_value(index, conditions, answer, &up_value);
		if (up_value != conditions[0][index - N * (N - 1)] || down_value != conditions[1][index - N * (N - 1)])
			return (0);
	}
	return (1);
}

int		check_left_right(int index, int **conditions, int *answer)
{
	int	left_value;
	int	right_value;

	if (index % N == N - 1)
	{
		get_left_value(index, conditions, answer, &left_value);
		get_right_value(index, conditions, answer, &right_value);
		if (left_value != conditions[2][(index + 1) / N - 1] || right_value != conditions[3][(index + 1) / N - 1])
			return (0);
	}
	return (1);
}
