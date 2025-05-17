/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 17:36:59 by maxmart2          #+#    #+#             */
/*   Updated: 2025/05/18 01:38:04 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

static int	ft_manage_arg(char type, va_list args);

int	ft_printf(const char *format, ...)
{
	int		written;
	int		i;
	int		temp;
	va_list	args;

	va_start(args, format);
	written = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			temp = ft_manage_arg(format[++i], args);
			if (temp == -1)
				return (-1);
			written += temp;
		}
		else
			written += ft_print_character(format[i]);
		i++;
	}
	va_end(args);
	return (written);
}

static int	ft_manage_arg(char type, va_list args)
{
	if (type == 'c')
		return (ft_print_character(va_arg(args, int)));
	else if (type == 's')
		return (ft_print_string(va_arg(args, char *)));
	else if (type == 'p')
		return (ft_print_address(va_arg(args, void *)));
	else if (type == 'd' || type == 'i')
		return (ft_print_integer(va_arg(args, int)));
	else if (type == 'u')
		return (ft_print_unsigned(va_arg(args, unsigned int)));
	else if (type == 'x')
		return (ft_print_hexa(va_arg(args, int), FALSE));
	else if (type == 'X')
		return (ft_print_hexa(va_arg(args, int), TRUE));
	else if (type == '%')
		return (ft_print_character('%'));
	else
		return (-1);
}
