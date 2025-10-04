/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atashiro <atashiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:56:11 by atashiro          #+#    #+#             */
/*   Updated: 2024/11/02 16:53:22 by atashiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	length;
	char			*result;

	if (!s)
		return (NULL);
	length = ft_strlen(s);
	result = malloc(length * sizeof(char) + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (i < length)
	{
		result[i] = (*f)(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}

// #include <string.h>
// #include <ctype.h>

// char	a_toupper(unsigned int n, char c)
// {
// 	if (n < 42)
// 	{
// 		if (97 <= c && c <= 122)
// 			return (c - 32);
// 	}
// 	return (c);
// }

// int main(void)
// {
// 	char *str1;
// 	char (*f)(unsigned int, char);
// 	f = a_toupper;
// 	printf("ft_strmapi(\"atsuyatashiro\", f):");
// 	str1 = ft_strmapi("atsuyatashiro", f);
// 	printf("%s\n", str1);
// 	free(str1);

// 	char *str2;
// 	str2 = ft_strmapi(0, f);
// 	printf("ft_strmapi(0, f):%s\n", str2);
// 	free(str2);
// }