/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardet- <lbardet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 00:12:04 by lbardet-          #+#    #+#             */
/*   Updated: 2026/05/12 13:20:23 by lbardet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000
# endif
# ifndef WIDTH
#  define WIDTH 800
# endif
# ifndef HEIGHT
#  define HEIGHT 600
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

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_player;

typedef struct s_ray
{
	double	dir_x;
	double	dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
}	t_ray;

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
	t_rgb		floor;
	t_rgb		ceiling;
	t_player	player;
	t_textures	textures;
	char		*no;
	char		*so;
	char		*ea;
	char		*we;
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	char		*map;
	char		**parsed_map;
	int			line_len;
	int			bpp;
	int			endian;
	int			fd;
	int			line_h;
	int			countcheck;
	size_t		end;
}	t_data;

int		checkmap_name(char *map);
int		parsing_map(t_data *data, t_textures *textures, t_player *player);
int		check_player(t_data *data, t_player *player);
int		checkmandatories(char **map);
int		is_close_map(char **map);
int		close_or_not(char **map, int x, int y);
int		flood_fill(int x, int y, char **map);
int		is_map_line(char *line);
void	fill_struct(t_data *data, char *line);
char	*skip_to_path(char *line);
void	load_textures(t_textures *textures, t_data *data);
t_rgb	stock_rgb(char *line);
char	**extract_map(char **parsed_map);
void	malloc_everything(t_textures *textures, t_data *data);
int		player_init(t_data *data, t_player *player, int x, int y);
int		rgb_to_int(t_rgb color);
void	mlx_load(t_data *data);
void	init_screen(t_data *data);
void	put_pixel(t_data *data, int x, int y, t_rgb color);
void	get_ray_dir(t_player *player, double camera_x,
			double *ray_x, double *ray_y);
void	init_dda(t_player *p, t_ray *r, double ray_x, double ray_y);
void	init_step(t_player *p, t_ray *r);
void	dda(t_ray *r, char **map);
void	draw_column(t_data *d, int x, int line_h, t_rgb color);
void	render_column(t_player *player, t_data *d, int x);
void	raycast(t_player *player, t_data *data);
void	clear_image(t_data *data);
int		key_hook(int keycode, t_data *data);
void	move_forward(t_player *player, t_data *d);
void	move_backward(t_player *player, t_data *d);
void	move_left(t_player *player, t_data *d);
void	move_right(t_player *player, t_data *d);
void	rotate_left(t_player *player);
void	rotate_right(t_player *player);
int		close_window(t_data *data);
t_walls	*select_texture(t_ray *r, t_textures *tex);
double	get_wall_x(t_player *p, t_ray *r, double perp_dist);
unsigned int	get_texture_pixel(t_walls *tex, int x, int y);
void	draw_texture_column(t_data *d, t_walls *tex,
	int x, int line_h, int tex_x);
void	put_pixel_color(t_data *data, int x, int y, unsigned int color);

#endif