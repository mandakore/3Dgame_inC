/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atashiro <atashiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:57:32 by atashiro          #+#    #+#             */
/*   Updated: 2024/11/02 17:09:21 by atashiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	ft_putstr_fd(s, fd);
	write(fd, "\n", 1);
}

// #include <stdio.h>
// #include <string.h>
// #include <ctype.h>
// #include "libft.h"

// int	main()
// {
// 	ft_putendl_fd("atashiro", 1);
// 	write(1, "\n", 1);

// 	write(1, "NULL", ft_strlen("NULL"));
// 	ft_putendl_fd(0, 1);
// 	write(1, "\n", 1);
// }
