#include "../minitalk.h"

int	actual_char;

void	server_sighandler(int code)
{
	static int	actual_char;

	if (code == SIGUSR1)
		actual_char = actual_char << 1;
	else if (code == SIGUSR2)
		actual_char = (actual_char << 1) + 1;
	else
		ft_printf("Unexpected SIGNAL received.\n");
	if (++g_count == 32)
	{
		if (actual_char == 0)
		{

		}
	}
}

void	setup_server_sigreaction(struct sigaction *sa_server)
{
	sa_server->sa_handler = &server_sighandler;
	sa_server->sa_flags = 0;
	sigemptyset(&sa_server->sa_mask);
	sigaction(SIGUSR1, &sa_server, NULL);
	sigaction(SIGUSR2, &sa_server, NULL);
}

int	main(void)
{
	struct sigaction	sa_server;
	static unsigned int	count;
	pid_t				pid_client;

	setup_server_sigreaction(&sa_server);
	pid_client = wait_for_pidclient();
	while (1)
		pause();
}