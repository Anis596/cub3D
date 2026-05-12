/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardet- <lbardet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 00:12:10 by lbardet-          #+#    #+#             */
/*   Updated: 2026/05/12 13:57:30 by lbardet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_data		*data;
	t_textures	*textures;
	t_player	*player;

	if (ac != 2 || !checkmap_name(av[1]))
		return (printf("Error: arguments"), 1);
	textures = malloc(sizeof(t_textures));
	data = malloc(sizeof(t_data));
	player = malloc(sizeof(t_player));
	data->mlx = mlx_init();
	if (!data->mlx || !textures || !data || !player)
		exit(1);
	data->fd = open(av[1], O_RDONLY);
	if (data->fd < 0)
		exit (1);
	parsing_map(data, textures, player);
	data->parsed_map[(int)player->pos_y][(int)player->pos_x] = '0';
	data->textures = *textures;
	mlx_load(data);
	raycast(player, data);
	mlx_hook(data->win, 2, 1L << 0, key_hook, data);
	mlx_hook(data->win, 17, 0, close_window, data);	
	mlx_loop(data->mlx);
	return (0);
}
