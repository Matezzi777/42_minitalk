#include "minitalk.h"

void	send_char(int pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c >> (7 - i) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(50000);
		i++;
	}
}
/*
int	main(int argc, char **argv)
{
	int		pid;
	int		i;
	char	*message;
	char	*message_encoded;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		message = argv[2];
		i = 0;
		while (message[i])
		{
			send_char(pid, message[i]);
			i++;
		}
	}
	else
		ft_printf("Error : Wrong format!\nPlease use this way :\n\n./client <PID> \"message\"");
	return (0);
}
*/

int	main(void)
{
	ft_printf("Client launched.");
}