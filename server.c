#include "minitalk.h"

int	main(void)
{
	ft_printf("Server launched with PID : %d\nEn attente d'un signal...\n", getpid());
	ft_printf("Server stopped.\n");
}