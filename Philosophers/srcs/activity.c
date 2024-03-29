/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 06:19:38 by younjkim          #+#    #+#             */
/*   Updated: 2022/05/17 18:05:44 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	right_handed(t_p *p)
{
	pthread_mutex_lock(p->r_fork);
	pthread_mutex_lock(&p->info->m_msg);
	print_status(p, "has taken a fork");
	pthread_mutex_unlock(&p->info->m_msg);
	if (p->n == 1)
	{
		pthread_mutex_unlock(p->r_fork);
		ft_usleep(p->t_die);
		return ;
	}
	pthread_mutex_lock(p->l_fork);
	pthread_mutex_lock(&p->info->m_msg);
	print_status(p, "has taken a fork");
	pthread_mutex_unlock(&p->info->m_msg);
	pthread_mutex_lock(&p->info->m_msg);
	print_status(p, "is eating");
	pthread_mutex_unlock(&p->info->m_msg);
	p->count++;
	pthread_mutex_lock(&p->info->m_last_eat);
	p->t_last_eat = get_time();
	pthread_mutex_unlock(&p->info->m_last_eat);
	ft_usleep(p->t_eat);
	pthread_mutex_unlock(p->r_fork);
	pthread_mutex_unlock(p->l_fork);
}

void	left_handed(t_p *p)
{
	pthread_mutex_lock(p->l_fork);
	pthread_mutex_lock(&p->info->m_msg);
	print_status(p, "has taken a fork");
	pthread_mutex_unlock(&p->info->m_msg);
	if (p->n == 1)
	{
		pthread_mutex_unlock(p->l_fork);
		ft_usleep(p->t_die);
		return ;
	}
	pthread_mutex_lock(p->r_fork);
	pthread_mutex_lock(&p->info->m_msg);
	print_status(p, "has taken a fork");
	pthread_mutex_unlock(&p->info->m_msg);
	pthread_mutex_lock(&p->info->m_msg);
	print_status(p, "is eating");
	pthread_mutex_unlock(&p->info->m_msg);
	p->count++;
	pthread_mutex_lock(&p->info->m_last_eat);
	p->t_last_eat = get_time();
	pthread_mutex_unlock(&p->info->m_last_eat);
	ft_usleep(p->t_eat);
	pthread_mutex_unlock(p->l_fork);
	pthread_mutex_unlock(p->r_fork);
}

void	eat_activity(t_p *p)
{
	if (p->id % 2 == 0)
		right_handed(p);
	else
		left_handed(p);
}

void	activity(t_p *p)
{
	eat_activity(p);
	if (p->n_meals != -1 && p->count == p->n_meals)
	{
		pthread_mutex_lock(&p->info->m_stop);
		p->stop = 1;
		pthread_mutex_unlock(&p->info->m_stop);
		return ;
	}
	pthread_mutex_lock(&p->info->m_msg);
	print_status(p, "is sleeping");
	pthread_mutex_unlock(&p->info->m_msg);
	ft_usleep(p->t_sleep);
	pthread_mutex_lock(&p->info->m_msg);
	print_status(p, "is thinking");
	pthread_mutex_unlock(&p->info->m_msg);
	if (p->n % 2 != 0)
		ft_usleep(100);
}
