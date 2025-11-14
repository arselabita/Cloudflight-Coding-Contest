/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 18:47:51 by yhirai            #+#    #+#             */
/*   Updated: 2023/06/01 15:38:27 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
//#include "libft.h"

static size_t	count_words(char const *str, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] == c)
			i++;
		if (str[i] != '\0')
			count++;
		while (str[i] != '\0' && str[i] != c)
			i++;
	}
	return (count);
}

static size_t	characters_count(char const *str, char c)
{
	size_t	count;
	size_t	i;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		while (str[i] == c)
			i++;
		while (str[i] != '\0' && str[i] != c)
		{
			count++;
			i++;
		}
	}
	return (count);
}

static void	ft_free(char **all_strings)
{
	int	i;

	i = 0;
	while (all_strings[i] != NULL)
	{
		free(all_strings[i]);
		i++;
	}
	free(all_strings);
}

static char	*get_words(char const *str, char c, char **all_strings)
{
	char	*word;
	size_t	k;
	size_t	i;

	i = 0;
	word = malloc(sizeof(char) * (characters_count(str, c) + 1));
	if (word == NULL)
	{
		ft_free(all_strings);
		return (NULL);
	}
	k = 0;
	while (str[i] != '\0' && str[i] != c)
	{
		word[k] = str[i];
		i++;
		k++;
	}
	word[k] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	size_t		j;
	char		**all_strings;
	size_t		wc;

	if (s == NULL)
		return (NULL);
	j = 0;
	wc = count_words(s, c);
	all_strings = (char **)calloc(sizeof(char *), wc + 1);
	if (all_strings == NULL)
		return (NULL);
	while (j < wc && *s != '\0')
	{
		while (*s == c)
			s++;
		if (*s != c)
		{
			all_strings[j] = get_words(s, c, all_strings);
			if (all_strings[j++] == NULL)
				return (NULL);
		}
		while (*s != '\0' && *s != c)
			s++;
	}
	return (all_strings);
}

// #include <libc.h>
// int main(void)
// {
// 	char **s = ft_split(" sfg gd  dgd", ' ');
// 	char **tmp = s;
// 	while (*s)
// 		free(*s++);
// 	free(tmp);
// }

// #include "libft.h"
// int	main(void)
// {
// 	char	**ans;
// 	char *expected[] = {"hello","world","42","tokyo", NULL};
// 	int		i;

// 	i = 0;
// 	ans = ft_split("hello world 42 tokyo", ' ');
// 	while (ans[i] != '\0')
// 	{
// 		printf("%d: %s\n", i, ans[i]);
// 		printf("%d: %d\n", i, ft_strncmp(ans[i],
// expected[i],ft_strlen(expected[i])));
// 		i++;
// 	}
// 	return (0);
// }
