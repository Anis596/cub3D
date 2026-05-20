/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardet- <lbardet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 00:12:10 by lbardet-          #+#    #+#             */
/*   Updated: 2026/05/20 20:56:36 by lbardet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_data		*data;
	t_textures	*textures;

	if (ac != 2 || !checkmap_name(av[1]))
		return (printf("Error: arguments"), 1);
	data = ft_calloc(1, sizeof(t_data));
	textures = ft_calloc(1, sizeof(t_textures));
	if (!data || !textures)
	{
		free(data);
		free(textures);
		return (1);
	}
	data->mlx = mlx_init();
	if (!data->mlx)
	{
		free(data);
		free(textures);
		return (printf("Error: MLX initialization failed\n"), 1);
	}
	data->fd = open(av[1], O_RDONLY);
	if (data->fd < 0)
	{
		free_mlx_ptr(data);
		free(data);
		free(textures);
		return (printf("Error: Cannot open map file\n"), 1);
	}
	parsing_map(data, textures, &data->player);
	data->textures = *textures;
	free(textures);
	mlx_load(data);
	raycast(&data->player, data);
	mlx_hook(data->win, 2, 1L<<0, key_hook, data);
	mlx_hook(data->win, 17, 0, close_window, data);
	mlx_loop(data->mlx);
}
