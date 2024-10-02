/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartina <mmartina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 01:25:22 by mmartina          #+#    #+#             */
/*   Updated: 2024/10/03 01:25:24 by mmartina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static volatile sig_atomic_t	g_acknowledge = 0;

/*Check if there are some errors in the arguments passed.
	Arguments :
	-> int	nb_args : basically argc in the main.
	-> char	**arguments : basically argv in the main.
	Returns :
	-> 1 : If an error is detected.
		-> Wrong nb of arguments.
		-> PID not only composed of digits.
		-> PID <= 0.
	-> 0 : If the arguments are corrects.
*/
static int	arg_error(int nb_args, char **arguments)
{
	int	i;

	if (nb_args != 3)
	{
		ft_printf("Error.\nInvalid number of arguments.\n");
		return (1);
	}
	i = -1;
	while (arguments[1][++i])
	{
		if (!ft_isdigit(arguments[1][i]))
		{
			ft_printf("Error.\nInvalid characters found in PID.\n");
			return (1);
		}
	}
	if (ft_atoi(arguments[1]) <= 0)
	{
		ft_printf("Error.\nPID can't be null or negative.\n");
		return (1);
	}
	return (0);
}

static void	client_sighandler(int sig, siginfo_t *info, void *context)
{
	if (sig != SIGUSR1)
	{
		ft_printf("Error\nUnexpected signal received.\n");
		exit(EXIT_FAILURE);
	}
	(void)info;
	(void)context;
	g_acknowledge = 1;
}

static void	setup_sigaction(struct sigaction *sa, siginfo_t *info, int pid)
{
	sa->sa_flags = SA_SIGINFO;
	sa->sa_sigaction = &client_sighandler;
	sigemptyset(&sa->sa_mask);
	sigaddset(&sa->sa_mask, SIGUSR1);
	sigaction(SIGUSR1, sa, NULL);
	info->si_pid = pid;
}

static void	send_char(int pid, unsigned int character)
{
	unsigned int	counter;
	int				kill_return_value;

	counter = -1;
	while (++counter < 32)
	{
		if ((character >> (31 - counter)) & 1)
			kill_return_value = kill(pid, SIGUSR1);
		else
			kill_return_value = kill(pid, SIGUSR2);
		if (kill_return_value == -1)
		{
			ft_printf("Error\nError during signal sending from client.\n");
			exit(EXIT_FAILURE);
		}
		while (!g_acknowledge)
			;
		g_acknowledge = 0;
	}
}

int	main(int argc, char **argv)
{
	int					i;
	struct sigaction	sa_client;
	siginfo_t			siginfo;

	if (arg_error(argc, argv))
		return (0);
	setup_sigaction(&sa_client, &siginfo, ft_atoi(argv[1]));
	i = -1;
	while (argv[2][++i])
		send_char(siginfo.si_pid, (unsigned int)argv[2][i]);
	send_char(siginfo.si_pid, '\0');
	ft_printf("Success !\nServer received %d characters.\n", i);
	return (0);
}
