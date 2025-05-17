/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 03:26:56 by maxmart2          #+#    #+#             */
/*   Updated: 2025/02/26 03:26:58 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char const *str, char const *to_find, size_t len)
{
	size_t	i;

	if (!str && !len)
		return (NULL);
	if (!*to_find)
		return ((char *)str);
	while (*str && len--)
	{
		i = 0;
		while (str[i] == to_find[i] && to_find[i] && i <= len)
		{
			if (!to_find[i + 1])
				return ((char *)str);
			i++;
		}
		str++;
	}
	return (NULL);
}
