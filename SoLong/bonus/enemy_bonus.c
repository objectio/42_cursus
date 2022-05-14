/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 21:28:10 by younjkim          #+#    #+#             */
/*   Updated: 2022/03/27 21:28:16 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_fcnorm(t_game *g, int *e, int *counter, int *movement)
{
	if ((*e) == g->enemy)
	{
		(*movement) = ft_rn((*movement));
		(*counter)++;
		(*e) = 0;
	}
}

int	ft_side(int e)
{
	static int	change = 0;

	if (e == 0)
		change += 1;
	return (change);
}

int	ft_enemy(t_game *g)
{
	int			ij[2];
	static int	movement = 1;
	static int	counter = 0;
	static int	e = 0;

	ij[0] = 0;
	ft_enemy_anim(g, ft_side(e));
	while (g->map[ij[0]] && g->enemy != 0)
	{
		ij[1] = 0;
		while (g->map[ij[0]][ij[1]])
		{
			if (g->map[ij[0]][ij[1]] == 'W')
			{
				ij[1] += ft_enemycheck(g, ij, counter, movement);
				e += 1;
			}
			ij[1]++;
		}
		ij[0]++;
	}
	if (g->open_flag)
		ft_opendoor(g);
	ft_fcnorm(g, &e, &counter, &movement);
	return (0);
}

int	ft_enemycheck(t_game *g, int *ij, int counter, int movement)
{
	if (g->end_flag == 0 && ((counter % 31) == 0)
		&& ft_eventsw(g, g->map[ij[0]][ij[1] + movement]))
	{
		g->map[ij[0]][ij[1]] = '0';
		g->map[ij[0]][ij[1] + movement] = 'W';
		ft_print_step(g);
		if (movement == 1)
			return (1);
	}
	return (0);
}
