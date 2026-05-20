/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardet- <lbardet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 20:57:13 by lbardet-          #+#    #+#             */
/*   Updated: 2026/05/20 20:57:13 by lbardet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_parsed_map(char **parsed_map)
{
	int	i;

	if (!parsed_map)
		return ;
	i = 0;
	while (parsed_map[i])
	{
		free(parsed_map[i]);
		i++;
	}
	free(parsed_map);
}

void	free_textures(t_data *data)
{
	if (!data || !data->mlx)
		return ;
	if (data->textures.no.img)
		mlx_destroy_image(data->mlx, data->textures.no.img);
	if (data->textures.so.img)
		mlx_destroy_image(data->mlx, data->textures.so.img);
	if (data->textures.ea.img)
		mlx_destroy_image(data->mlx, data->textures.ea.img);
	if (data->textures.we.img)
		mlx_destroy_image(data->mlx, data->textures.we.img);
}

void	free_strings(t_data *data)
{
	if (!data)
		return ;
	if (data->no)
		free(data->no);
	if (data->so)
		free(data->so);
	if (data->ea)
		free(data->ea);
	if (data->we)
		free(data->we);
	if (data->map)
		free(data->map);
}

void	free_mlx(t_data *data)
{
	if (!data || !data->mlx)
		return ;
	if (data->fd > 0)
		close(data->fd);
	if (data->img)
		mlx_destroy_image(data->mlx, data->img);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
}