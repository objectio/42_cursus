/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opendoor_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 21:30:03 by younjkim          #+#    #+#             */
/*   Updated: 2022/03/27 21:30:10 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_helper(t_game *g, int *delay)
{
	if ((*delay) == 30)
		g->exits.path = "./assets/exit7.xpm";
	if ((*delay) == 35)
		g->exits.path = "./assets/exit8.xpm";
	if ((*delay) == 40)
		g->exits.path = "./assets/exit9.xpm";
	if ((*delay) == 45)
		g->exits.path = "./assets/exit10.xpm";
	if ((*delay) == 50)
		g->exits.path = "./assets/exit11.xpm";
	if ((*delay) == 55)
		g->exits.path = "./assets/exit12.xpm";
}

int	ft_opendoor(t_game *g)
{
	static int	delay = 0;

	if (delay == 0)
		g->exits.path = "./assets/exit1.xpm";
	if (delay == 3)
		g->exits.path = "./assets/exit2.xpm";
	if (delay == 7)
		g->exits.path = "./assets/exit3.xpm";
	if (delay == 12)
		g->exits.path = "./assets/exit4.xpm";
	if (delay == 16)
		g->exits.path = "./assets/exit5.xpm";
	if (delay == 21)
		g->exits.path = "./assets/exit6.xpm";
	ft_helper(g, &delay);
	delay++;
	g->exits.img = mlx_xpm_file_to_image(g->mlx, g->exits.path,
			&g->exits.len, &g->exits.high);
	if (g->end_flag == 0)
		ft_print_step(g);
	return (0);
}

void	ft_lt(t_game *g, int kll)
{
	if (kll == 8)
		g->enemys.path = "./assets/enemy2.xpm";
	if (kll == 16)
		g->enemys.path = "./assets/enemy3.xpm";
	if (kll == 24)
		g->enemys.path = "./assets/enemy4.xpm";
	if (kll == 30)
		g->enemys.path = "./assets/enemy5.xpm";
}

void	ft_rt(t_game *g, int kll)
{
	if (kll == 8)
		g->enemys.path = "./assets/enemy6.xpm";
	if (kll == 16)
		g->enemys.path = "./assets/enemy7.xpm";
	if (kll == 24)
		g->enemys.path = "./assets/enemy8.xpm";
	if (kll == 30)
		g->enemys.path = "./assets/enemy9.xpm";
}

int	ft_enemy_anim(t_game *g, int code)
{
	static int	kll = 0;

	if ((code % 2) == 1)
		ft_rt(g, kll);
	else
		ft_lt(g, kll);
	if (kll == 30)
		kll = -1;
	kll++;
	g->enemys.img = mlx_xpm_file_to_image(g->mlx, g->enemys.path,
			&g->enemys.len, &g->enemys.high);
	ft_print_step(g);
	return (1);
}
