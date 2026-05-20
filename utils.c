/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardet- <lbardet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 06:55:16 by lbardet-          #+#    #+#             */
/*   Updated: 2026/05/12 13:03:49 by lbardet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	rgb_to_int(t_rgb color)
{
	return ((color.r << 16) | (color.g << 8) | color.b);
}

int	close_window(t_data *data)
{
	clean_exit(data);
	return (0);
}
