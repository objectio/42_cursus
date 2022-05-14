/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 21:22:49 by younjkim          #+#    #+#             */
/*   Updated: 2022/03/27 21:22:56 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include "./minilibx_/mlx.h"
# include <string.h>

# define BUFFER_SIZE 1000
# define PIXELS 32

typedef struct s_img
{
	char	*path;
	int		len;
	int		high;
	void	*img;
}	t_img;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	t_img	exits;
	t_img	emptys;
	t_img	enemys;
	t_img	walls;
	t_img	collects;
	t_img	players;
	int		fd;
	int		len;
	int		floor;
	int		exit;
	int		empty;
	int		enemy;
	int		wall;
	int		collect;
	int		player;
	int		countcoin;
	int		maxcoin;
	int		alive_flag;
	int		step;
	int		end_flag;
	int		open_flag;
}	t_game;

int		ft_strlen(char *s);
void	ft_putchar(char c);
void	ft_putstr(char *s);
void	check_map(char *path, t_game *g);
int		get_next_line(char **line);
void	ft_error(int code);
char	**ft_split(char const *s, char c);
void	ft_strjoinhelp(char *concs, char *s1, char *s2);
char	*ft_strjoin(char *s1, char *s2);
void	map_step(t_game *g);
int		checkends(t_game *g);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
void	init(t_game *g);
void	start_game(t_game *game);
void	draw(t_game *g);
void	ft_hook(t_game *t_game);
void	ft_move_right(t_game *g);
void	ft_move_left(t_game *g);
void	ft_move_up(t_game *g);
void	ft_move_down(t_game *g);
int		ft_events(t_game *g, char c);
void	ft_putnbr(int n);
char	*ft_itoa(int n);
char	*ft_strdup(char *s1);
void	ft_die(t_game *g);
int		ft_end(int keycode, t_game *g);
void	ft_win(t_game *g);
int		ft_enemy(t_game *g);
void	ft_print_step(t_game *g);
void	ft_change_anim(char *s, t_game *g);
int		ft_exit(void);
int		ft_eventsw(t_game *g, char c);
int		ft_rn(int a);
int		ft_enemycheck(t_game *g, int *ij, int counter, int movement);
int		ft_opendoor(t_game *g);
int		ft_enemy_anim(t_game *g, int code);

#endif
