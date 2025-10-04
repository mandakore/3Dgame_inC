/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atashiro <atashiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 18:47:54 by atashiro          #+#    #+#             */
/*   Updated: 2024/11/22 22:42:33 by atashiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *count)
{
	int	tmp;

	tmp = write(1, &c, 1);
	if (tmp == -1)
		return ;
	(*count) += tmp;
}

int	ft_check(va_list arg, char format, int *count)
{
	if (format == 'c')
		ft_putchar(va_arg(arg, int), count);
	else if (format == 's')
		ft_putstr(va_arg(arg, char *), count);
	else if (format == 'p')
		ft_print_address(va_arg(arg, unsigned long long), count);
	else if (format == 'd' || format == 'i')
		ft_putnbr(va_arg(arg, int), count);
	else if (format == 'u')
		ft_putunbr(va_arg(arg, unsigned int), count);
	else if (format == 'x' || format == 'X')
		ft_puthex(va_arg(arg, unsigned int), format, count);
	else
		ft_putchar('%', count);
	return (*count);
}

int	ft_printf(const char *string, ...)
{
	int		i;
	int		count;
	va_list	arg;

	va_start(arg, string);
	i = 0;
	count = 0;
	while (string[i] != '\0')
	{
		if (string[i] == '%')
		{
			i++;
			if (string[i])
				ft_check(arg, string[i], &count);
		}
		else
		{
			ft_putchar(string[i], &count);
		}
		i++;
	}
	va_end(arg);
	return (count);
}

// #include <stdio.h>

// int	main()
// {
// 	printf("printf:I'm %dyears old.\n", 24);
// 	ft_printf("ft_printf:I'm %dyears old.\n", 24);
// 	printf("\n");
// 	printf("%d\n",printf("Hello %s\n", "World!"));
// 	printf("%d\n",ft_printf("Hello %s\n", "World!"));
// 	printf("\n");
// 	ft_printf("%d, %s, %c, %x, %p, %%\n", -42, "negative", 'Z', -255, &main);
// 	printf("%d, %s, %c, %x, %p, %%\n", -42, "negative", 'Z', -255, &main);
// 	return(0);
// }