#include "minitalk.h"

void	send_char(int pid, unsigned int c)
{
	int	i;

	i = 0;
	while (i < 32)
	{
		if (c & (1U << i))
			kill(pid, SIGUSR2); //0
		else
			kill(pid, SIGUSR1); //1
		usleep(50000);
		i++;
	}
}

void	send_bit(pid_t pid, char bit, char flag_to_pause)
{
	if (bit == 0)
	{
		if (kill(pid, SIGUSR1) < 0)
		{
			ft_printf("Error sending SIGUSR1\n");
			exit(EXIT_FAILURE);
		}
	}
	else if (bit == 1)
	{
		if (kill(pid, SIGUSR2) < 0)
		{
			ft_printf("Error sending SIGUSR2\n");
			exit(EXIT_FAILURE);
		}
	}
	if (flag_to_pause != 0)
		pause();
}