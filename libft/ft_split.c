/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atashiro <atashiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:56:35 by atashiro          #+#    #+#             */
/*   Updated: 2024/11/16 04:04:58 by atashiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *str, char sep)
{
	int	i;
	int	word_count;

	i = 0;
	word_count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == sep)
			i++;
		else
		{
			word_count++;
			while (str[i] && str[i] != sep)
				i++;
		}
	}
	return (word_count);
}

static char	*ft_putword(char *word, char const *s, int i, int word_len)
{
	int	j;

	j = 0;
	while (word_len > 0)
	{
		word[j] = s[i - word_len];
		j++;
		word_len--;
	}
	word[j] = '\0';
	return (word);
}

static char	**free_array(char **ptr)
{
	int	i;

	i = 0;
	if (ptr)
	{
		while (ptr[i] != NULL)
		{
			free(ptr[i]);
			i++;
		}
		free(ptr);
	}
	return (0);
}

static char	**ft_split_words(char const *s, char c, char **s2, int num_words)
{
	int	i;
	int	word;
	int	word_len;

	i = 0;
	word = 0;
	word_len = 0;
	while (word < num_words)
	{
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			i++;
			word_len++;
		}
		s2[word] = (char *)malloc(sizeof(char) * (word_len + 1));
		if (!s2)
			return (free_array(s2));
		ft_putword(s2[word], s, i, word_len);
		word_len = 0;
		word++;
	}
	s2[word] = 0;
	return (s2);
}

char	**ft_split(char const *s, char c)
{
	char			**s2;
	unsigned int	num_words;

	if (!s)
		return (0);
	num_words = ft_count_words(s, c);
	s2 = (char **)malloc(sizeof(char *) * (num_words + 1));
	if (!s2)
		return (0);
	s2 = ft_split_words(s, c, s2, num_words);
	return (s2);
}

// #include <stdio.h>
// #include <stdlib.h>

// void	print_split_result(char **result)
// {
// 	int i = 0;

// 	while (result[i] != NULL)
// 	{
// 		printf("Word %d: %s\n", i, result[i]);
// 		i++;
// 	}
// }

// int	main(void)
// {
// 	char **result;
// 	char *str = "Hello,World,This,is,a,test";
// 	char sep = ',';

// 	result = ft_split(str, sep);
// 	if (!result)
// 	{
// 		printf("Error: Memory allocation failed\n");
// 		return (1);
// 	}

// 	print_split_result(result);

// 	int i = 0;
// 	while (result[i] != NULL)
// 	{
// 		free(result[i]);
// 		i++;
// 	}
// 	free(result);

// 	return (0);
// }