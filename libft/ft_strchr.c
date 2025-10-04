/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atashiro <atashiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 13:11:33 by atashiro          #+#    #+#             */
/*   Updated: 2024/11/13 20:44:08 by atashiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while ((char)c != *s)
	{
		if (!*s)
			return (0);
		s++;
	}
	return ((char *)s);
}

// #include <string.h>
// #include <ctype.h>

// int main(void)
// {
// 	printf("strchr:%s\n", strchr("atashiro", 's'));
// 	printf("ft_strchr:%s\n", ft_strchr("atashiro", 's'));
// }