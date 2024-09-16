/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagomad <amagomad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 10:10:22 by amagomad          #+#    #+#             */
/*   Updated: 2024/09/13 11:33:11 by amagomad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int main(int ac, char **av)
{
    t_win *win;
    t_map *map;
    t_xpm *xpm;

    ac_check(ac);
    win = malloc(sizeof(t_win));
    map = malloc(sizeof(t_map));
    xpm = malloc(sizeof(t_xpm));
    stock_map(map, av);
    mlx_xpm_init(xpm, win);

    // Initialiser la fenêtre
    win->mlx_ptr = mlx_init();
    win->win_ptr = mlx_new_window(win->mlx_ptr, 1920, 1080, "so_long");
    if (!win->win_ptr)
        return (free(win->mlx_ptr), 1);

    // Dessiner la carte
    draw_map(win, xpm, map);

    // gestion de la fermeture de la fenêtre et des touches
    mlx_hook(win->win_ptr, 17, 0, close_window, NULL);
    mlx_hook(win->win_ptr, 2, 0, key_press, NULL);

    // Boucle principale
    mlx_loop(win->mlx_ptr);

    ft_free(win, map, xpm);
    return (0);
}
