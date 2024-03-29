/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 06:21:48 by younjkim          #+#    #+#             */
/*   Updated: 2022/05/16 10:16:41 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <errno.h>

typedef struct s_info
{
	int				n_philo;
	unsigned int	t_to_die;
	unsigned int	t_to_eat;
	unsigned int	t_to_sleep;
	unsigned int	t_start;
	int				n_meals;
	int				stop;
	pthread_mutex_t	m_stop;
	pthread_mutex_t	m_msg;
	pthread_mutex_t	m_last_eat;
}				t_info;

typedef struct s_p
{
	t_info			*info;
	int				id;
	int				n;
	int				count;
	unsigned int	t_die;
	unsigned int	t_eat;
	unsigned int	t_sleep;
	int				n_meals;
	unsigned int	t_last_eat;
	int				stop;
	pthread_t		death;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
}				t_p;

void			ft_bzero(void *s, size_t n);
int				ft_isdigit(int c);
int				ft_strlen(char *str);
int				ft_strcmp(const char *s1, const char *s2);
long			long_atoi(char *str);
unsigned int	get_time(void);
void			print_status(t_p *p, char *status);
void			print_msg(t_p *p, char *msg);
int				ft_error(char *str);
int				init_info(int ac, char **av, t_info *info);
void			init_philos(t_p *philos, t_info *info);
void			distribute_forks(t_p *p, pthread_mutex_t *forks, int n);
void			ft_usleep(unsigned int time_in_ms);
int				launching_threading(t_p *philos, t_info *info, pthread_t *th);
void			activity(t_p *p);
void			destroy_mutex(t_info *info, pthread_mutex_t *forks);

#endif
