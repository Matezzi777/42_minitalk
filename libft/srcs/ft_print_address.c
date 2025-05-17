/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_address.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 17:57:40 by maxmart2          #+#    #+#             */
/*   Updated: 2025/05/18 01:41:14 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>

static void	ft_put_addr(uintptr_t addr)
{
	char	*format;

	format = "0123456789abcdef";
	if (addr <= 15)
		write(1, &format[addr], 1);
	else
	{
		ft_put_addr(addr / 16);
		ft_put_addr(addr % 16);
	}
}

int	ft_print_address(void *addr)
{
	int			written;
	uintptr_t	ptr_converted;

	if (addr == NULL)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	ptr_converted = (uintptr_t)addr;
	write(1, "0x", 2);
	ft_put_addr(ptr_converted);
	written = 2;
	while (ptr_converted)
	{
		written++;
		ptr_converted /= 16;
	}
	return (written);
}
