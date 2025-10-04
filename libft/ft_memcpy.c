/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atashiro <atashiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 21:12:43 by atashiro          #+#    #+#             */
/*   Updated: 2024/11/13 20:28:41 by atashiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dest && !src)
		return (NULL);
	if (dest != src)
	{
		while (i < n)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (dest);
}

// #include <string.h>
// #include <stdlib.h>

// void	print_test_result(int test_number, int result)
// {
// 	if (result)
// 		printf("Test %d: Passed\n", test_number);
// 	else
// 		printf("Test %d: Failed\n", test_number);
// }

// void	test_ft_memcpy()
// {
// 	char dest[50];
// 	const char src[] = "Hello, World!";
// 	size_t n;

// 	n = 13;
// 	ft_memcpy(dest, src, n);
// 	dest[n] = '\0';
// 	print_test_result(1, strcmp(dest, "Hello, World!") == 0);
// }

// int main()
// {
// 	test_ft_memcpy();
// 	return 0;
// }