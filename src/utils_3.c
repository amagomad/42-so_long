/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagomad <amagomad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 15:33:25 by amagomad          #+#    #+#             */
/*   Updated: 2024/09/18 18:33:53 by amagomad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void    move_player(t_xpm *xpm, t_map *map, int keycode, t_params *params)
{
    int new_x;
    int new_y;

    new_x = xpm->player_x;
    new_y = xpm->player_y;

    // update x or y
    if (keycode == KEY_W) new_y--;
    else if (keycode == KEY_S) new_y++;
    else if (keycode == KEY_A) new_x--;
    else if (keycode == KEY_D) new_x++;

    // check if it's a wall or not
    if (map->map[new_y][new_x] != '1')
    {
        if (map->map[new_y][new_x] == 'C')
        {
            map->collected++;
            map->map[new_y][new_x] = '0';
            printf("Collectible collected! Total collected: %d\n", map->collected);
        }
        else if (map->map[new_y][new_x] == 'E')
        {
            ft_free(params);
            exit(EXIT_SUCCESS);
        }
        
        // delete old position of player
        map->map[xpm->player_y][xpm->player_x] = '0';

        // update his position
        xpm->player_x = new_x;
        xpm->player_y = new_y;

        // mark it on the map
        map->map[new_y][new_x] = 'P';

        printf("Player moved to: (%d, %d)\n", xpm->player_x, xpm->player_y);
    }
    else
        printf("Player hit a wall at: (%d, %d)\n", new_x, new_y);
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