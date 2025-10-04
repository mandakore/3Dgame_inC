/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atashiro <atashiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:56:40 by atashiro          #+#    #+#             */
/*   Updated: 2024/11/09 17:32:58 by atashiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	size_t	size;
	char	*dest;

	size = ft_strlen(src);
	dest = (char *)malloc(size * sizeof(char) + 1);
	if (dest == NULL)
		return (0);
	ft_memcpy(dest, src, size);
	dest[size] = '\0';
	return (dest);
}

// #include <string.h>
// #include <ctype.h>

// int main(void)
// {
// 	char *test1;
// 	test1 = strdup("atashiro");
// 	printf("strdup:%s\n", test1);
// 	free(test1);

// 	char *test2;
// 	test2 = ft_strdup("atashiro");
// 	printf("ft_strdup:%s\n", test2);
// 	free(test2);

// 	system("leaks a.out");
// }