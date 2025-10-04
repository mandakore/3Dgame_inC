/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atashiro <atashiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:16:19 by atashiro          #+#    #+#             */
/*   Updated: 2024/10/25 21:01:49 by atashiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		c -= 32;
	return (c);
}

// #include <ctype.h>

// int main(void)
// {
// 	printf("%d\n",ft_toupper('b'));
// 	printf("%d\n",toupper('b'));
// }