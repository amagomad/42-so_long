/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagomad <amagomad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 10:10:22 by amagomad          #+#    #+#             */
/*   Updated: 2024/09/18 16:25:48 by amagomad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int main(int ac, char **av)
{
    t_win *win;
    t_map *map;
    t_xpm *xpm;
    t_params *params;
    
    ac_check(ac);
    params = malloc(sizeof(t_params));
    win = malloc(sizeof(t_win));
    map = malloc(sizeof(t_map));
    xpm = malloc(sizeof(t_xpm));
    params->xpm = xpm;
    params->map = map;
    params->win = win;
    stock_map(map, av);
    mlx_xpm_init(xpm, win);

    win->mlx_ptr = mlx_init();
    win->win_ptr = mlx_new_window(win->mlx_ptr, map->width * 64, map->height * 64, "so_long");
    if (!win->win_ptr)
        return (free(win->mlx_ptr), 1);

    draw_map(win, xpm, map);

    mlx_hook(win->win_ptr, 17, 0, close_window, NULL);
    mlx_key_hook(win->win_ptr, key_press, params);
    
    mlx_loop(win->mlx_ptr);

    ft_free(win, map, xpm);
    return (0);
}
