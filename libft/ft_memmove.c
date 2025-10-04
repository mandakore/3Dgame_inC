/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atashiro <atashiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:07:40 by atashiro          #+#    #+#             */
/*   Updated: 2024/11/16 03:46:44 by atashiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*source;
	char		*dest;

	source = (char *)src;
	dest = (char *)dst;
	if (source < dest)
	{
		while (len > 0)
		{
			len--;
			dest[len] = source[len];
		}
	}
	else
		ft_memcpy(dest, source, len);
	return (dst);
}

// #include <string.h>

// int main(void)
// {
// 	char str1[50];
// 	char str2[50] = "atashiro";
// 	char *result;
// 	result = ft_memmove(str1, str2, 3);
// 	str1[3] = '\0';
// 	printf("%s\n", result);

// 	char str3[50];
// 	char str4[50] = "atashiro";
// 	char *result2;
// 	result2 = memmove(str3, str4, 3);
// 	str3[3] = '\0';
// 	printf("%s", result2);
// 	return (0);
// }