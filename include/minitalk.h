/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abboudje <abboudje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 02:30:49 by abboudje          #+#    #+#             */
/*   Updated: 2024/11/02 16:05:39 by abboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include<stdio.h>
# include<unistd.h>
# include<stdlib.h>
# include<signal.h>

/***************************CORE***************************/
void	ft_putstr_fd(char const *s, int fd);
size_t	ft_strlen(const char *s);
void	ft_putnbr_fd(int n, int fd);
int		ft_atoi(const char *str);
/***************************CLIENT.C******************************/
void	response_handler(int signal_type);
void	send_bit(int server_pid, int bit_value);
void	send_char(int server_pid, unsigned char c);
void	send_string(int server_pid, const char *str);

/***************************SERVER.C******************************/
void	ft_handle_signal(int signal_type, siginfo_t *info, void *context);

#endif