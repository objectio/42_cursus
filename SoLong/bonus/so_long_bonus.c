/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 21:27:57 by younjkim          #+#    #+#             */
/*   Updated: 2022/03/27 21:28:02 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_error(int code)
{
	ft_putstr("Error\n");
	if (code == 1)
		ft_putstr("something wrong with map file\n");
	if (code == 2)
		ft_putstr("wrong map rule\n");
	if (code == 3)
		ft_putstr("wrong map name\n");
	if (code == 4)
		ft_putstr("wrong arguments\n");
	if (code == 5)
		ft_putstr("window can't be open\n");
	exit(0);
}

int	ft_eventsw(t_game *g, char c)
{
	(void)g;
	if (c == '1')
		return (0);
	if (c == 'C')
		return (0);
	if (c == 'P')
	{
		ft_die(g);
		return (1);
	}
	if (c == 'W')
		return (0);
	if (c == 'E')
		return (0);
	return (1);
}

int	ft_rn(int a)
{
	if (a == -1)
		return (1);
	else if (a == 1)
		return (-1);
	return (1);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		ft_error(4);
	game = malloc(1 * sizeof(t_game));
	init(game);
	if (game == NULL)
		return (0);
	check_map(argv[1], game);
	start_game(game);
	close(game->fd);
	free(game);
	return (0);
}
