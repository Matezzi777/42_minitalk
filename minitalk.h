#ifndef MINITALK
# define MINITALK

// LIBRARIES
//personal libs
# include "libft/libft.h"
# include "my_printf/ft_printf.h"
//system libs
# include <unistd.h> //write(), pause(), sleep(), usleep()
# include <signal.h> //signal(), sigaction(), sigemptyset(), sigaddset(), sigaction(), kill(), getpid()
# include <stdlib.h> //malloc(), free(), exit()

// FUNCTIONS
//utils.c
void	send_char(int pid, unsigned int c);

#endif