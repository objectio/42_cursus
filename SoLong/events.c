/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 21:22:24 by younjkim          #+#    #+#             */
/*   Updated: 2022/03/27 21:22:31 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_end(int keycode, t_game *g)
{
	(void)g;
	if (keycode == 53)
		exit(0);
	return (0);
}

void	ft_die(t_game *g)
{
	mlx_destroy_window(g->mlx, g->win);
	g->win = mlx_new_window(g->mlx, 10 * 32,
			10 * 32, "so_long");
	mlx_string_put(g->mlx, g->win, 10 * 16 - 16,
		10 * 16 - 16, 0x0066FF33, "YOU DIE!");
	g->end_flag = 1;
	mlx_hook(g->win, 17, 0, ft_exit, NULL);
	mlx_key_hook(g->win, ft_end, g);
}

void	ft_win(t_game *g)
{
	mlx_destroy_window(g->mlx, g->win);
	g->win = mlx_new_window(g->mlx, 10 * 32,
			10 * 32, "so_long");
	mlx_string_put(g->mlx, g->win, 10 * 16 - 16,
		10 * 16 - 16, 0x0066FF33, "YOU WIN!");
	g->end_flag = 1;
	mlx_hook(g->win, 17, 0, ft_exit, NULL);
	mlx_key_hook(g->win, ft_end, g);
}

int	ft_events(t_game *g, char c)
{
	if (c == '1')
		return (0);
	if (c == 'C')
	{
		g->countcoin += 1;
		if (g->maxcoin == g->countcoin)
			g->open_flag = 1;
	}
	if (c == 'W')
	{
		ft_putnbr(++g->step);
		ft_die(g);
	}
	if (c == 'E')
	{
		if (g->open_flag == 1)
		{	
			ft_putnbr(++g->step);
			ft_win(g);
		}
		return (0);
	}
	return (1);
}
