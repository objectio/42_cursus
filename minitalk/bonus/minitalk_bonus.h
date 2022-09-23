/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 18:59:26 by younjkim          #+#    #+#             */
/*   Updated: 2022/02/28 15:05:26 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <signal.h>
# include <sys/types.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_char_handler
{
	char			byte;
	unsigned int	size;
	size_t			client_pid;
}				t_char_handler;

int		ft_atoi(const char *str);
void	ack_handler(int sig);
void	ft_putnbr_fd(int n, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);

#endif
