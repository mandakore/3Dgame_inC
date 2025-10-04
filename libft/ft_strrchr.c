/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atashiro <atashiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 13:11:46 by atashiro          #+#    #+#             */
/*   Updated: 2024/11/02 15:32:20 by atashiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while (i >= 0)
	{
		if (str[i] == (char)c)
			return ((char *)(str + i));
		i--;
	}
	return (0);
}

// #include <string.h>
// int main()
// {
// 	    char test[] = "aiueo";
//     printf("ft_strrchr  : %s\n", ft_strrchr(test, 'a'));
//     printf("strrchr : %s\n", strrchr(test, 'a'));
//     printf("ft_strrchr  : %s\n", ft_strrchr(test, 'i'));
//     printf("strrchr : %s\n", strrchr(test, 'i'));
//     printf("ft_strrchr  : %s\n", ft_strrchr(test, 'u'));
//     printf("strrchr : %s\n", strrchr(test, 'u'));
//     printf("ft_strrchr  : %s\n", ft_strrchr(test, 'e'));
//     printf("strrchr : %s\n", strrchr(test, 'e'));
//     printf("ft_strrchr  : %s\n", ft_strrchr(test, 'o'));
//     printf("strrchr : %s\n", strrchr(test, 'o'));
//     printf("ft_strrchr  : %s\n", ft_strrchr(test, 0));
//     printf("strrchr : %s\n", strrchr(test, 0));
//     printf("ft_strrchr  : %s\n", ft_strrchr(test, 1));
//     printf("strrchr : %s\n", strrchr(test, 1));
//     printf("ft_strrchr  : %s\n", ft_strrchr(test, 'z'));
//     printf("strrchr : %s\n", strrchr(test, 'z'));
// }
