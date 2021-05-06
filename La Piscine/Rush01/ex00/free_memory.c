/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 22:55:48 by younjkim          #+#    #+#             */
/*   Updated: 2021/04/04 22:56:15 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	free_memory(int **conditions, int *answer)
{
	int	i;

	free(conditions);
	i = 0;
	while (i < 4)
	{
		free(conditions[i++]);
	}
	free(answer);
}
