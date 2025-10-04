/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atashiro <atashiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 21:12:46 by atashiro          #+#    #+#             */
/*   Updated: 2024/11/13 20:20:57 by atashiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t number, size_t size)
{
	void	*b;
	size_t	total_size;

	total_size = number * size;
	if (number && ((total_size / number) != size))
		return (NULL);
	b = malloc(total_size);
	if (!b)
		return (NULL);
	ft_bzero(b, total_size);
	return (b);
}

// int main(void)
// {
// 	int	*calloc_test;
// 	calloc_test = (int *)ft_calloc(1, sizeof(int));
// 	for(int i = 0; i < 10; i++)
// 		printf("%d ", calloc_test[i]);
// 	printf("\n");
// 	free(calloc_test);
// }