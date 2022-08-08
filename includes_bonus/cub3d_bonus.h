/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d_bonus.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tevan-de <tevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/16 15:45:34 by tevan-de      #+#    #+#                 */
/*   Updated: 2022/08/08 14:52:29 by tevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

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
# define ROT_SPEED 0.03490658504
# define MOVE_SPEED 0.1

# define BLUE 0x000000FF
# define RED 0x00FF0000
# define TRANSPARENT 0xFF000000
# define WHITE 0x00FFFFFF

# define KEY_UP 13
# define KEY_DOWN 1
# define KEY_LEFT 0
# define KEY_RIGHT 2
# define KEY_ROTL 123
# define KEY_ROTR 124
# define KEY_ESC 53

typedef enum e_bool
{
	FALSE = 0,
	TRUE = 1
}	t_bool;

typedef enum e_parser_check
{
	PARSER_RESOLUTION = 0,
	PARSER_NORTH = 1,
	PARSER_SOUTH = 2,
	PARSER_WEST = 3,
	PARSER_EAST = 4,
	PARSER_CEILING = 5,
	PARSER_FLOOR = 6,
	PARSER_SPRITE = 7
}	t_parser_check;

typedef enum e_texture_type
{
	TEXTURE_NORTH = 0,
	TEXTURE_SOUTH = 1,
	TEXTURE_WEST = 2,
	TEXTURE_EAST = 3,
	TEXTURE_FLOOR = 4,
	TEXTURE_SPRITE = 5
}	t_texture_type;

typedef enum e_colour_type
{
	NO_COLOUR_TYPE = 0,
	CEILING = 1
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

typedef struct s_draw_m
{
	t_doubles		tile;
	t_doubles		pos;
	t_ints			box;
	t_doubles		box_part;
	t_ints			ipos;
	t_ints			start;
	int				offset_y;
}	t_draw_m;

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
	int				end;
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

typedef struct s_bmp
{
	int				image_height;
	int				image_width;
	int				padding;
	int				xppm;
	int				yppm;
	unsigned int	color;
	unsigned int	bpp;
	unsigned int	compression;
	unsigned int	file_size;
	unsigned int	header_size;
	unsigned int	image_size;
	unsigned int	important_colors;
	unsigned int	offset;
	unsigned int	planes;
	unsigned int	reserved;
	unsigned int	total_colors;
}	t_bmp;

typedef struct s_parser
{
	char			*texture[6];
	int				seen[8];
	t_ints			res;
	t_map			map;
	t_rgb			ceiling;
}	t_parser;

typedef struct s_texture
{
	t_img			img;
	t_ints			size;
}	t_texture;

typedef struct s_paint
{
	int				ceiling;
	t_texture		texture[6];
}	t_paint;

typedef struct s_draw_f
{
	double			distance;
	double			middle_y;
	int				pos_y;
	t_doubles		start;
	t_doubles		end;
	t_doubles		delta;
	t_doubles		step;
	t_doubles		floor;
	t_ints			ifloor;
	t_ints			t;
	int				y;
}	t_draw_f;

typedef struct s_draw_s
{
	t_doubles		sprite;
	t_doubles		transform;
	t_ints			end;
	t_ints			start;
	int				col;
	int				height;
	int				row;
	int				width;
	int				x;
}	t_draw_s;

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

typedef struct s_sprite2
{
	double			square_distance;
	t_ints			ipos;
}	t_sprite2;

typedef struct s_sprite
{
	double			*zbuffer;
	int				n_all;
	int				n_visible;
	t_sprite2		*all;
	t_texture		texture;
}	t_sprite;

typedef struct s_data
{
	t_img			img;
	t_keys			keys;
	t_player		player;
	t_mlx			mlx;
	t_sprite		sprite;
	t_paint			paint;
	t_parser		parser;
}	t_data;

/*
**bmp_bonus.c
*/
void				create_bmp(t_data data);

/*
**colors_bonus.c
*/
int					create_trgb(int t, int r, int g, int b);

/*
**cub3d_bonus.c
*/
void				cub3d(t_data dat, int bmp);

/*
**cub3d_utils_bonus.c
*/
int					abbs(int n);
void				calculate_distance(t_ray *ray);
double				fix_angle(double angle);
int					ft_strcmp(const char *s1, const char *s2);

/*
**draw_3d_ray_bonus.c
*/
void				draw_3d_ray(t_img img, t_paint paint, t_ray ray,
						t_ints res);
void				floor_casting(t_img img, t_player player, t_ints res,
						t_texture texture);

/*
**draw_floor_bonus.c
*/
void				draw_floor(t_img img, t_player player, t_ints res,
						t_texture texture);

/*
**draw_minimap_bonus.c
*/
void				draw_minimap(t_data data, t_doubles pos, t_ints map_size,
						char **map);

/*
**main_bonus.c
*/
int					main(int argc, char **argv);

/*
**mlx_events_bonus.c
*/
int					click_x(void);
int					key_press(int keycode, t_data *data);
int					key_release(int keycode, t_data *data);

/*
**mlx_functions_bonus.c
*/
unsigned int		get_pixel(t_img img, int x, int y);
void				put_pixel(t_img *img, int x, int y, int color);
void				set_sprite_texture(char *path, t_texture *texture,
						void *mlx);
void				set_wall_textures(char *path[5], t_texture texture[5],
						void *mx);

/*
**movement_bonus.c
*/
int					move(t_data *data);

/*
**parser_bonus.c
*/
void				parse(t_parser *parser, char *line);

/*
**parser_error_check_bonus.c
*/
void				count_entries(char *line, int seen[8],
						int map_begin);
t_bool				check_for_parser_errors(t_parser *parser);

/*
**parser_map_bonus.c
*/
t_bool				check_if_map_is_valid(t_parser *parser);

/*
**parser_map_floodfill_bonus.c
*/
t_bool				check_if_map_is_closed(char **array, t_map map);

/*
**parser_utils_bonus.c
*/
void				exit_program(char *s);
void				free_array(char **array, int size);
char				**free_array_part(char **array, int i);
void				skip_until_space(char **string);

/*
**parser_utils2_bonus.c
*/
t_bool				check_if_extension_is_valid(char *filename,
						char *extension);
int					cub3d_atoi_pointer(char **str);
void				skip_character(char **s, char c);
void				skip_characters(char **s, char c);

/*
**parser_utils3_bonus.c
*/
char				**ft_split_calloc(char *s, char c, t_ints size);
char				*ft_strjoin_c(char *s1, char *s2, char c);
int					ft_word_count(char const *s, char c);

/*
**parser_utils4_bonus.c
*/
int					is_color(const char *str);
t_bool				is_empty(char c);
t_bool				is_map(char c);
int					is_path(const char *str);
t_bool				is_resolution(const char *str);

/*
**raycasting_bonus.c
*/
void				raycasting(t_data data);

/*
**sprites_bonus.c
*/
void				visible_sprite(t_sprite *sprite, t_doubles pos, int x,
						int y);
void				draw_sprites(t_data data, t_player player);

#endif
