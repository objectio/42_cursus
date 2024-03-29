/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 20:05:49 by younjkim          #+#    #+#             */
/*   Updated: 2022/02/28 18:34:40 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

t_char_handler	g_char_handler;

void	ft_build_message(int bit, t_char_handler *char_handler)
{
	if (bit == SIGUSR1)
		bit = 0;
	else
		bit = 1;
	char_handler->byte += bit << char_handler->size;
	char_handler->size++;
	if (char_handler->size == 8)
	{
		if (char_handler->byte == 0)
			kill(g_char_handler.client_pid, SIGUSR2);
		ft_putchar_fd(char_handler->byte, 1);
		char_handler->byte = 0;
		char_handler->size = 0;
	}
}

void	ft_message_handler(int bit, siginfo_t *info, void *context)
{
	g_char_handler.client_pid = info->si_pid;
	ft_build_message(bit, &g_char_handler);
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = ft_message_handler;
	g_char_handler.byte = 0;
	g_char_handler.size = 0;
	ft_putstr_fd("Server PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putendl_fd("", 1);
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sigaction(SIGUSR2, &sa, NULL);
	sigaction(SIGUSR1, &sa, NULL);
	while (1)
		pause();
}
