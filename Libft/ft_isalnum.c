/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardet- <lbardet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 02:05:08 by lbardet-          #+#    #+#             */
/*   Updated: 2025/10/14 06:50:34 by lbardet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((!(ft_isdigit(c))) && (!ft_isalpha(c)))
		return (0);
	return (1);
}

// int	main(void)
// {
// 	if (!ft_isalnum('o'))
// 		printf("asdas");
// 	return (0);
// }
