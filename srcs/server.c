/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 22:53:27 by maxmart2          #+#    #+#             */
/*   Updated: 2025/05/18 23:42:24 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <signal.h>

volatile sig_atomic_t	g_lezgo = 0;

void	ft_put_logo(void)
{
	ft_printf("\033[31m ▄▄   ▄▄  ▄▄▄  ▄▄    ▄  ▄▄▄  ▄▄▄▄▄▄▄  ▄▄▄▄▄▄  ▄▄▄      "
		"▄▄▄   ▄ \n");
	ft_printf("\033[32m█  █▄█  ██   ██  █  █ ██   ██       ██      ██   █    █"
		"   █ █ █\n");
	ft_printf("\033[33m█       ██   ██   █▄█ ██   ██▄     ▄██  ▄   ██   █    █"
		"   █▄█ █\n");
	ft_printf("\033[34m█       ██   ██       ██   █  █   █  █ █▄█  ██   █    █"
		"      ▄█\n");
	ft_printf("\033[35m█       ██   ██  ▄    ██   █  █   █  █      ██   █▄▄▄ █"
		"     █▄\n");
	ft_printf("\033[36m█ ██▄██ ██   ██ █ █   ██   █  █   █  █  ▄   ██       ██"
		"    ▄  █\n");
	ft_printf("\033[37m█▄█   █▄██▄▄▄██▄█  █▄▄██▄▄▄█  █▄▄▄█  █▄█ █▄▄██▄▄▄▄▄▄▄██"
		"▄▄▄█ █▄█\n\033[0m");
}

void	sig_handler(int sig, siginfo_t *info, void *context)
{
	static int				bit_index = 0;
	static unsigned char	current_char = 0;

	(void)context;
	if (sig == SIGUSR1)
		current_char |= (1 << (7 - bit_index));
	bit_index++;
	if (bit_index == 8)
	{
		if (current_char == '\0')
		{
			kill(info->si_pid, SIGUSR2);
			g_lezgo = 1;
		}
		else
			write(1, &current_char, 1);
		bit_index = 0;
		current_char = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = &sig_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_put_logo();
	ft_printf("\n   ================\n   | PID : %d |\n"
		"   ================\n\n", getpid());
	while (TRUE)
	{
		ft_printf("Waiting for signals...\n\n\033[34m");
		while (TRUE)
		{
			pause();
			if (g_lezgo)
				break ;
		}
		g_lezgo = 0;
		ft_printf("\n\n\033[0m");
	}
}
