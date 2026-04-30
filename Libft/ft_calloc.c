/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardet- <lbardet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 02:34:38 by lbardet-          #+#    #+#             */
/*   Updated: 2025/10/16 16:59:57 by lbardet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = (void *)malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, (nmemb * size));
	return (ptr);
}

// int	main(void)
// {
// 	int	*tab;
// 	size_t	i;
// 	size_t	nmemb = 5;
// 	size_t	size = sizeof(int);
// 	tab = (int *)ft_calloc(nmemb, size);
// 	if (!tab)
// 		return (0);
// 	i = 0;
// 	while (i < nmemb)
// 	{
// 		printf ("%d\n", tab[i]);
// 		i++;
// 	}
// 	free(tab);
// 	return (0);
// }
