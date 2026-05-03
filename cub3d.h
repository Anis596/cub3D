/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardet- <lbardet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 00:12:04 by lbardet-          #+#    #+#             */
/*   Updated: 2026/05/03 11:40:50 by lbardet-         ###   ########.fr       */
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
# include "get_next_line/gnl_bonus/get_next_line_bonus.h"

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}	t_rgb;

typedef struct s_walls
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}	t_walls;

typedef struct s_textures
{
	t_walls	no;
	t_walls	so;
	t_walls	ea;
	t_walls	we;
}	t_textures;

typedef struct s_data
{
	t_rgb	floor;
	t_rgb	ceiling;
	char	*no;
	char	*so;
	char	*ea;
	char	*we;
	void	*mlx;
	void	*win;
	char	*map;
	char	**parsed_map;
	int		fd;
	size_t	end;
}	t_data;

int		checkmap_name(char *map);
int		parsing_map(t_data *data, t_textures *textures);
int		check_player(t_data *data);
int		checkmandatories(char **map);
int		is_close_map(char **map);
int		close_or_not(char **map, int x, int y);
int		flood_fill(int x, int y, char **map);
int		is_map_line(char *line);
void	fill_struct(t_data *data, char *line);
char	*skip_to_path(char *line);
void	load_textures_no(t_textures *textures, t_data *data, char *line);
void	load_textures_so(t_textures *textures, t_data *data, char *line);
void	load_textures_ea(t_textures *textures, t_data *data, char *line);
void	load_textures_we(t_textures *textures, t_data *data, char *line);
void	load_textures(t_textures *textures, t_data *data);
t_rgb	stock_rgb(char *line);
char	**extract_map(char **parsed_map);
void	malloc_everything(t_textures *textures, t_data *data);

#endif