/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardet- <lbardet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 05:08:21 by lbardet-          #+#    #+#             */
/*   Updated: 2025/10/14 07:21:26 by lbardet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;

	src_len = ft_strlen(src);
	if (size > 0)
	{
		while (*src != 0 && (size - 1) > 0)
		{
			*dst++ = *src++;
			size--;
		}
		*dst = 0;
	}
	return (src_len);
}

// int main(void)
// {
// 	char dest[100] = "aaa";
// 	const char src[100] = ";lbk;blkb;l";
// 	ft_strlcpy(dest, src, 1);
// 	printf("%s\n", dest);
// 	return(0);
// }