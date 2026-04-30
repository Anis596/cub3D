/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabcopy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardet- <lbardet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 04:46:57 by lbardet-          #+#    #+#             */
/*   Updated: 2026/04/30 05:20:05 by lbardet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tabcopy(char **tab)
{
	char	**copy;
	size_t	i;

	if (!tab)
		return (NULL);
	copy = ft_calloc(ft_tablen((const char **)tab) + 1, sizeof(char *));
	if (!copy)
		return (NULL);
	i = 0;
	while (tab[i])
	{
		copy[i] = ft_strdup(tab[i]);
		if (!copy[i])
		{
			ft_freetab(copy);
			return (NULL);
		}
		i++;
	}
	return (copy);
}
