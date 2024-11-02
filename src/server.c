/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abboudje <abboudje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 02:34:19 by abboudje          #+#    #+#             */
/*   Updated: 2024/11/02 17:04:10 by abboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include<signal.h>
#include<unistd.h>

void	ft_handle_signal(int signal_type, siginfo_t *info, void *context)
{
	static unsigned char	current_char = 0;
	static int				bit_position = 0;
	static pid_t			client_pid = 0;

	(void)context;
	if (client_pid != info->si_pid)
	{
		bit_position = 0;
		current_char = 0;
	}
	client_pid = info->si_pid;
	current_char = current_char << 1;
	if (signal_type == SIGUSR1)
		current_char = current_char | 1;
	bit_position++;
	if (bit_position == 8)
	{
		write(1, &current_char, 1);
		bit_position = 0;
		current_char = 0;
	}
	kill(client_pid, SIGUSR2);
}

int	main(void)
{
	struct sigaction	sa;

	ft_putstr_fd("Server PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\n", 1);
	sa.sa_sigaction = &ft_handle_signal;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
