/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartina <mmartina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:48:34 by mmartina          #+#    #+#             */
/*   Updated: 2024/09/11 16:59:39 by mmartina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_signal(int code)
{
	ft_putnbr_fd(code, 1);
	ft_putchar_fd(' ', 1);
	/*
	if (code == SIGUSR1)
		ft_printf("SIGUSR1 received\n");
	else if (code == SIGUSR2)
		ft_printf("SIGUSR2 received\n");
	else
		ft_printf("Other signal received (Unexpected)\n");
	*/
}

int	main(void)
{
	int					i;
	struct sigaction	sa;

	sa.sa_flags = 0;
	sa.sa_handler = &handle_signal;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("Server launched with PID : %d\nEn attente d'un signal...\n",
		getpid());
	i = 0;
	while (1)
	{
		pause();
		i++;
		if (i == 8)
		{
			ft_putchar_fd('\n', 1);
			i = 0;
		}
	}
}
