/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartina <mmartina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 01:25:39 by mmartina          #+#    #+#             */
/*   Updated: 2024/10/03 01:36:57 by mmartina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// VARIABLE GLOBALE ACK ([0] = FLAG ACK, [1] = PID DU CLIENT)
static volatile sig_atomic_t	g_acknowledge[2] = {0, 0};

// GESTIONNAIRE DE SIGNAUX
static void	server_sighandler(int sig, siginfo_t *info, void *context)
{
	static unsigned int	character;
	static unsigned int	counter;

	(void)context;
	if (sig == SIGUSR2)
		character = character << 1;
	else if (sig == SIGUSR1)
		character = (character << 1) + 1;
	else
		ft_printf("Error\nUnexpected signal received (%d)", sig);
	counter++;
	if (counter == 32)
	{
		if (character == 0)
			write(1, "\n\n==========\nListening...\n", 26);
		else
		{
			write(1, &character, 1);
		}
		character = 0;
		counter = 0;
	}
	g_acknowledge[0] = 1;
	g_acknowledge[1] = info->si_pid;
}

//MAIN
int	main(void)
{
	struct sigaction	sa_server;

	sa_server.sa_flags = SA_SIGINFO;
	sa_server.sa_sigaction = server_sighandler;
	sigemptyset(&sa_server.sa_mask);
	sigaddset(&sa_server.sa_mask, SIGUSR1);
	sigaddset(&sa_server.sa_mask, SIGUSR2);
	if (sigaction(SIGUSR1, &sa_server, NULL) == -1
		|| sigaction(SIGUSR2, &sa_server, NULL) == -1)
	{
		ft_printf("Error\nServer failed to launch (sigaction setup).\n");
		return (0);
	}
	ft_printf("MINITALK Server ready!\nPID : %d\nListening...\n", getpid());
	while (1)
	{
		while (g_acknowledge[0] != 1)
			;
		g_acknowledge[0] = 0;
		kill(g_acknowledge[1], SIGUSR1);
	}
}
