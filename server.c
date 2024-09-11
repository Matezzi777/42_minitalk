/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartina <mmartina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:48:34 by mmartina          #+#    #+#             */
/*   Updated: 2024/09/12 00:52:46 by mmartina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

unsigned int	g_count = 0;

void	handle_signal(int code)
{
	static int	actual_char;

	if (code == SIGUSR1)
		actual_char = actual_char << 1;
	else if (code == SIGUSR2)
		actual_char = (actual_char << 1) + 1;
	else
		ft_printf("\nERROR : UNEXPECTED SIGNAL RECEIVED\n");
	if ((++g_count % 32) == 0)
	{
		if (actual_char == 0)
		{
			ft_printf("\nTRANSMISSION TERMINEE\n\nEn attente d'un signal...\n");
		}
		else
			ft_putchar_fd(actual_char, 1);
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_flags = 0;
	sa.sa_handler = &handle_signal;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("Server launched with PID : %d\nEn attente d'un signal...\n",
		getpid());
	while (1)
		pause();
}
