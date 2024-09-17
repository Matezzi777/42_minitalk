#include "../minitalk.h"

int	send_message(int server_pid, char *message)
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
}

int	main(int argc, char **argv)
{
	int	server_pid;

	if (argc == 3)
	{
		server_pid = ft_atoi(argv[1]);
		send_message(server_pid, argv[2]);
		ft_printf("Message sent!\n");
	}
	else
		ft_printf("Error\n\nMust be used like :\n%s <PID> \"message\"\n", argv[0]);
}