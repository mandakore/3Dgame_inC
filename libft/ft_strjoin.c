/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atashiro <atashiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:57:06 by atashiro          #+#    #+#             */
/*   Updated: 2024/11/16 04:15:03 by atashiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	result = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!result)
		return (NULL);
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		result[i] = s2[j];
		i++;
		j++;
	}
	result[i] = '\0';
	return (result);
}

// #include <string.h>
// #include <ctype.h>

// int main(void)
// {
// 	char *test1;
// 	char *test2;
// 	test1 = ft_strjoin("atashiro", "abcdef");
// 	test2 = ft_strjoin(0, "abcdef");
// 	printf("ft_strjoin(atashiro, abcdef):%s\n", test1);
// 	printf("ft_strjoin(0, abcdef):%s\n", test2);
// 	free(test1);
// 	free(test2);
// }