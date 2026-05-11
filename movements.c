/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardet- <lbardet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 08:01:47 by lbardet-          #+#    #+#             */
/*   Updated: 2026/05/11 08:21:37 by lbardet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_hook(int keycode, t_data *data, t_player *player)
{
	if (keycode == 65307)
		exit(0);
	if (keycode == 'w')
		move_forward(data, player);
	if (keycode == 's')
		move_backward(data, player);
	if (keycode == 'a')
		move_left(data, player);
	if (keycode == 'd')
		move_right(data, player);
	if (keycode == 65361)
		rotate_left(data, player);
	if (keycode == 65363)
		rotate_right(data, player);
	raycast(player, data);
	return (0);
}

void	move_forward(t_player *player, t_data *d)
{
	double	speed;

	speed = 0.1;
	if (d->map[(int)(player->pos_y)]
			[(int)(player->pos_x + player->dir_x * speed)] != '1')
		player->pos_x += player->dir_x * speed;
	if (d->map[(int)(player->pos_y + player->dir_y * speed)]
			[(int)(player->pos_x)] != '1')
		player->pos_y += player->dir_y * speed;
}

void	move_backward(t_player *player, t_data *d)
{
	double	speed;

	speed = 0.1;
	if (d->map[(int)(player->pos_y)]
			[(int)(player->pos_x - player->dir_x * speed)] != '1')
		player->pos_x -= player->dir_x * speed;
	if (d->map[(int)(player->pos_y - player->dir_y * speed)]
			[(int)(player->pos_x)] != '1')
		player->pos_y -= player->dir_y * speed;
}

void	move_left(t_player *player, t_data *d)
{
	double	speed;

	speed = 0.1;
	if (d->map[(int)(player->pos_y)]
				[(int)(player->pos_x - player->plane_x * speed)] != '1')
		player->pos_x -= player->plane_x * speed;
	if (d->map[(int)(player->pos_y - player->plane_y * speed)]
				[(int)(player->pos_x)] != '1')
		player->pos_y -= player->plane_y * speed;
}

void	move_right(t_player *player, t_data *d)
{
	double	speed;

	speed = 0.1;
	if (d->map[(int)(player->pos_y)]
				[(int)(player->pos_x + player->plane_x * speed)] != '1')
		player->pos_x += player->plane_x * speed;
	if (d->map[(int)(player->pos_y + player->plane_y * speed)]
				[(int)(player->pos_x)] != '1')
		player->pos_y += player->plane_y * speed;
}
