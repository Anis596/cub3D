/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardet- <lbardet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 00:26:08 by lbardet-          #+#    #+#             */
/*   Updated: 2026/05/11 07:56:24 by lbardet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	raycast(t_player *player, t_data *data)
{
	int	x;

	x = 0;
	clear_image(data);
	init_screen(data);
	while (x < WIDTH)
	{
		render_column(player, data, x);
		x++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

void	init_step(t_player *p, t_ray *r)
{
	if (r->dir_x < 0)
	{
		r->step_x = -1;
		r->side_dist_x = (p->pos_x - r->map_x) * r->delta_dist_x;
	}
	else
	{
		r->step_x = 1;
		r->side_dist_x = (r->map_x + 1.0 - p->pos_x) * r->delta_dist_x;
	}
	if (r->dir_y < 0)
	{
		r->step_y = -1;
		r->side_dist_y = (p->pos_y - r->map_y) * r->delta_dist_y;
	}
	else
	{
		r->step_y = 1;
		r->side_dist_y = (r->map_y + 1.0 - p->pos_y) * r->delta_dist_y;
	}
}

void	dda(t_ray *r, char **map)
{
	while (r->hit == 0)
	{
		if (r->side_dist_x < r->side_dist_y)
		{
			r->side_dist_x += r->delta_dist_x;
			r->map_x += r->step_x;
			r->side = 0;
		}
		else
		{
			r->side_dist_y += r->delta_dist_y;
			r->map_y += r->step_y;
			r->side = 1;
		}
		if (map[r->map_y][r->map_x] == '1')
			r->hit = 1;
	}
}

void	draw_column(t_data *d, int x, int line_h, t_rgb color)
{
	int	start;
	int	end;
	int	y;

	start = -line_h / 2 + HEIGHT / 2;
	end = line_h / 2 + HEIGHT / 2;
	if (start < 0)
		start = 0;
	if (end >= HEIGHT)
		end = HEIGHT - 1;
	y = start;
	while (y <= end)
	{
		put_pixel(d, x, y, color);
		y++;
	}
}

void	render_column(t_player *p, t_data *d, int x)
{
	t_ray	r;
	double	camera_x;
	double	ray_x;
	double	ray_y;
	double	perp_dist;

	camera_x = 2 * x / (double)WIDTH - 1;
	get_ray_dir(p, camera_x, &ray_x, &ray_y);
	init_dda(p, &r, ray_x, ray_y);
	init_step(p, &r);
	dda(&r, d->parsed_map);
	if (r.side == 0)
		perp_dist = (r.map_x - p->pos_x + (1 - r.step_x) / 2) / r.dir_x;
	else
		perp_dist = (r.map_y - p->pos_y + (1 - r.step_y) / 2) / r.dir_y;
	if (perp_dist <= 0)
		perp_dist = 0.0001;
	d->line_h = (int)(HEIGHT / perp_dist);
	draw_column(d, x, d->line_h, d->floor);
}
