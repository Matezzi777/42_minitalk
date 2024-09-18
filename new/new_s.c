#include "../minitalk.h"

unsigned int	g_count = 0;

void	server_sig_handler(int code)
{
	static int	actual_char;
	static int	client_pid;

	if (code == SIGUSR1)
		actual_char = actual_char << 1;
	else if (code == SIGUSR2)
		actual_char = (actual_char << 1) + 1;
	else
		ft_printf("Error\nUnexpected signal received\n");
	if ((++g_count % 32 == 0))
	{
		if (actual_char == 0)
		{
			ft_printf("Transmission terminée.\n\n");
			kill(client_pid, SIGUSR2); //Envoyer SIGUSR2
		}
		else
		{
			if (g_count == 32)
				client_pid = actual_char;
			else
				ft_putchar_fd(actual_char, 1);
			kill(client_pid, SIGUSR1); //Envoyer SIGUSR1
		}
	}
}

int		main(void)
{
	struct sigaction sigaction_server;

	ft_printf("=== SERVER STARTED ===\nEn attente...\n");
	sigaction_server.sa_handler = &server_sig_handler;
	sigaction_server.sa_flags = 0;
	sigemptyset(&sigaction_server.sa_mask);
	sigaction(SIGUSR1, &sigaction_server, NULL);
	sigaction(SIGUSR2, &sigaction_server, NULL);
	while (1)
	{
		pause();
	}
}
