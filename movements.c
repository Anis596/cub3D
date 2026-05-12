/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardet- <lbardet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 08:01:47 by lbardet-          #+#    #+#             */
/*   Updated: 2026/05/12 12:58:12 by lbardet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 65307)
		exit(0);
	if (keycode == 'w')
		move_forward(&data->player, data);
	if (keycode == 's')
		move_backward(&data->player, data);
	if (keycode == 'a')
		move_left(&data->player, data);
	if (keycode == 'd')
		move_right(&data->player, data);
	if (keycode == 65361)
		rotate_left(&data->player);
	if (keycode == 65363)
		rotate_right(&data->player);
	raycast(&data->player, data);
	return (0);
}

void	move_forward(t_player *player, t_data *d)
{
	double	speed;

	speed = 0.1;
	if (d->parsed_map[(int)(player->pos_y)]
			[(int)(player->pos_x + player->dir_x * speed)] != '1')
		player->pos_x += player->dir_x * speed;
	if (d->parsed_map[(int)(player->pos_y + player->dir_y * speed)]
			[(int)(player->pos_x)] != '1')
		player->pos_y += player->dir_y * speed;
}

void	move_backward(t_player *player, t_data *d)
{
	double	speed;

	speed = 0.1;
	if (d->parsed_map[(int)(player->pos_y)]
			[(int)(player->pos_x - player->dir_x * speed)] != '1')
		player->pos_x -= player->dir_x * speed;
	if (d->parsed_map[(int)(player->pos_y - player->dir_y * speed)]
			[(int)(player->pos_x)] != '1')
		player->pos_y -= player->dir_y * speed;
}

void	move_left(t_player *player, t_data *d)
{
	double	speed;

	speed = 0.1;
	if (d->parsed_map[(int)(player->pos_y)]
				[(int)(player->pos_x - player->plane_x * speed)] != '1')
		player->pos_x -= player->plane_x * speed;
	if (d->parsed_map[(int)(player->pos_y - player->plane_y * speed)]
				[(int)(player->pos_x)] != '1')
		player->pos_y -= player->plane_y * speed;
}

void	move_right(t_player *player, t_data *d)
{
	double	speed;

	speed = 0.1;
	if (d->parsed_map[(int)(player->pos_y)]
				[(int)(player->pos_x + player->plane_x * speed)] != '1')
		player->pos_x += player->plane_x * speed;
	if (d->parsed_map[(int)(player->pos_y + player->plane_y * speed)]
				[(int)(player->pos_x)] != '1')
		player->pos_y += player->plane_y * speed;
}
