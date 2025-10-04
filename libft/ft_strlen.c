/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atashiro <atashiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:05:29 by atashiro          #+#    #+#             */
/*   Updated: 2024/11/02 16:14:11 by atashiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

// #include <string.h>

// int main (void)
// {
// 	char str[] = "42Tokyo *@(?/\\";

// 	printf("%zu\n", ft_strlen(str));
// 	printf("%lu\n", strlen(str));
// 	return (0);
// }