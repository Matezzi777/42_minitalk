/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 03:26:05 by maxmart2          #+#    #+#             */
/*   Updated: 2025/02/26 03:26:07 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	void		*d;

	if ((!dest && !src) || (dest == src))
		return (dest);
	d = dest;
	if (dest > src)
		while (n--)
			((char *)dest)[n] = ((char *)src)[n];
	else
		while (n--)
			*(char *)dest++ = *(char *)src++;
	return (d);
}
