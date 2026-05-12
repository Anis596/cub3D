/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardet- <lbardet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 00:26:04 by lbardet-          #+#    #+#             */
/*   Updated: 2026/05/12 13:28:16 by lbardet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	checkmap_name(char *map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	i--;
	if (map[i] != 'b' || map[i - 1] != 'u'
		|| map[i - 2] != 'c' || map[i - 3] != '.')
		return (0);
	return (1);
}

int	parsing_map(t_data *data, t_textures *textures, t_player *player)
{
	int	i;

	i = 0;
	(void)textures;
	data->map = malloc(BUFFER_SIZE + 1);
	if (!data->map)
		exit(1);
	data->end = read(data->fd, data->map, BUFFER_SIZE);
	if (data->end <= 0)
		exit(1);
	data->map[data->end] = 0;
	data->parsed_map = ft_split(data->map, '\n');
	while (data->parsed_map[i] && i < 6)
	{
		fill_struct(data, data->parsed_map[i]);
		i++;
	}
	load_textures(textures, data);
	data->parsed_map = extract_map(data->parsed_map);
	if (!check_player(data, player) || !checkmandatories(data->parsed_map)
		|| !is_close_map(data->parsed_map))
		exit(1);
	return (1);
}

int	check_player(t_data *data, t_player *player)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	data->countcheck = 0;
	if (!data->parsed_map)
		return (0);
	while (data->parsed_map[j])
	{
		while (data->parsed_map[j][i])
		{
			if (data->parsed_map[j][i] == 'E' || data->parsed_map[j][i] == 'W'
				|| data->parsed_map[j][i] == 'S'
				|| data->parsed_map[j][i] == 'N')
				data->countcheck = player_init(data, player, i, j);
			i ++;
		}
		i = 0;
		j++;
	}
	if (data->countcheck == 1)
		return (1);
	return (0);
}

int	checkmandatories(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '0' && map[i][j] != 'N'
				&& map[i][j] != 'E' && map[i][j] != '1'
				&& map[i][j] != 'W' && map[i][j] != 'S'
				&& map[i][j] != ' ')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
