/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atashiro <atashiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 23:26:20 by atashiro          #+#    #+#             */
/*   Updated: 2024/11/22 20:10:42 by atashiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s, int *count)
{
	int	i;

	if (s == NULL)
		return (ft_putstr("(null)", count));
	i = 0;
	while (s[i])
		ft_putchar(s[i++], count);
	return (*count);
}

int	ft_print_address(unsigned long long address, int *count)
{
	if (address == 0)
	{
		ft_putstr("(nil)", count);
	}
	else
	{
		ft_putstr("0x", count);
		ft_putnbr_ptr(address, count);
	}
	return (*count);
}

void	ft_putnbr(int n, int *count)
{
	if (n < 0)
	{
		if (n == -2147483648)
		{
			ft_putstr("-2147483648", count);
			return ;
		}
		ft_putchar('-', count);
		n *= -1;
	}
	if (n > 9)
		ft_putnbr(n / 10, count);
	ft_putchar("0123456789"[n % 10], count);
}

void	ft_putunbr(unsigned int n, int *count)
{
	if (n > 9)
		ft_putunbr(n / 10, count);
	ft_putchar("0123456789"[n % 10], count);
}

void	ft_puthex(unsigned int nbr, char c, int *count)
{
	if (nbr > 15)
	{
		ft_puthex(nbr / 16, c, count);
		ft_puthex(nbr % 16, c, count);
	}
	else
	{
		if (nbr < 10)
			ft_putchar(nbr + '0', count);
		else
		{
			if (c == 'x')
				ft_putchar(nbr - 10 + 'a', count);
			else
				ft_putchar(nbr - 10 + 'A', count);
		}
	}
}
