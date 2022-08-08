/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tevan-de <tevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/22 11:29:08 by tevan-de      #+#    #+#                 */
/*   Updated: 2022/02/28 11:44:25 by tevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <math.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include "../mlx_macos/mlx.h"

# define HALF_PI M_PI_2
# define PI M_PI
# define TWO_PI 6.28318530718
# define RAD 0.01745329251
# define HALF_FOV 0.575959
# define FOV 1.151917
# define ROT_SPEED RAD
# define MOVE_SPEED 0.1

# define TRANSPARENT 0xFF000000

# define KEY_UP 13
# define KEY_DOWN 1
# define KEY_LEFT 0
# define KEY_RIGHT 2
# define KEY_ROTL 123
# define KEY_ROTR 124
# define KEY_ESC 53

# define RESX 1280
# define RESY 720

typedef enum e_bool
{
	FALSE = 0,
	TRUE = 1
}	t_bool;

typedef enum e_parser_check
{
	PARSER_NORTH = 0,
	PARSER_SOUTH = 1,
	PARSER_WEST = 2,
	PARSER_EAST = 3,
	PARSER_CEILING = 4,
	PARSER_FLOOR = 5
}	t_parser_check;

typedef enum e_texture_type
{
	TEXTURE_NORTH = 0,
	TEXTURE_SOUTH = 1,
	TEXTURE_WEST = 2,
	TEXTURE_EAST = 3
}	t_texture_type;

typedef enum e_colour_type
{
	NO_COLOUR_TYPE = 0,
	CEILING = 1,
	FLOOR = 2
}	t_colour_type;

typedef struct s_doubles
{
	double			x;
	double			y;
}	t_doubles;

typedef struct s_ints
{
	int				x;
	int				y;
}	t_ints;

typedef struct s_img
{
	int				bpp;
	int				ndian;
	int				ll;
	void			*addr;
	void			*img;
}	t_img;

typedef struct s_keys
{
	int				up;
	int				down;
	int				left;
	int				right;
	int				rotate_left;
	int				rotate_right;
	int				press;
}	t_keys;

typedef struct s_player
{
	char			**map;
	double			angle;
	double			inv;
	t_doubles		dir;
	t_doubles		plane;
	t_doubles		pos;
	t_ints			ipos;
	t_ints			map_size;
}	t_player;

typedef struct s_map
{
	t_bool			begin;
	t_bool			end;
	int				n_sprites;
	t_ints			player;
	t_ints			size;
	char			*string;
}	t_map;

typedef struct s_mlx
{
	void			*mlx;
	void			*win;
	t_ints			res;
}	t_mlx;

typedef struct s_rgb
{
	int				b;
	int				g;
	int				r;
}	t_rgb;

typedef struct s_parser
{
	char			*texture[4];
	int				seen[6];
	t_map			map;
	t_rgb			ceiling;
	t_rgb			floor;
}	t_parser;

typedef struct s_texture
{
	t_img			img;
	t_ints			size;
}	t_texture;

typedef struct s_paint
{
	int				ceiling;
	int				floor;
	t_texture		texture[4];
}	t_paint;

typedef struct s_draw
{
	double			col;
	double			step;
	int				color;
	int				end;
	int				height;
	int				icol;
	int				row;
	int				start;
	int				shadow;
	t_texture		*texture;
}	t_draw;

typedef struct s_ray
{
	double			angle_p;
	double			angle_r;
	double			camera;
	double			distance;
	int				hit;
	int				hit_side;
	int				x;
	t_doubles		delta;
	t_doubles		dir;
	t_doubles		intercept;
	t_doubles		pos;
	t_doubles		side;
	t_ints			ipos;
	t_ints			step;
}	t_ray;

typedef struct s_data
{
	t_img			img;
	t_keys			keys;
	t_player		player;
	t_mlx			mlx;
	t_paint			paint;
	t_parser		parser;
}	t_data;

/*
**colors.c
*/
int					create_trgb(int t, int r, int g, int b);

/*
**cub3d_utils.c
*/
int					abbs(int n);
void				calculate_distance(t_ray *ray);
double				fix_angle(double angle);
int					ft_strcmp(const char *s1, const char *s2);

/*
**cub3d.c
*/
void				cub3d(t_data data);

/*
**draw_3d_ray.c
*/
void				draw_3d_ray(t_img img, t_paint paint, t_ray ray,
						t_ints res);

/*
**main.c
*/
int					main(int argc, char **argv);

/*
**mlx_events.c
*/
int					click_x(void);
int					key_press(int keycode, t_data *data);
int					key_release(int keycode, t_data *data);

/*
**mlx_functions.c
*/
unsigned int		get_pixel(t_img img, int x, int y);
void				put_pixel(t_img *img, int x, int y, int color);
void				set_wall_textures(char *path[5], t_texture texture[5],
						void *mx);

/*
**movement.c
*/
int					move(t_data *data);

/*
**parser_error_check.c
*/
void				count_entries(char *line, int seen[7],
						int map_begin);
t_bool				check_for_parser_errors(t_parser *parser);

/*
**parser_map_floodfill.c
*/
t_bool				check_if_map_is_closed(char **array, t_map map);

/*
**parser_map.c
*/
t_bool				check_if_map_is_valid(t_parser *parser);

/*
**parser_utils.c
*/
void				exit_program(char *s);
void				free_array(char **array, int size);
char				**free_array_part(char **array, int i);
void				skip_until_space(char **string);

/*
**parser_utils2.c
*/
t_bool				check_if_extension_is_valid(char *filename,
						char *extension);
int					cub3d_atoi_pointer(char **str);
void				skip_character(char **s, char c);
void				skip_characters(char **s, char c);

/*
**parser_utils3.c
*/
char				**ft_split_calloc(char *s, char c, t_ints size);
char				*ft_strjoin_c(char *s1, char *s2, char c);
int					ft_word_count(char const *s, char c);

/*
**parser_utils4.c
*/
int					is_color(const char *str);
t_bool				is_empty(char c);
t_bool				is_map(char c);
int					is_path(const char *str);
t_bool				is_resolution(const char *str);

/*
**parser.c
*/
void				parse(t_parser *parser, char *line);

/*
**raycasting.c
*/
void				raycasting(t_data data);

#endif
