/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardet- <lbardet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 05:57:45 by lbardet-          #+#    #+#             */
/*   Updated: 2025/10/17 20:19:41 by lbardet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strnlen(char *s, int start)
{
	int	a;

	a = 0;
	while (s[start])
	{
		a++;
		start++;
	}
	return (a);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*s2;
	char	*result;

	if (!s)
		return (NULL);
	if (len > ft_strnlen((char *)s, start))
		len = ft_strnlen((char *)s, start);
	if (start >= ft_strlen(s))
		len = 0;
	s2 = (char *)malloc((sizeof (char) * len) + 1);
	if (!s2)
		return (NULL);
	result = s2;
	while (start-- && *s)
		s++;
	while (len-- && *s)
		*s2++ = *s++;
	*s2 = 0;
	return (result);
}

// int	main(void)
// {
// 	char const *s = "TU CROIS T UN LION";
// 	char	*s1 = ft_substr(s, 4, 7);
// 	printf ("%s\n", s1);
// 	return (0);
// }
