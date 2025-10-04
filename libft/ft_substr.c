/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atashiro <atashiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 11:15:17 by atashiro          #+#    #+#             */
/*   Updated: 2024/11/17 16:38:53 by atashiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*result;
	size_t	str_len;
	size_t	fin_len;

	if (!str)
		return (0);
	str_len = ft_strlen(str);
	fin_len = 0;
	if (start < str_len)
		fin_len = str_len - start;
	if (fin_len > len)
		fin_len = len;
	result = (char *)malloc(sizeof(char) * (fin_len + 1));
	if (!result)
		return (0);
	if (start > str_len)
		result[0] = '\0';
	else
		ft_strlcpy(result, str + start, fin_len + 1);
	return (result);
}

// #include <string.h>
// #include <ctype.h>

// int main(void)
// {
// 	char *s1;
// 	char *s2;
// 	char *s3;
// 	char *s4;
// 	s1 = ft_substr("atashiro", 2, 3);
// 	s2 = ft_substr("atashiro", 2, 20);
// 	s3 = ft_substr("atashiro", 7, 5);
// 	s4 = ft_substr(0, 5, 5);
// 	printf("ft_substr(\"atashiro\", 2, 3):%s\n", s1);
// 	printf("ft_substr(\"atashiro\", 2, 20):%s\n", s2);
// 	printf("ft_subsrr(\"atashiro\", 7, 5):%s\n", s3);
// 	printf("ft_substr(0, 5, 5):%s\n", s4);

// 	free(s1);
// 	free(s2);
// 	free(s3);
// 	free(s4);
// }