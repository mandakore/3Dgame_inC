/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atashiro <atashiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 13:00:42 by atashiro          #+#    #+#             */
/*   Updated: 2024/11/16 03:14:21 by atashiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_overflow(unsigned long nbr, int sign)
{
	if (sign == 1)
		if (nbr >= LONG_MAX / 10)
			return (-1);
	if (sign == -1)
		if (nbr >= LONG_MAX / 10)
			return (0);
	return (1);
}

static int	check_space(int c)
{
	while ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	unsigned long	nbr;
	int				sign;
	int				overflow;

	nbr = 0;
	sign = 1;
	while (check_space(*str))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		overflow = check_overflow(nbr, sign);
		if (overflow != 1)
			return (overflow);
		nbr = (nbr * 10) + (*str++ - '0');
	}
	return (nbr * sign);
}

// #include <string.h>
// #include <ctype.h>

// int main(void)
// {
// //test1
// 	printf("atoi:%d,%d\n", atoi("+0042"), atoi("-42"));
// 	printf("ft_atoi:%d,%d\n", ft_atoi("+0042"), ft_atoi("-42"));
// //test2
// 	printf("atoi:%d,%d\n", atoi("2147483648"), atoi(" \n 42"));
// 	printf("ft_atoi:%d,%d\n", ft_atoi("2147483648"), ft_atoi(" \n 42"));
// //test3
// 	printf("atoi:%d,%d\n", atoi("  ++--234"), atoi("-++--555"));
// 	printf("ft_atoi:%d,%d\n", ft_atoi("  ++--234"), ft_atoi("-++--555"));
// }
