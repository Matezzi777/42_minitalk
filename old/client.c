/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartina <mmartina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:48:27 by mmartina          #+#    #+#             */
/*   Updated: 2024/09/11 23:45:11 by mmartina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
			send_char(pid, (unsigned int)message[i]);
			i++;
		}
		send_char(pid, 0);
	}
	else
	{
		ft_printf("Error : Wrong format!\nPlease use this way :\n\n");
		ft_printf("./client <PID> \"message\"\n");
	}
	return (0);
}
