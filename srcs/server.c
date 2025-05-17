/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 22:53:27 by maxmart2          #+#    #+#             */
/*   Updated: 2025/05/17 22:53:32 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void	handler(int sig, siginfo_t *info, void *context)
{
	(void)context;
	printf("Signal %d received (from PID %d).\n", sig, info->si_pid);
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;

	(void)argc;
	(void)argv;

	printf("Server PID : %d\n", getpid());
	sa.sa_sigaction = handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;

	sigaction(SIGINT, &sa, NULL);

	while (1)
	{
		printf("Waiting for signals...\n");
		sleep(1);
	}

	return (0);
}