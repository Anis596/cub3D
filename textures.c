/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardet- <lbardet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 00:26:11 by lbardet-          #+#    #+#             */
/*   Updated: 2026/05/02 09:23:58 by lbardet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    malloc_mlx(t_data *data)
{
    data->mlx = mlx_init();
    if (!data->mlx)
        exit(1);
    data->win = mlx_new_window(data->mlx, 800, 600, "Cub3D");
	mlx_loop(data->mlx);
}