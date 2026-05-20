/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardet- <lbardet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 00:25:56 by lbardet-          #+#    #+#             */
/*   Updated: 2026/05/20 20:57:34 by lbardet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_mlx_ptr(t_data *data)
{
	if (!data || !data->mlx)
		return ;
	if (data->fd > 0)
		close(data->fd);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
}

void	clean_exit_error(t_data *data, int code, char *message)
{
	printf("Error: %s\n", message);
	if (!data)
		exit(code);
	free_textures(data);
	free_parsed_map(data->parsed_map);
	free_strings(data);
	free_mlx(data);
	free(data);
	exit(code);
}

void	clean_exit_minimal(t_data *data, t_textures *textures, int code, char *message)
{
	printf("Error: %s\n", message);
	if (data)
	{
		if (data->fd > 0)
			close(data->fd);
		free_mlx_ptr(data);
		free(data);
	}
	if (textures)
		free(textures);
	exit(code);
}

void	clean_exit(t_data *data)
{
	if (!data)
		return ;
	free_textures(data);
	free_parsed_map(data->parsed_map);
	free_strings(data);
	free_mlx(data);
	free(data);
	exit(0);
}

void	clean_exit_with_textures(t_data *data, t_textures *textures)
{
	if (data)
	{
		free_textures(data);
		free_parsed_map(data->parsed_map);
		free_strings(data);
		free_mlx(data);
		free(data);
	}
	if (textures)
		free(textures);
	exit(0);
}
