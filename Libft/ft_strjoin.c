/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardet- <lbardet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 06:21:52 by lbardet-          #+#    #+#             */
/*   Updated: 2025/10/15 06:50:53 by lbardet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_strcat(char *s1, char const *s2)
{
	size_t	i;

	i = ft_strlen(s1);
	while (*s2)
		s1[i++] = *s2++;
	s1[i] = 0;
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	mallocsize;
	char	*s3;

	mallocsize = (ft_strlen(s1) + ft_strlen(s2));
	s3 = (char *)malloc(sizeof (char) * (mallocsize + 1));
	if (!s3)
		return (NULL);
	s3[0] = 0;
	ft_strcat(s3, s1);
	ft_strcat(s3, s2);
	return (s3);
}

// int main(void)
// {
// 	printf("%s\n", ft_strjoin("JE VAIS ", "TRES BIEN"));
// 	return (0);
// }