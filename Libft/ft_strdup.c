/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardet- <lbardet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 05:30:10 by lbardet-          #+#    #+#             */
/*   Updated: 2025/10/15 05:41:29 by lbardet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*s2;
	size_t	len;
	size_t	i;

	len = ft_strlen(s);
	i = 0;
	s2 = (char *)malloc((sizeof (char) * len) + 1);
	if (!s2)
		return (NULL);
	while (*s != 0)
		s2[i++] = *s++;
	s2[i] = 0;
	return (s2);
}

// int	main(void)
// {
// 	char	s[] = "TU CROIS T UN LION";
// 	printf("%s\n", ft_strdup(s));
// 	return (0);
// }