/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brickard <brickard@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 12:41:48 by brickard          #+#    #+#             */
/*   Updated: 2022/01/19 20:57:09 by brickard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_send_char(pid_t pid, char c)
{
	int	current_bit;
	int	kill_res;

	current_bit = 0;
	while (current_bit < 8)
	{
		if (c & (1 << current_bit))
			kill_res = kill(pid, SIGUSR1);
		else
			kill_res = kill(pid, SIGUSR2);
		if (kill_res)
		{
			ft_putstr("ERROR: signal!\n");
			exit(0);
		}
		current_bit++;
		usleep(50);
	}
}

static void	ft_send_message(pid_t pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_send_char(pid, str[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc == 3)
	{
		pid = (pid_t)ft_atoi(argv[1]);
		ft_send_message(pid, argv[2]);
	}
	else
		ft_putstr("ERROR! Enter correct arguments: [PID] [Message]\n");
	return (0);
}
