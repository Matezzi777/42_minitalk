#include "minitalk.h"

// g_acknowledge = [flag_signal_received , signal_origin_pid]
static volatile sig_atomic_t	g_acknowledge[2] = {0, 0};

// static void	extract_content(int c)
// {
// 	static int	string[100];
// 	static int	i;

// 	string[i++] = c;
// 	if (i == 100)
// 	{
// 		write(1, &string, i);
// 		i = 0;
// 	}
// 	if (c == 0)
// 	{
// 		write(1, &string, i);
// 		write(1, "\n\n==========\nListening...\n", 26);
// 		i = 0;
// 	}
// }

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

int	main(void)
{
	struct sigaction	sa_server;

	sa_server.sa_flags = SA_SIGINFO;
	sa_server.sa_sigaction = server_sighandler;
	sigemptyset(&sa_server.sa_mask);
	sigaddset(&sa_server.sa_mask, SIGUSR1);
	sigaddset(&sa_server.sa_mask, SIGUSR2);
	if (sigaction(SIGUSR1, &sa_server, NULL) == -1 || sigaction(SIGUSR2, &sa_server, NULL) == -1)
	{
		ft_printf("Error\nServer failed to launch (sigaction setup).\n");
		return (0);
	}
	ft_printf("MINITALK Server ready!\nPID : %d\nListening...\n", getpid());
	while(1)
	{
		while (g_acknowledge[0] != 1)
			pause();
		kill(g_acknowledge[1], SIGUSR1);
		g_acknowledge[0] = 0;
	}
}
