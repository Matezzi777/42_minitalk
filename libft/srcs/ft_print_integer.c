/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_integer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 17:57:39 by maxmart2          #+#    #+#             */
/*   Updated: 2025/05/18 01:48:10 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_integer(int n)
{
	int	written;

	ft_putnbr_fd(n, 1);
	if (n == INT_MIN)
		return (11);
	written = 1;
	if (n < 0)
	{
		written++;
		n *= -1;
	}
	while (n / 10)
	{
		n /= 10;
		written++;
	}
	return (written);
}
