/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagomad <amagomad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 12:26:11 by amagomad          #+#    #+#             */
/*   Updated: 2024/09/21 14:30:26 by amagomad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	count_lines(char *line, int fd, t_params *params)
{
	int		first_line_length;
	int		height;

	first_line_length = 0;
	height = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		if (height == 0)
			first_line_length = ft_strlen(line);
		else if (ft_strlen(line) != first_line_length)
			lines_checker(params, line, fd);
		height++;
		free(line);
		line = get_next_line(fd);
	}
	params->map->height = height;
	params->map->width = first_line_length;
	return (height);
}

void	flood_fill(t_flood *flood, int x, int y)
{
	if (flood->map_copy[y][x] == '1' || flood->map_copy[y][x] == 'V')
		return ;
	if (flood->map_copy[y][x] == 'C')
		flood->collectibles++;
	if (flood->map_copy[y][x] == 'E')
		flood->exit++;
	flood->map_copy[y][x] = 'V';
	flood_fill(flood, x + 1, y);
	flood_fill(flood, x - 1, y);
	flood_fill(flood, x, y + 1);
	flood_fill(flood, x, y - 1);
}

int	check_walls(t_map *map)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (x < map->width)
	{
		if (map->map[0][x] != '1' || map->map[map->height - 1][x] != '1')
			return (0);
		x++;
	}
	while (y < map->height)
	{
		if (map->map[y][0] != '1' || map->map[y][map->width - 1] != '1')
			return (0);
		y++;
	}
	return (1);
}

void	characters_check(t_map *map)
{
	int		x;
	int		y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->map[y][x] != '1' && map->map[y][x] != '0'
				&& map->map[y][x] != 'P' && map->map[y][x] != 'C'
				&& map->map[y][x] != 'E')
			{
				ft_printf("ERROR : Character %c isn't allowed\n",
					map->map[y][x]);
				ft_printf("Allowed characters are only : 1, 0, P, C, E\n");
				exit(EXIT_FAILURE);
			}
			x++;
		}
		y++;
	}
}

void	exits_count(t_map *map)
{
	int		x;
	int		y;
	int		n;

	n = 0;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->map[y][x] == 'E')
				n++;
			x++;
		}
		y++;
	}
	if (n != 1)
	{
		ft_printf("ERROR : (Only) 1 exit is required\n");
		exit(EXIT_FAILURE);
	}
}
