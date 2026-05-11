/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardet- <lbardet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 00:26:06 by lbardet-          #+#    #+#             */
/*   Updated: 2026/05/11 07:55:28 by lbardet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	player_north(t_player *player)
{
	player->dir_x = 0;
	player->dir_y = -1;
	player->plane_x = 0.66;
	player->plane_y = 0;
}

static void	player_south(t_player *player)
{
	player->dir_x = 0;
	player->dir_y = 1;
	player->plane_x = -0.66;
	player->plane_y = 0;
}

static void	player_east(t_player *player)
{
	player->dir_x = 1;
	player->dir_y = 0;
	player->plane_x = 0;
	player->plane_y = 0.66;
}

static void	player_west(t_player *player)
{
	player->dir_x = -1;
	player->dir_y = 0;
	player->plane_x = 0;
	player->plane_y = -0.66;
}

int	player_init(t_data *data, t_player *player, int x, int y)
{
	if (data->parsed_map[y][x] == 'N')
		player_north(player);
	if (data->parsed_map[y][x] == 'S')
		player_south(player);
	if (data->parsed_map[y][x] == 'E')
		player_east(player);
	if (data->parsed_map[y][x] == 'W')
		player_west(player);
	player->pos_x = x + 0.5;
	player->pos_y = y + 0.5;
	return (data->countcheck + 1);
}
