/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atashiro <atashiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:05:26 by atashiro          #+#    #+#             */
/*   Updated: 2024/11/09 02:46:04 by atashiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = s;
	while (i < n)
	{
		str[i] = c;
		i++;
	}
	return (s);
}

// #include <string.h>

// int main()
// {
//     char buffer[10] = "42Tokyo";
//     ft_memset(buffer, 'w', 5);
//     printf("%s\n", buffer);
// 	char buffer2[10] = "42Tokyo";
// 	memset(buffer2, 'w', 5);
// 	printf("%s\n", buffer2);
//     return (0);
// }