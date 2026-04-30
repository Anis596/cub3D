/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardet- <lbardet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 07:17:02 by lbardet-          #+#    #+#             */
/*   Updated: 2025/10/17 20:11:32 by lbardet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char *str, char charset)
{
	int	count;
	int	pos;

	pos = 0;
	count = 0;
	while (str[pos])
	{
		while (str[pos] == charset)
			pos++;
		if (str[pos])
		{
			count++;
			while (str[pos] && str[pos] != charset)
				pos++;
		}
	}
	return (count);
}

static char	*malloc_word(char *str, char charset, int i)
{
	int		start;
	int		end;
	char	*word;
	int		j;

	j = 0;
	start = i;
	while (str[i] != charset && str[i])
		i++;
	end = i;
	word = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!word)
		return (NULL);
	while (start < end)
		word[j++] = str[start++];
	word[j] = '\0';
	return (word);
}

static char	**bigfree(char **tab, int jcrochet)
{
	while (jcrochet >= 0)
	{
		free(tab[jcrochet]);
		jcrochet--;
	}
	free(tab);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		jcrochet;
	char	**tab;
	int		i;
	int		word_count;

	i = 0;
	jcrochet = 0;
	word_count = count_words((char *)s, c);
	tab = malloc(sizeof(char *) * (word_count + 1));
	if (!tab)
		return (NULL);
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
		{
			tab[jcrochet] = malloc_word((char *)s, c, i);
			if (!tab[jcrochet])
				return (bigfree(tab, jcrochet - 1));
			jcrochet++;
		}
		i++;
	}
	tab[jcrochet] = NULL;
	return (tab);
}

// int	main(void)
// {
// 	char **tab;
// 	int i = 0;
// 	tab = ft_split("hello!", ' ');
// 	while (tab[i])
// 	{
// 		printf("%s\n", tab[i]);
// 		i++;
// 	}
// 	return (0);
// }