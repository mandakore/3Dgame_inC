/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atashiro <atashiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 11:23:53 by atashiro          #+#    #+#             */
/*   Updated: 2024/11/13 20:24:38 by atashiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*s1_c;
	const unsigned char	*s2_c;
	size_t				i;

	s1_c = (const unsigned char *)s1;
	s2_c = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (s1_c[i] == s2_c[i])
			i++;
		else
			return (s1_c[i] - s2_c[i]);
	}
	return (0);
}

// int	main()
// {
// 	char	*str1 = "Tokyo";
// 	char	*str2 = "Tokyu";

// 	printf("%d",ft_memcmp(str1, str2, 5));
// }