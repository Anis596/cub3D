/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardet- <lbardet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 08:18:28 by lbardet-          #+#    #+#             */
/*   Updated: 2026/05/20 20:26:40 by lbardet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_left(t_player *player)
{
	double	old_dir_x;
	double	old_plane_x;
	double	rot;

	rot = 0.05;
	old_dir_x = player->dir_x;
	old_plane_x = player->plane_x;
	player->dir_x = player->dir_x * cos(rot)
		- player->dir_y * sin(rot);
	player->dir_y = old_dir_x * sin(rot)
		+ player->dir_y * cos(rot);
	player->plane_x = player->plane_x * cos(rot)
		- player->plane_y * sin(rot);
	player->plane_y = old_plane_x * sin(rot)
		+ player->plane_y * cos(rot);
}

void	rotate_right(t_player *player)
{
	double	old_dir_x;
	double	old_plane_x;
	double	rot;

	rot = -0.05;
	old_dir_x = player->dir_x;
	old_plane_x = player->plane_x;
	player->dir_x = player->dir_x * cos(rot)
		- player->dir_y * sin(rot);
	player->dir_y = old_dir_x * sin(rot)
		+ player->dir_y * cos(rot);
	player->plane_x = player->plane_x * cos(rot)
		- player->plane_y * sin(rot);
	player->plane_y = old_plane_x * sin(rot)
		+ player->plane_y * cos(rot);
}

