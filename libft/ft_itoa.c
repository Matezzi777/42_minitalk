/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 03:25:23 by maxmart2          #+#    #+#             */
/*   Updated: 2025/02/26 03:25:25 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*manage_special_cases(int n, char *conversion)
{
	if (n == 0)
	{
		conversion[0] = '0';
		conversion[1] = '\0';
	}
	else
	{
		conversion[0] = '-';
		conversion[1] = '2';
		conversion[2] = '1';
		conversion[3] = '4';
		conversion[4] = '7';
		conversion[5] = '4';
		conversion[6] = '8';
		conversion[7] = '3';
		conversion[8] = '6';
		conversion[9] = '4';
		conversion[10] = '8';
		conversion[11] = '\0';
	}
	return (conversion);
}

static int	get_size_to_malloc(int n)
{
	int	size;

	size = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		size++;
	while (n != 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	int		length;
	int		i;
	char	*conversion;

	length = get_size_to_malloc(n);
	conversion = (char *)malloc((length + 1) * sizeof(char));
	if (!conversion)
		return (NULL);
	if (n == 0 || n == -2147483648)
		return (manage_special_cases(n, conversion));
	if (n < 0)
	{
		conversion[0] = '-';
		n = -n;
	}
	i = 0;
	while (n)
	{
		conversion[length - i - 1] = n % 10 + '0';
		n = n / 10;
		i++;
	}
	conversion[length] = '\0';
	return (conversion);
}

// #include <stdio.h>

// int	main(void)
// {
// 	int	test1;
// 	int	test2;
// 	int	test3;
// 	int	test4;
// 	int	test5;
// 	int	test6;
// 	int	test7;

// 	test1 = 0;
// 	test2 = 10;
// 	test3 = -10;
// 	test4 = 42;
// 	test5 = -42;
// 	test6 = 2147483647;
// 	test7 = -2147483648;
// 	printf("'%s' -> %d\n", ft_itoa(test1), test1);
// 	printf("'%s' -> %d\n", ft_itoa(test2), test2);
// 	printf("'%s' -> %d\n", ft_itoa(test3), test3);
// 	printf("'%s' -> %d\n", ft_itoa(test4), test4);
// 	printf("'%s' -> %d\n", ft_itoa(test5), test5);
// 	printf("'%s' -> %d\n", ft_itoa(test6), test6);
// 	printf("'%s' -> %d\n", ft_itoa(test7), test7);
// }
