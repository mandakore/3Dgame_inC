/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atashiro <atashiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:05:54 by atashiro          #+#    #+#             */
/*   Updated: 2024/11/09 17:19:34 by atashiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		size_s1;

	if (!s1 || !set)
		return (NULL);
	while (ft_strchr(set, *s1) && *s1 != '\0')
		s1++;
	size_s1 = ft_strlen((char *)s1);
	while (ft_strchr(set, s1[size_s1]) && size_s1 != 0)
		size_s1--;
	return (ft_substr((char *)s1, 0, size_s1 + 1));
}

// #include <string.h>
// #include <ctype.h>

// int main(void)
// {
// 	char *test1;
// 	char *test2;
// 	char *test3;
// 	char *test4;
// 	char *test5;
// 	char *test6;
// 	test1 = ft_strtrim("kkkkkkkkkkatashirokkkkkkk", "k");
// 	test2 = ft_strtrim("    atashiro", " ");
// 	test3 = ft_strtrim("atashiro", "atashiro");
// 	test4 = ft_strtrim(0, "abc");
// 	test5 = ft_strtrim("abc", 0);
// 	test6 = ft_strtrim("atashiro", "\0");
// 	printf("ft_strtrim(\"atashiro\", \"sh\"):%s\n", test1);
// 	printf("ft_strtrim(\"atashiro\", \"kk\"):%s\n", test2);
// 	printf("ft_strtrim(\"atashiro\", \"atashiro\"):%s\n", test3);
// 	printf("ft_strtrim(0, \"abc\"):%s\n", test4);
// 	printf("ft_strtrim(\"abc\", 0):%s\n", test5);
// 	printf("ft_strtrim(\"atashiro\", \"\\0\"):%s\n", test6);

// 	free(test1);
// 	free(test2);
// 	free(test3);
// 	free(test4);
// 	free(test5);
// 	free(test6);
// }