/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardet- <lbardet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 00:12:10 by lbardet-          #+#    #+#             */
/*   Updated: 2026/05/03 11:55:31 by lbardet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_data		*data;
	t_textures	*textures;

	data = NULL;
	textures = NULL;
	if (ac != 2 || !checkmap_name(av[1]))
		return (printf("Error: arguments"), 1);
	textures = malloc(sizeof(t_textures));
	data = malloc(sizeof(t_data));
	data->mlx = mlx_init();
	if (!data->mlx || !textures || !data)
		exit(1);
	data->fd = open(av[1], O_RDONLY);
	if (data->fd < 0)
		exit (1);
	parsing_map(data, textures);
	return (0);
}
