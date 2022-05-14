/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 21:23:45 by younjkim          #+#    #+#             */
/*   Updated: 2022/03/27 21:23:51 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_inintimg(t_game *g)
{
	g->players.path = "./assets/player2.xpm";
	g->players.img = mlx_xpm_file_to_image(g->mlx, g->players.path,
			&g->players.len, &g->players.high);
	g->emptys.path = "./assets/floor1.xpm";
	g->emptys.img = mlx_xpm_file_to_image(g->mlx, g->emptys.path,
			&g->emptys.len, &g->emptys.high);
	g->enemys.path = "./assets/enemy1.xpm";
	g->enemys.img = mlx_xpm_file_to_image(g->mlx, g->enemys.path,
			&g->enemys.len, &g->enemys.high);
	g->walls.path = "./assets/wall1.xpm";
	g->walls.img = mlx_xpm_file_to_image(g->mlx, g->walls.path,
			&g->walls.len, &g->walls.high);
	g->exits.path = "./assets/exit1.xpm";
	g->exits.img = mlx_xpm_file_to_image(g->mlx, g->exits.path,
			&g->exits.len, &g->exits.high);
	g->collects.path = "./assets/collect1.xpm";
	g->collects.img = mlx_xpm_file_to_image(g->mlx, g->collects.path,
			&g->collects.len, &g->collects.high);
}

void	*objec(t_game *g, char c)
{
	if (c == 'P')
		return (g->players.img);
	if (c == '0')
		return (g->emptys.img);
	if (c == 'C')
		return (g->collects.img);
	if (c == '1')
		return (g->walls.img);
	if (c == 'E')
		return (g->exits.img);
	if (c == 'W')
		return (g->enemys.img);
	return (g->emptys.img);
}

void	ft_change_anim(char *s, t_game *g)
{
	g->players.path = s;
	g->players.img = mlx_xpm_file_to_image(g->mlx, g->players.path,
			&g->players.len, &g->players.high);
	draw(g);
}

void	draw(t_game *g)
{
	int	i;
	int	j;

	i = 0;
	mlx_clear_window(g->mlx, g->win);
	while (g->map[i])
	{
		j = 0;
		while (g->map[i][j])
		{
			mlx_put_image_to_window(g->mlx, g->win, g->emptys.img,
				j * 32, i * 32);
			mlx_put_image_to_window(g->mlx, g->win, objec(g, g->map[i][j]),
				j * 32, i * 32);
			j++;
		}
		i++;
	}
}

void	start_game(t_game *g)
{
	g->mlx = mlx_init();
	if (g->mlx == NULL)
		ft_error(5);
	g->win = mlx_new_window(g->mlx, g->len * 32,
			g->floor * 32, "so_long");
	if (g->win == NULL)
		ft_error(5);
	ft_inintimg(g);
	if (g->end_flag == 0)
		draw(g);
	ft_hook(g);
	mlx_hook(g->win, 17, 0, ft_exit, NULL);
	if (g->end_flag == 0)
		mlx_loop_hook(g->mlx, ft_enemy, g);
	mlx_loop(g->mlx);
}
