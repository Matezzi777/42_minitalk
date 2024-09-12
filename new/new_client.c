#include "../minitalk.h"

void	client_sighandler(int code)
{
	if (code == SIGUSR1)
		exit(0);
	else if (code == SIGUSR2)
	{
		ft_printf("SUCCESS : Message received by server.\n");
		exit(0);
	}
	else
	{
		ft_printf("Unexpected SIGNAL received.\n");
		exit(1);
	}
}

int	main(int argc, char **argv)
{
	unsigned int		i;
	struct sigaction	sa_client;

	sa_client.sa_handler = &client_sighandler;
	sa_client.sa_flags = 0;
	sigemptyset(&sa_client.sa_mask);
	sigaction(SIGUSR1, &sa_client, NULL);
	sigaction(SIGUSR2, &sa_client, NULL);
	if (argc != 3)
		ft_printf("ERROR : BAD SYNTAX\nPlease use as follow : %s <PID> \"Message to send...\"\n\n", argv[0]);
	else
	{
		i = 0;
		while (argv[2][i])
		{
			send_char(ft_atoi(argv[1]), argv[2][i]);
			pause();
			i++;
		}
		send_char(ft_atoi(argv[1]), '\0');
		pause();
	}
}