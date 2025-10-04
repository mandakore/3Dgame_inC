/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atashiro <atashiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 13:12:30 by atashiro          #+#    #+#             */
/*   Updated: 2024/11/13 14:32:37 by atashiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((s1[i] || s2[i]) && (i < n))
	{
		if (s1[i] != s2[i])
			return (((unsigned char)s1[i] - (unsigned char)s2[i]));
		i++;
	}
	return (0);
}

// #include <string.h>
// #include <ctype.h>

// int main(void)
// {
// 	printf("strncmp:%d\n", strncmp("1234", "1235", 3));
// 	printf("ft_strncmp:%d\n", ft_strncmp("1234", "1235", 3));
// }