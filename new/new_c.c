#include "../minitalk.h"
#include <signal.h>

void	client_sig_handler(int code)
{
	if (code == SIGUSR1)
		exit(0);
	else if (code == SIGUSR2)
		ft_printf("Message successfully received by the server.\n");
	else
		ft_printf("Error\nUnexpected signal received\n");
}

void	send_message(int server_pid, char *message)
{
	int	i;

	i = 0;
	send_char(server_pid, getpid());
	pause();
	while(message[i])
	{
		send_char(server_pid, message[i]);
		pause();
		i++;
	}
	send_char(server_pid, 0);
	pause();
}

int	main(int argc, char **argv)
{
	int					server_pid;
	struct sigaction	sigaction_client;

	if (argc == 3)
	{
		sigaction_client.sa_handler = &client_sig_handler;
		sigaction_client.sa_flags = 0;
		sigemptyset(&sigaction_client.sa_mask);
		sigaction(SIGUSR1, &sigaction_client, NULL);
		sigaction(SIGUSR2, &sigaction_client, NULL);
		server_pid = ft_atoi(argv[1]);
		send_message(server_pid, argv[2]);
	}
	else
		ft_printf("Error\n\nMust be used like :\n%s <PID> \"message\"\n", argv[0]);
}