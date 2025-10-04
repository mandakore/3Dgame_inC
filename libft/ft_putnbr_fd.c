/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atashiro <atashiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 13:30:09 by atashiro          #+#    #+#             */
/*   Updated: 2024/11/01 16:45:36 by atashiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			write(fd, "-", 1);
			n *= -1;
		}
		if (n > 9)
			ft_putnbr_fd(n / 10, fd);
		write(fd, &"0123456789"[n % 10], 1);
	}
}

// int	main()
// {
// 	ft_putnbr_fd(-2147483648,1);
// 	write(1, "\n", 1);
// 	ft_putnbr_fd(42,1);
// 	write(1, "\n", 1);
// 	ft_putnbr_fd(0,1);
// 	write(1, "\n", 1);
// 	ft_putnbr_fd(-42,1);
// 	write(1, "\n", 1);
// 	ft_putnbr_fd(2147483647,1);
// 	write(1, "\n", 1);
// }