/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 19:56:52 by younjkim          #+#    #+#             */
/*   Updated: 2022/02/28 18:12:34 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	ft_send_byte(int pid, char byte)
{
	int		shift;
	int		result;
	int		bit;

	shift = 0;
	while (shift < 8)
	{
		bit = (byte >> shift) & 1;
		if (bit == 0)
			result = kill(pid, SIGUSR1);
		else
			result = kill(pid, SIGUSR2);
		if (result == -1)
		{
			ft_putendl_fd("Server PID is invalid or doesn't exist!", 1);
			exit(1);
		}
		usleep(500);
		shift++;
	}
}

void	ft_send_message(int pid, char *message)
{
	int		i;

	i = 0;
	usleep(50);
	while (message[i] != '\0')
	{
		ft_send_byte(pid, message[i]);
		i++;
	}
	ft_send_byte(pid, 0);
}

void	ack_handler(int sig)
{
	ft_putendl_fd("Every messages are delivered successfully!", 1);
}

int	main(int argc, char **argv)
{
	int	server_pid;

	signal(SIGUSR2, ack_handler);
	if (argc != 3)
	{
		if (argc < 3)
			ft_putendl_fd("Please specify server PID and message.", 1);
		if (argc > 3)
			ft_putendl_fd("Please remove unnecessary parameters.", 1);
		return (1);
	}
	server_pid = ft_atoi(argv[1]);
	if (server_pid < 0)
		ft_putendl_fd("Please enter the PID of the server correctly.", 1);
	ft_putendl_fd("Trying to send...", 1);
	ft_send_message(server_pid, argv[2]);
	return (0);
}
