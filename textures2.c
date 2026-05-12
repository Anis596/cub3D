/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardet- <lbardet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 13:06:25 by lbardet-          #+#    #+#             */
/*   Updated: 2026/05/12 13:06:25 by lbardet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_walls	*select_texture(t_ray *r, t_textures *tex)
{
	if (r->side == 0)
	{
		if (r->step_x > 0)
			return (&tex->ea);
		return (&tex->we);
	}
	else
	{
		if (r->step_y > 0)
			return (&tex->so);
		return (&tex->no);
	}
}

double	get_wall_x(t_player *p, t_ray *r, double perp_dist)
{
	double	wall_x;

	if (r->side == 0)
		wall_x = p->pos_y + perp_dist * r->dir_y;
	else
		wall_x = p->pos_x + perp_dist * r->dir_x;
	wall_x -= floor(wall_x);
	return (wall_x);
}

unsigned int	get_texture_pixel(t_walls *tex, int x, int y)
{
	char	*dst;

	dst = tex->addr
		+ (y * tex->line_len)
		+ (x * (tex->bpp / 8));
	return (*(unsigned int *)dst);
}

void	draw_texture_column(t_data *d, t_walls *tex,
	int x, int line_h, int tex_x)
{
	int				y;
	int				start;
	int				end;
	int				tex_y;
	unsigned int	color;

	start = -line_h / 2 + HEIGHT / 2;
	end = line_h / 2 + HEIGHT / 2;
	if (start < 0)
		start = 0;
	if (end >= HEIGHT)
		end = HEIGHT - 1;
	y = start;
	while (y < end)
	{
		tex_y = (y - start) * tex->height / line_h;
		color = get_texture_pixel(tex, tex_x, tex_y);
		put_pixel_color(d, x, y, color);
		y++;
	}
}

void	put_pixel_color(t_data *data, int x, int y, unsigned int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= WIDTH || y >= HEIGHT)
		return ;
	dst = data->addr
		+ (y * data->line_len)
		+ (x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}
