/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_bonus.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tevan-de <tevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/28 15:54:51 by tevan-de      #+#    #+#                 */
/*   Updated: 2022/08/08 14:13:55 by tevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/cub3d_bonus.h"

static void	set_starting_dir_and_plane(t_data *data)
{
	if (data->player.map[data->player.ipos.x][data->player.ipos.y] == 'N')
	{
		data->player.angle = HALF_PI;
		data->player.dir.x = -1.0;
		data->player.plane.y = 0.66;
	}
	else if (data->player.map[data->player.ipos.x][data->player.ipos.y] == 'S')
	{
		data->player.angle = 3 * HALF_PI;
		data->player.dir.x = 1;
		data->player.plane.y = -0.66;
	}
	else if (data->player.map[data->player.ipos.x][data->player.ipos.y] == 'W')
	{
		data->player.angle = PI;
		data->player.dir.y = -1;
		data->player.plane.x = -0.66;
	}
	else if (data->player.map[data->player.ipos.x][data->player.ipos.y] == 'E')
	{
		data->player.dir.y = 1;
		data->player.plane.x = 0.66;
	}
	data->player.inv = 1.0 / (data->player.plane.x * data->player.dir.y
			- data->player.dir.x * data->player.plane.y);
}

static void	initialize_data(t_data *data, t_parser p)
{
	data->player.map = ft_split_calloc(p.map.string, '\n', p.map.size);
	if (!data->player.map)
		exit_program("Malloc failed\n");
	data->player.pos.x = (double)p.map.player.x + 0.5;
	data->player.pos.y = (double)p.map.player.y + 0.5;
	data->player.ipos.x = p.map.player.x;
	data->player.ipos.y = p.map.player.y;
	set_starting_dir_and_plane(data);
	data->player.map[data->player.ipos.x][data->player.ipos.y] = '0';
	data->player.map_size.x = p.map.size.y;
	data->player.map_size.y = p.map.size.x;
	data->mlx.res.x = p.res.x;
	data->mlx.res.y = p.res.y;
	data->paint.ceiling = create_trgb(0, p.ceiling.r, p.ceiling.g, p.ceiling.b);
	data->sprite.n_all = p.map.n_sprites;
	if (data->sprite.n_all > 0)
	{
		data->sprite.all = ft_calloc(sizeof(t_sprite2), data->sprite.n_all);
		if (!data->sprite.all)
			exit_program("Malloc failed\n");
	}
	data->sprite.zbuffer = ft_calloc(sizeof(double), data->mlx.res.x);
	if (!data->sprite.zbuffer)
		exit_program("Malloc failed\n");
}

static void	parse_cubfile(t_parser *parser, char *cubfile)
{
	char	*line;
	int		fd;
	int		ret;

	fd = open(cubfile, O_RDONLY);
	if (fd == -1)
		exit_program("Failed to open cub file\n");
	ret = 1;
	line = NULL;
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		if (ret == -1)
			exit_program("Failed reading the line\n");
		parse(parser, line);
		free(line);
		line = NULL;
	}
	close(fd);
}

int	main(int argc, char **argv)
{
	t_data	data;

	ft_bzero(&data, sizeof(data));
	if (argc == 2 || argc == 3)
	{
		if (check_if_extension_is_valid(argv[1], ".cub") == FALSE)
			exit_program("File extension is incorrect\n");
		parse_cubfile(&data.parser, argv[1]);
		if (check_for_parser_errors(&data.parser) == FALSE)
			exit_program("Invalid cubfile\n");
		initialize_data(&data, data.parser);
		if (argc == 3)
		{
			if (ft_strcmp(argv[2], "--save"))
				exit_program("Invalid argument\n");
			cub3d(data, 1);
		}
		else
			cub3d(data, 0);
	}
	else
		exit_program("Invalid number of arguments");
	return (0);
}
