/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardet- <lbardet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 07:09:42 by lbardet-          #+#    #+#             */
/*   Updated: 2026/05/20 20:58:34 by lbardet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_dda(t_player *p, t_ray *r, double ray_x, double ray_y)
{
	r->dir_x = ray_x;
	r->dir_y = ray_y;
	r->map_x = (int)p->pos_x;
	r->map_y = (int)p->pos_y;
	r->hit = 0;
	if (r->dir_x == 0)
		r->delta_dist_x = 1e30;
	else
		r->delta_dist_x = fabs(1.0 / r->dir_x);
	if (r->dir_y == 0)
		r->delta_dist_y = 1e30;
	else
		r->delta_dist_y = fabs(1.0 / r->dir_y);
}

void	get_ray_dir(t_player *player, double camera_x,
	double *ray_x, double *ray_y)
{
	*ray_x = player->dir_x + player->plane_x * camera_x;
	*ray_y = player->dir_y + player->plane_y * camera_x;
}

double	get_distance(t_ray *r)
{
	if (r->side == 0)
		return (r->side_dist_x - r->delta_dist_x);
	return (r->side_dist_y - r->delta_dist_y);
}

void	perp_dist_line_height(double perp_dist, int *line_h)
{
	if (perp_dist < 0.000001)
		perp_dist = 0.000001;
	*line_h = (int)(HEIGHT / perp_dist);
	if (*line_h < 1)
		*line_h = 1;
}
