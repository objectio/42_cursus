/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 21:29:46 by younjkim          #+#    #+#             */
/*   Updated: 2022/03/27 21:29:52 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_move(int keycode, t_game *g)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 2)
		ft_move_right(g);
	if (keycode == 1)
		ft_move_down(g);
	if (keycode == 0)
		ft_move_left(g);
	if (keycode == 13)
		ft_move_up(g);
	ft_print_step(g);
	return (1);
}

void	ft_print_step(t_game *g)
{
	char		*ss;

	ss = ft_itoa(g->step);
	if (g->end_flag == 0)
	{
		draw(g);
		mlx_string_put(g->mlx, g->win, 0, 0, 0x0066FF33, ss);
	}
	if (ss)
		free(ss);
}

void	ft_hook(t_game *g)
{
	mlx_key_hook(g->win, ft_move, g);
}

int	ft_exit(void)
{
	exit(0);
	return (0);
}
