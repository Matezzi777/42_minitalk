/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 22:53:24 by maxmart2          #+#    #+#             */
/*   Updated: 2025/05/17 22:57:06 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "minitalk.h"

t_bool	check_pid(char *pid)
{
	
}

int	main(int argc, char **argv)
{
	if (argc != 3)
		ft_printf("Wrong number of argument.\nUse : ./client <PID> <string>\n");
	else
	{
		if (!check_pid(argv[1]))
			return ;
	}
}