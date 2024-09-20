/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagomad <amagomad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 15:33:25 by amagomad          #+#    #+#             */
/*   Updated: 2024/09/20 18:05:11 by amagomad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_player(t_xpm *xpm, t_map *map, int keycode, t_params *params)
{
	int new_x;
	int new_y;

	new_x = xpm->player_x;
	new_y = xpm->player_y;
	if (keycode == KEY_W) new_y--;						// update x or y
	else if (keycode == KEY_S) new_y++;
	else if (keycode == KEY_A) new_x--;
	else if (keycode == KEY_D) new_x++;
	if (map->map[new_y][new_x] != '1')					// check if it's a wall or not
	{
		if (map->map[new_y][new_x] == 'C')
		{
			map->collected++;
			map->map[new_y][new_x] = '0';
		}
		else if (map->map[new_y][new_x] == 'E' && map->collected == map->total_collec)
		{
			ft_free(params);
			exit(EXIT_SUCCESS);
		}
		map->map[xpm->player_y][xpm->player_x] = '0';	// delete old position of player
		xpm->player_x = new_x;							// update his position
		xpm->player_y = new_y;
		map->map[new_y][new_x] = 'P';					// mark it on the map
	}
}

void    collectibles_count(t_map *map)
{
	int     x;
	int     y;

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
		copy[i] = strdup(map->map[i]);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

int		check_walls(t_map *map)
{
    int x;
    int y;

    // Check top and bottom walls
    for (x = 0; x < map->width; x++)
    {
        if (map->map[0][x] != '1' || map->map[map->height - 1][x] != '1')
            return (0);
    }

    // Check left and right walls
    for (y = 0; y < map->height; y++)
    {
        if (map->map[y][0] != '1' || map->map[y][map->width - 1] != '1')
            return (0);
    }

    return (1);
}


void	flood_fill(char **map_copy, int x, int y, int *collectibles, int *exit)
{
	// si hors des limites ou on rencontre un mur ou déjà visité, on arrête
	if (map_copy[y][x] == '1' || map_copy[y][x] == 'V')
		return;

	// Si on rencontre un collectible, on le compte
	if (map_copy[y][x] == 'C')
	(*collectibles)++;

	// si on rencontre l'exit, on le compte
	if (map_copy[y][x] == 'E')
		(*exit)++;

	// Marquer la case comme visitée
	map_copy[y][x] = 'V';

	// Appel récursif pour les 4 directions (haut, bas, gauche, droite)
	flood_fill(map_copy, x + 1, y, collectibles, exit);
	flood_fill(map_copy, x - 1, y, collectibles, exit);
	flood_fill(map_copy, x, y + 1, collectibles, exit);
	flood_fill(map_copy, x, y - 1, collectibles, exit);
}

int		validate_map(t_map *map)
{
	char **map_copy;
	int collectibles = 0;
	int exit = 0;
	int start_x = -1;
	int start_y = -1;

	// Chercher le point de départ
	for (int y = 0; y < map->height; y++)
	{
		for (int x = 0; x < map->width; x++)
		{
			if (map->map[y][x] == 'P')
			{
				start_x = x;
				start_y = y;
			}
		}
	}

	// Si pas de point de départ
	if (start_x == -1 || start_y == -1)
	return (0);

	// Créer une copie de la carte
	map_copy = copy_map(map);
	if (!map_copy)
	return (0);

	// Lancer le flood fill à partir du point de départ
	flood_fill(map_copy, start_x, start_y, &collectibles, &exit);

	// Libérer la copie de la carte
	for (int i = 0; i < map->height; i++)
		free(map_copy[i]);
	free(map_copy);

	// Vérifier si tous les collectibles et l'exit sont atteints
	return (collectibles == map->total_collec && exit > 0);
}
