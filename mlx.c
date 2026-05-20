/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardet- <lbardet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 10:05:33 by lbardet-          #+#    #+#             */
/*   Updated: 2026/05/20 20:20:17 by lbardet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	mlx_load(t_data *data)
{
	data->win = mlx_new_window(data->mlx, 800, 600, "cub3D");
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bpp, &data->line_len,
			&data->endian);
}

void	init_screen(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (y < HEIGHT / 2)
				put_pixel(data, x, y, data->ceiling);
			else
				put_pixel(data, x, y, data->floor);
			x++;
		}
		y++;
	}
}

void	put_pixel(t_data *data, int x, int y, t_rgb color)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= WIDTH || y >= HEIGHT)
		return ;
	dst = data->addr
		+ (y * data->line_len)
		+ (x * (data->bpp / 8));
	*(unsigned int *)dst = rgb_to_int(color);
}

void	clear_image(t_data *data)
{
	ft_memset(data->addr, 0,
		HEIGHT * data->line_len);
}
