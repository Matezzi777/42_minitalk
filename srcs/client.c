/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 22:53:24 by maxmart2          #+#    #+#             */
/*   Updated: 2025/05/18 02:12:51 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "libft.h"

int	main(int argc, char **argv)
{
	int	server_pid;

	if (argc != 3)
		ft_printf("Wrong nb of arguments.\nUse : ./client <PID> <string>\n");
	else
	{
		server_pid = ft_atoi(argv[1]);
		ft_printf("Sending \"%s\" to server %d\n", argv[2], server_pid);
	}
}
