/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 22:53:24 by maxmart2          #+#    #+#             */
/*   Updated: 2025/05/18 23:44:35 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <signal.h>

volatile sig_atomic_t	g_acknowledge = 0;

void	sig_handler(int sig)
{
	(void)sig;
	g_acknowledge = 1;
	if (sig == SIGUSR2)
		ft_printf("\033[32mMessage successfuly sent!\n\033[0m");
}

void	send_character(int pid, unsigned char c)
{
	int	i;

	i = 8;
	while (--i >= 0)
	{
		if ((c >> i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (!g_acknowledge)
			pause();
		g_acknowledge = 0;
	}
}

void	send_message(int pid, char *message)
{
	int	i;

	i = -1;
	while (message[++i])
		send_character(pid, (unsigned char)message[i]);
	send_character(pid, '\0');
}

int	main(int argc, char **argv)
{
	pid_t				server_pid;
	struct sigaction	sa;

	if (argc != 3)
		ft_printf("Wrong nb of arguments.\nUse : ./client <PID> <string>\n");
	else
	{
		server_pid = (pid_t)ft_atoi(argv[1]);
		sa.sa_handler = &sig_handler;
		sigemptyset(&sa.sa_mask);
		sa.sa_flags = 0;
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		ft_printf("Sending \"%s\" to server %d.\n\n", argv[2], server_pid);
		send_message(server_pid, argv[2]);
	}
}
