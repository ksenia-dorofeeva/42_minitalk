/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brickard <brickard@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 12:42:04 by brickard          #+#    #+#             */
/*   Updated: 2022/01/19 20:55:36 by brickard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_handler(int signal, siginfo_t *siginfo, void *context)
{
	static char	c;
	static int	current_bit;

	(void)context;
	(void)siginfo;
	if (signal == SIGUSR1)
		c |= (1 << current_bit);
	current_bit++;
	if (current_bit == 8)
	{
		ft_putchar(c);
		c = 0;
		current_bit = 0;
	}
}

int	main(void)
{
	struct sigaction	s_sigact;

	ft_putstr("PID: ");
	ft_putnbr(getpid());
	ft_putstr("\n");
	s_sigact.sa_flags = SA_SIGINFO;
	s_sigact.sa_sigaction = ft_handler;
	if (sigaction(SIGUSR1, &s_sigact, NULL) == -1)
		ft_putstr("ERROR: signal!\n");
	if (sigaction(SIGUSR2, &s_sigact, NULL) == -1)
		ft_putstr("ERROR: signal!\n");
	while (1)
		pause();
	return (0);
}
