/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagomad <amagomad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 12:46:41 by amagomad          #+#    #+#             */
/*   Updated: 2024/09/23 20:23:10 by amagomad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	validate_map(t_params *params)
{
	t_flood		flood;
	int			start_x;
	int			start_y;

	flood.collectibles = 0;
	flood.exit = 0;
	start_x = -1;
	start_y = -1;
	characters_check(params->map);
	exits_count(params);
	players_count(params);
	find_start_position(params->map, &start_x, &start_y);
	if (start_x == -1 || start_y == -1)
		return (0);
	flood.map_copy = copy_map(params->map);
	if (!flood.map_copy)
		return (0);
	flood_fill(&flood, start_x, start_y);
	free_map_copy(flood.map_copy, params->map->height);
	return (flood.collectibles == params->map->total_collec && flood.exit > 0);
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
	ft_printf("ERROR: Lines must all be the same width\n");
	ft_free(params, 1);
	close(fd);
	exit(EXIT_FAILURE);
}

void	players_count(t_params *params)
{
	int		x;
	int		y;
	int		n;

	n = 0;
	y = 0;
	while (y < params->map->height)
	{
		x = 0;
		while (x < params->map->width)
		{
			if (params->map->map[y][x] == 'P')
				n++;
			x++;
		}
		y++;
	}
	if (n != 1)
	{
		ft_printf("ERROR : (Only) 1 player is accepted\n");
		ft_free(params, 0);
		exit(EXIT_FAILURE);
	}
}
