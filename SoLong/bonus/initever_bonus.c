/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initever_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 21:30:48 by younjkim          #+#    #+#             */
/*   Updated: 2022/03/27 21:30:54 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	init(t_game *g)
{
	g->fd = 0;
	g->len = 0;
	g->floor = 0;
	g->exit = 0;
	g->empty = 0;
	g->wall = 0;
	g->collect = 0;
	g->player = 0;
	g->countcoin = 0;
	g->end_flag = 0;
	g->alive_flag = 0;
	g->end_flag = 0;
	g->mlx = NULL;
	g->win = NULL;
	g->maxcoin = 0;
	g->open_flag = 0;
	g->step = 0;
}
