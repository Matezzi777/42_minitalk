/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartina <mmartina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:48:46 by mmartina          #+#    #+#             */
/*   Updated: 2024/09/11 16:52:20 by mmartina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

// LIBRARIES
//personal libs
# include "libft/libft.h"
# include "my_printf/ft_printf.h"
//system libs
# include <unistd.h>	//write(), pause(), sleep(), usleep()
# include <stdlib.h>	//malloc(), free(), exit()
# include <signal.h>	//signal(), sigaction(), sigemptyset()
						//sigaddset(), sigaction(), kill(), getpid()

// FUNCTIONS
//utils.c
void	send_char(int pid, unsigned int c);

#endif