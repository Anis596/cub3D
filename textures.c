/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardet- <lbardet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 11:06:14 by lbardet-          #+#    #+#             */
/*   Updated: 2026/05/20 20:51:18 by lbardet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	load_textures_no(t_textures *textures, t_data *data)
{
	textures->no.img = mlx_xpm_file_to_image(data->mlx, data->no,
			&textures->no.width, &textures->no.height);
	if (!textures->no.img)
		clean_exit_error(data, 1, "Cannot load NO texture");
	textures->no.addr = mlx_get_data_addr(textures->no.img, &textures->no.bpp,
			&textures->no.line_len, &textures->no.endian);
	if (!textures->no.addr)
		clean_exit_error(data, 1, "Cannot get data from NO texture");
}

static void	load_textures_so(t_textures *textures, t_data *data)
{
	textures->so.img = mlx_xpm_file_to_image(data->mlx, data->so,
			&textures->so.width, &textures->so.height);
	if (!textures->so.img)
		clean_exit_error(data, 1, "Cannot load SO texture");
	textures->so.addr = mlx_get_data_addr(textures->so.img, &textures->so.bpp,
			&textures->so.line_len, &textures->so.endian);
	if (!textures->so.addr)
		clean_exit_error(data, 1, "Cannot get data from SO texture");
}

static void	load_textures_ea(t_textures *textures, t_data *data)
{
	textures->ea.img = mlx_xpm_file_to_image(data->mlx, data->ea,
			&textures->ea.width, &textures->ea.height);
	if (!textures->ea.img)
		clean_exit_error(data, 1, "Cannot load EA texture");
	textures->ea.addr = mlx_get_data_addr(textures->ea.img, &textures->ea.bpp,
			&textures->ea.line_len, &textures->ea.endian);
	if (!textures->ea.addr)
		clean_exit_error(data, 1, "Cannot get data from EA texture");
}

static void	load_textures_we(t_textures *textures, t_data *data)
{
	textures->we.img = mlx_xpm_file_to_image(data->mlx, data->we,
			&textures->we.width, &textures->we.height);
	if (!textures->we.img)
		clean_exit_error(data, 1, "Cannot load WE texture");
	textures->we.addr = mlx_get_data_addr(textures->we.img, &textures->we.bpp,
			&textures->we.line_len, &textures->we.endian);
	if (!textures->we.addr)
		clean_exit_error(data, 1, "Cannot get data from WE texture");
}

void	load_textures(t_textures *textures, t_data *data)
{
	load_textures_no(textures, data);
	load_textures_so(textures, data);
	load_textures_ea(textures, data);
	load_textures_we(textures, data);
}
