/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atashiro <atashiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 11:16:40 by atashiro          #+#    #+#             */
/*   Updated: 2024/11/13 14:03:00 by atashiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ptr;
	size_t				i;

	ptr = (const unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == (unsigned char)c)
			return ((void *)&ptr[i]);
		i++;
	}
	return (NULL);
}

// #include <string.h>

// int	main(void)
// {
// 	char   *s = "atashiro";
// 	int   c = 'r';
// 	size_t   n = 10;

// 	printf("ft_memchr: %p\n", ft_memchr(s, c, n));
// 	printf("memchr: %p\n", memchr(s, c, n));
// }