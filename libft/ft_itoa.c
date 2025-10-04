/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atashiro <atashiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:56:14 by atashiro          #+#    #+#             */
/*   Updated: 2024/11/16 03:42:53 by atashiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*put_num(char *s, unsigned int number, long int len)
{
	while (number > 0)
	{
		s[len--] = 48 + (number % 10);
		number = number / 10;
	}
	return (s);
}

static long int	check_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char				*s;
	long int			len;
	unsigned int		number;
	int					sign;

	sign = 1;
	len = check_len(n);
	s = (char *)malloc(sizeof(char) * (len + 1));
	if (!(s))
		return (NULL);
	s[len] = '\0';
	len--;
	if (n == 0)
		s[0] = '0';
	if (n < 0)
	{
		sign *= -1;
		number = n * sign;
		s[0] = '-';
	}
	else
		number = n;
	s = put_num(s, number, len);
	return (s);
}

// #include <string.h>
// #include <ctype.h>

// int main(void)
// {
// 	char *str1;
// 	str1 = ft_itoa(-2147483648);
// 	printf("-2147483648:%s\n", str1);
// 	free(str1);
// 	str1 = ft_itoa(-1);
// 	printf("-1:%s\n", str1);
// 	free(str1);
// 	str1 = ft_itoa(0);
// 	printf("0:%s\n", str1);
// 	free(str1);
// 	str1 = ft_itoa(1);
// 	printf("1:%s\n", str1);
// 	free(str1);
// 	str1 = ft_itoa(2147483647);
// 	printf("2147483647:%s\n", str1);
// 	free(str1);
// }