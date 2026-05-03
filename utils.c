/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardet- <lbardet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 10:05:33 by lbardet-          #+#    #+#             */
/*   Updated: 2026/05/03 11:30:51 by lbardet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	malloc_everything(t_textures *textures, t_data *data)
{
	textures = malloc(sizeof(t_textures));
	data = malloc(sizeof(t_data));
	data->mlx = mlx_init();
	if (!data->mlx || !textures || !data)
		exit(1);
}
