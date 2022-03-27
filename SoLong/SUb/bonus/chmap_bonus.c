/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chmap_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 21:26:59 by younjkim          #+#    #+#             */
/*   Updated: 2022/03/27 21:27:06 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_map_name(char *path)
{
	int	i;

	i = ft_strlen(path);
	if (path[i - 1] != 'r' || path[i - 2] != 'e'
		|| path[i - 3] != 'b' || path[i - 4] != '.')
		ft_error(3);
}

char	*read_map(int fd, char *str)
{
	char	*buff;
	int		rd;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buff == NULL)
		ft_error(2);
	rd = 1;
	while (rd != 0)
	{
		rd = read(fd, buff, BUFFER_SIZE);
		if (rd == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[rd] = '\0';
		str = ft_strjoin(str, buff);
	}
	free (buff);
	return (str);
}

int	checkends(t_game *g)
{
	int	i;
	int	j;

	i = 0;
	while (g->map[i])
	{
		j = 0;
		while (g->map[i][j])
		{
			if (i == 0 && g->map[i][j] != '1')
				return (1);
			else if ((i == (g->floor - 1)) && g->map[i][j] != '1')
				return (1);
			else if (((j == ft_strlen(g->map[i]) - 1) || j == 0)
				&& g->map[i][j] != '1')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	checknl(char *readed)
{
	int	i;
	int	j;

	i = 0;
	while (readed[i])
	{
		if (readed[i] == '\n' && readed[i + 1] == '\n')
		{
			j = i + 1;
			while (readed[j])
			{
				if (readed[j] != '\n')
					ft_error(2);
				j++;
			}
		}
		i++;
	}
}

void	check_map(char *path, t_game *g)
{
	static char	*readed;

	check_map_name(path);
	g->fd = open(path, O_RDONLY);
	if (g->fd == -1)
		ft_error(1);
	readed = read_map(g->fd, readed);
	if (readed == NULL)
		ft_error(1);
	checknl(readed);
	g->map = ft_split(readed, '\n');
	if (readed)
		free (readed);
	if (g->map == NULL)
		ft_error(1);
	map_step(g);
	g->len = ft_strlen(g->map[0]);
}
