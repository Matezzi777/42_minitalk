#include "minitalk.h"

int	main(int argc, char **argv)
{
	int		pid;
	int		i;
	char	*message;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		message = argv[2];
		i = 0;
		while (message[i])
		{
			ft_putnbr_fd(message[i], 1);
			write(1, " - '",4);
			ft_putchar_fd(message[i], 1);
			write(1, "'", 1);
			send_char(pid, (unsigned int)message[i]);
			i++;
		}
	}
	else
		ft_printf("Error : Wrong format!\nPlease use this way :\n\n./client <PID> \"message\"");
	return (0);
}
