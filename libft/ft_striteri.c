/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atashiro <atashiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:56:47 by atashiro          #+#    #+#             */
/*   Updated: 2024/11/16 04:10:28 by atashiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (s != NULL && f != NULL)
	{
		i = 0;
		while (s[i])
		{
			(*f)(i, &s[i]);
			i++;
		}
	}
}

// void ft_putstr(unsigned int i, char *s)
// {
// 	(void)i;
// 	write(1, s, 1);
// }

// int main(void)
// {
// 	char str[] = "hello";
// 	ft_striteri(str, &ft_putstr);
// 	return 0;
// }