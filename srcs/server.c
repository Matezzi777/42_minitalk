/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 22:53:27 by maxmart2          #+#    #+#             */
/*   Updated: 2025/05/18 02:09:51 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "libft.h"

int	main(void)
{
	ft_printf("PID : %d\n", getpid());
	while (TRUE)
	{
		ft_printf("Waiting for signals...\n");
		sleep(1);
	}
}
