/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardet- <lbardet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 00:26:11 by lbardet-          #+#    #+#             */
/*   Updated: 2026/05/11 04:46:52 by lbardet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fill_struct(t_data *data, char *line)
{
	int	i;
	int	j;

	j = 0;
	j = skip_space(line, j);
	i = j;
	while (line[i] && line[i] != ' ')
		i++;
	i = skip_space(line, i);
	if (line[j] == 'N' && line[j + 1] == 'O')
		data->no = ft_strdup(line + i);
	else if (line[j] == 'S' && line[j + 1] == 'O')
		data->so = ft_strdup(line + i);
	else if (line[j] == 'E' && line[j + 1] == 'A')
		data->ea = ft_strdup(line + i);
	else if (line[j] == 'W' && line[j + 1] == 'E')
		data->we = ft_strdup(line + i);
	else if (line[j] == 'F' && line[j + 1] == ' ')
		data->floor = stock_rgb(line + i);
	else if (line[j] == 'C' && line[j + 1] == ' ')
		data->ceiling = stock_rgb(line + i);
}

t_rgb	stock_rgb(char *line)
{
	t_rgb	rgb;

	rgb.r = ft_atoi(line);
	while (*line && *line != ',')
		line++;
	line++;
	rgb.g = ft_atoi(line);
	while (*line && *line != ',')
		line++;
	line++;
	rgb.b = ft_atoi(line);
	if (rgb.r < 0 || rgb.r > 255 || rgb.g < 0 || rgb.g > 255
		|| rgb.b < 0 || rgb.b > 255)
		exit(1);
	return (rgb);
}

char	*skip_to_path(char *line)
{
	int		i;
	int		j;
	char	*path;

	path = malloc(BUFFER_SIZE + 1);
	j = 0;
	i = 0;
	while (line[i] == ' ' && line[i])
		i++;
	while (line[i] != ' ' && line[i])
		i++;
	while (line[i] == ' ' && line[i])
		i++;
	while (line[i] != ' ' && line[i])
	{
		path[j] = line[i];
		i++;
		j++;
	}
	path[j] = '\0';
	return (path);
}

char	**extract_map(char **parsed_map)
{
	int		i;
	int		j;
	char	**map;

	i = 0;
	while (parsed_map[i] && i < 6)
		i++;
	map = malloc
		(sizeof(char *) * (ft_tablen((const char **)parsed_map) - i + 1));
	if (!map)
		return (NULL);
	j = 0;
	while (parsed_map[i])
	{
		map[j] = ft_strdup(parsed_map[i]);
		i++;
		j++;
	}
	map[j] = NULL;
	free(parsed_map);
	return (map);
}
