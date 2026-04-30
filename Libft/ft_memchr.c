/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardet- <lbardet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 09:50:14 by lbardet-          #+#    #+#             */
/*   Updated: 2025/10/15 05:56:50 by lbardet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *)s;
	while (n--)
	{
		if (*str == (unsigned char)c)
			return (str);
		str++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	void	*s = "TU CROIS T UN LION";
// 	unsigned char	*str;

// 	str = (unsigned char *) ft_memchr(s, 76, 20);
// 	printf ("%s\n", str);
// 	return (0);
// }
