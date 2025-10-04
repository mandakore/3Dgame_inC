/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atashiro <atashiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 13:14:40 by atashiro          #+#    #+#             */
/*   Updated: 2024/11/17 17:01:12 by atashiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	i2;
	size_t	n_len;
	char	*s1_a;

	i = 0;
	i2 = 0;
	if ((s1 == NULL || s2 == NULL) && len == 0)
		return (NULL);
	s1_a = (char *)s1;
	n_len = ft_strlen(s2);
	if (n_len == 0 || s1 == s2)
		return (s1_a);
	while (s1_a[i] != '\0' && i < len)
	{
		while (s1_a[i + i2] && s2[i2] && s1_a[i + i2] == s2[i2] && i + i2 < len)
			i2++;
		if (i2 == n_len)
			return (s1_a + i);
		i++;
	}
	return (0);
}

// int main(void)
// {
// 	printf("%s\n", ft_strnstr("atashiro", "sh", 0));
// 	printf("%s\n", ft_strnstr("atashiro", "", 10));
// }