/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardet- <lbardet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 00:12:04 by lbardet-          #+#    #+#             */
/*   Updated: 2026/05/02 09:13:04 by lbardet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000
# endif

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <sys/time.h>
# include <math.h>
# include "minilibx-linux/mlx.h"
# include "Libft/libft.h"

typedef struct s_data
{
	void	*mlx;
	void	*win;
	char	*map;
	char	**parsed_map;
	int		fd;
	size_t	end;
}	t_data;

int		checkmap_name(char *map);
int		parsing_map(t_data *data);
int		check_player(t_data *data);
int		checkmandatories(char **map);
int		is_close_map(char **map);
int		close_or_not(char **map, int x, int y);
int		flood_fill(int x, int y, char **map);
void    malloc_mlx(t_data *data);

#endif