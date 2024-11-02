/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abboudje <abboudje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 02:28:57 by abboudje          #+#    #+#             */
/*   Updated: 2024/11/02 16:02:49 by abboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_response_received = 0;

void	response_handler(int signal_type)
{
	g_response_received = 1;
	(void)signal_type;
}

void	send_bit(int server_pid, int bit_value)
{
	int	signal;

	if (bit_value == 1)
		signal = SIGUSR1;
	else
		signal = SIGUSR2;
	if (kill(server_pid, signal) == -1)
	{
		ft_putstr_fd("Error", 2);
		exit(1);
	}
	while (!g_response_received)
		pause();
	g_response_received = 0;
}

void	send_char(int server_pid, unsigned char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		send_bit(server_pid, (c >> i) & 1);
		usleep(400);
		i--;
	}
}

void	send_string(int server_pid, const char *str)
{
	while (*str)
		send_char(server_pid, *str++);
	send_char(server_pid, '\0');
}

int	main(int argc, char **argv)
{
	pid_t	server_pid;

	if (argc != 3)
	{
		ft_putstr_fd("Usage: ./client [PID] [string]\n", 2);
		exit(1);
	}
	server_pid = ft_atoi(argv[1]);
	if (server_pid <= 0)
	{
		ft_putstr_fd("Invalid PID\n", 2);
		exit(1);
	}
	signal(SIGUSR2, response_handler);
	send_string(server_pid, argv[2]);
	return (0);
}
