/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardet- <lbardet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 00:12:10 by lbardet-          #+#    #+#             */
/*   Updated: 2026/05/02 09:22:37 by lbardet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac != 2 || !checkmap_name(av[1]))
		return (printf("Error: arguments"), 1);
	data = malloc(sizeof(t_data));
	if (!data)
		return (0);
	data->fd = open(av[1], O_RDONLY);
	if (data->fd < 0)
		return (free(data), 0);
	parsing_map(data);
	malloc_mlx(data);
	return (0);
}
