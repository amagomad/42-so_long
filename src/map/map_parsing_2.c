/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagomad <amagomad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 12:46:41 by amagomad          #+#    #+#             */
/*   Updated: 2024/09/21 14:30:50 by amagomad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	validate_map(t_map *map)
{
	t_flood		flood;
	int			start_x;
	int			start_y;

	flood.collectibles = 0;
	flood.exit = 0;
	start_x = -1;
	start_y = -1;
	characters_check(map);
	exits_count(map);
	find_start_position(map, &start_x, &start_y);
	if (start_x == -1 || start_y == -1)
		return (0);
	flood.map_copy = copy_map(map);
	if (!flood.map_copy)
		return (0);
	flood_fill(&flood, start_x, start_y);
	free_map_copy(flood.map_copy, map->height);
	return (flood.collectibles == map->total_collec && flood.exit > 0);
}

void	find_start_position(t_map *map, int *start_x, int *start_y)
{
	int	y;
	int	x;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->map[y][x] == 'P')
			{
				*start_x = x;
				*start_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	free_map_copy(char **map_copy, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(map_copy[i]);
		i++;
	}
	free(map_copy);
}

void	lines_checker(t_params *params, char *line, int fd)
{
	free(line);
	ft_free(params, 0);
	ft_printf("ERROR: Lines must all be the same width\n");
	close(fd);
	exit(EXIT_FAILURE);
}
