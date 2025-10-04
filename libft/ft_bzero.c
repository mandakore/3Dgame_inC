/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atashiro <atashiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 19:33:17 by atashiro          #+#    #+#             */
/*   Updated: 2024/11/09 17:43:06 by atashiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*str;

	str = s;
	i = 0;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}

// #include <string.h>
// int	main()
// {
// 	printf("[ft_bzero]\n");
// 	char test1[50];
// 	strcpy(test1, "12345678");
// 	ft_bzero(test1, 1);
// 	printf("(%s)\n", test1);
// 	printf("\n");
// 	printf("[bzero]\n");
// 	char test2[51];
// 	strcpy(test2, "12345678");
// 	bzero(test2, 1);
// 	printf("(%s)\n", test2);
// }