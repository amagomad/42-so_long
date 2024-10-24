/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagomad <amagomad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 12:22:21 by amagomad          #+#    #+#             */
/*   Updated: 2024/10/22 18:29:09 by amagomad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	stock_and_draw(t_params *params, char **av)
{
	stock_map(params, av);
	params->map->nb_moves = 0;
	collectibles_count(params->map);
	mlx_xpm_init(params->xpm, params->win, params);
	if (!check_walls(params->map) || !validate_map(params))
	{
		printf("ERROR : Invalid map\n");
		ft_free(params, 0);
		exit(EXIT_FAILURE);
	}
	params->win->win_ptr = mlx_new_window(params->win->mlx_ptr,
			params->map->width * 64, params->map->height * 64, "so_long");
	if (!params->win->win_ptr)
	{
		ft_printf("ERROR : MLX failed to open the window/\n");
		free(params->win->mlx_ptr);
		exit(EXIT_FAILURE);
	}
	mlx_hook(params->win->win_ptr, 17, 0, close_window, params);
	mlx_key_hook(params->win->win_ptr, key_press, params);
	draw_map(params);
}

void	stock_map(t_params *params, char **av)
{
	int		fd;
	char	*line;
	int		height;
	int		i;

	i = 0;
	line = NULL;
	fd = open(av[1], O_RDONLY);
	open_errors(fd);
	height = count_lines(line, fd, params);
	close(fd);
	params->map->map = (char **)malloc(sizeof(char *) * (height + 1));
	if (!params->map->map)
	{
		ft_printf("ERROR : Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}
	fd = open(av[1], O_RDONLY);
	open_errors(fd);
	file_read_stock(params->map, fd);
	close(fd);
}

void	draw_map(t_params *params)
{
	int		x;
	int		y;

	y = 0;
	while (y < params->map->height)
	{
		x = 0;
		while (x < params->map->width)
		{
			if (params->map->map[y][x] == '1')
				draw_1(params, x, y);
			else if (params->map->map[y][x] == '0')
				draw_0(params, x, y);
			else if (params->map->map[y][x] == 'P')
				draw_p(params, x, y);
			else if (params->map->map[y][x] == 'C')
				draw_c(params, x, y);
			else if (params->map->map[y][x] == 'E')
				draw_e(params, x, y);
			x++;
		}
		y++;
	}
}

void	collectibles_count(t_map *map)
{
	int		x;
	int		y;

	y = 0;
	map->collected = 0;
	map->total_collec = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->map[y][x] == 'C')
				map->total_collec++;
			x++;
		}
		y++;
	}
}

char	**copy_map(t_map *map)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * (map->height + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < map->height)
	{
		copy[i] = ft_strdup(map->map[i]);
		if (!copy[i])
		{
			while (i-- > 0)
				free(copy[i]);
			free(copy);
			return (NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}
