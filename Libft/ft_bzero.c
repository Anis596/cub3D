/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardet- <lbardet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 03:06:50 by lbardet-          #+#    #+#             */
/*   Updated: 2025/10/16 16:59:58 by lbardet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*str;
	size_t			i;

	i = 0;
	str = (unsigned char *)s;
	while (i < n)
		str[i++] = 0;
}

// int	main(void)
// {
// 	char	str[] = "afa54984654";
// 	size_t	n = 5;
// 	ft_bzero(str, n);
// 	printf("%s\n", str);
// 	write (1, &str[6], 1);
// 	return (0);
// }
