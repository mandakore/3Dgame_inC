/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atashiro <atashiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 18:49:57 by atashiro          #+#    #+#             */
/*   Updated: 2024/11/22 19:55:06 by atashiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_ptr(unsigned long long address, int *count)
{
	if (address > 15)
	{
		ft_putnbr_ptr(address / 16, count);
		ft_putnbr_ptr(address % 16, count);
	}
	else
	{
		if (address < 10)
			ft_putchar(address + '0', count);
		else
			ft_putchar(address - 10 + 'a', count);
	}
}
