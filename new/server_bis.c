#include "../minitalk.h"

int	flag_finished = 0;

/* This function handle the signals received by the server.


*/

// void	server_handler(int sig, siginfo_t *info, void *context)
// {
// 	static unsigned int	rec = 0;
// 	static			int	i = 0;

// 	if (sig == SIGUSR1 || sig == SIGUSR2)
// 	{
// 		if (sig == SIGUSR1)
// 			ft_printf("SIGUSR1 reçu (0).\n");
// 		if (sig == SIGUSR2)
// 			ft_printf("SIGUSR2 reçu (1).\n");
// 		kill(info->si_pid, SIGUSR1);
// 		i++;
// 	}
// 	else
// 		ft_printf("Error\nUnexpected signal received [%d].\n", sig);
// 	if (i == 32)
// 	{

// 	}
// }

// int	main(void)
// {
// 	struct sigaction	sa_server;

// 	sa_server.sa_sigaction = server_handler;
// 	sa_server.sa_flags = SA_SIGINFO;
// 	sigemptyset(&sa_server.sa_mask);
// 	sigaction(SIGUSR1, &sa_server, NULL);
// 	sigaction(SIGUSR2, &sa_server, NULL);
// 	ft_printf("Server READY - PID : %d\nListening...\n\n", getpid());
// 	while (1)
// 	{
// 		pause();
// 	}
// }

int	main(void)
{
	ft_printf("%d\nListening...\n", getpid());
}