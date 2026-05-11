/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardet- <lbardet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 07:09:42 by lbardet-          #+#    #+#             */
/*   Updated: 2026/05/11 08:00:42 by lbardet-         ###   ########.fr       */
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