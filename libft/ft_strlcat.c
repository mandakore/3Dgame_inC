/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atashiro <atashiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:00:59 by atashiro          #+#    #+#             */
/*   Updated: 2024/11/16 04:24:36 by atashiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	s;
	size_t	d;
	size_t	dst_len;
	size_t	src_len;

	src_len = ft_strlen(src);
	if (!dst && size == 0)
		return (src_len);
	d = ft_strlen(dst);
	dst_len = d;
	if (size <= dst_len)
		return (size + src_len);
	s = 0;
	while (src[s] && d + 1 < size)
	{
		dst[d] = src[s];
		s++;
		d++;
	}
	dst[d] = '\0';
	return (dst_len + src_len);
}

// #include <string.h>
// #include <ctype.h>

// int main(void)
// {
// 	char str3[20] = "atashiro";
// 	char str4[20] = "atashiro";
// 	printf("ft_strlcat:%lu:%s\n", ft_strlcat(str3, "abcdef", 12), str3);
// 	printf("ft_strlcat:%lu:%s\n", ft_strlcat(str4, "abcdef", 5), str4);
// }