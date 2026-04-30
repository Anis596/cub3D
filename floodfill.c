/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardet- <lbardet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 04:43:50 by lbardet-          #+#    #+#             */
/*   Updated: 2026/04/30 05:18:59 by lbardet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_close_map(char **map)
{
	char	**copy;
	int		x;
	int		y;

	y = 0;
	x = 0;
	copy = ft_tabcopy(map);
	if (!copy)
		return (0);
	while (copy[y])
	{
		x = 0;
		while (copy[y][x])
		{
			if (copy[y][x] == 'N' || copy[y][x] == 'S'
				|| copy[y][x] == 'E' || copy[y][x] == 'W')
				break ;
			x++;
		}
		if (copy[y][x] != '\0')
			break ;
		y++;
	}
	return (close_or_not(copy, x, y));
}

int	close_or_not(char **map, int x, int y)
{
	if (!flood_fill(x, y, map))
	{
		ft_freetab(map);
		return (0);
	}
	ft_freetab(map);
	return (1);
}

int	flood_fill(int x, int y, char **map)
{
	if (!map || !map[y] || x < 0 || y < 0)
		return (0);
	if ((size_t)x >= ft_strlen(map[y]))
		return (0);
	if (map[y][x] == ' ')
		return (0);
	if (map[y][x] == '1' || map[y][x] == 'F')
		return (1);
	map[y][x] = 'F';
	if (!flood_fill(x + 1, y, map)
		|| !flood_fill(x - 1, y, map)
		|| !flood_fill(x, y + 1, map)
		|| !flood_fill(x, y - 1, map))
		return (0);
	return (1);
}
