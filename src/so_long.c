/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagomad <amagomad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 10:10:22 by amagomad          #+#    #+#             */
/*   Updated: 2024/10/24 16:44:05 by amagomad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int		main(int ac, char **av)
{
	t_params	*params;

	ac_ext_check(ac, av);
	params = malloc(sizeof(t_params));
	params->win = malloc(sizeof(t_win));
	params->map = malloc(sizeof(t_map));
	params->xpm = malloc(sizeof(t_xpm));
	params->win->win_ptr = NULL;
	stock_and_draw(params, av);
	mlx_loop(params->win->mlx_ptr);
	mlx_destroy_window(params->win->mlx_ptr, params->win->win_ptr);
	mlx_destroy_display(params->win->mlx_ptr);
	ft_free(params, 0);
	return (0);
}

void	mlx_xpm_init(t_xpm *xpm, t_win *win, t_params *params)
{
	win->mlx_ptr = mlx_init();
	if (!win->mlx_ptr)
		exit(EXIT_FAILURE);
	xpm->underground_img = mlx_xpm_file_to_image(win->mlx_ptr,
			"includes/img/1.xpm", &xpm->underground_width,
			&xpm->underground_height);
	xpm->ground_img = mlx_xpm_file_to_image(win->mlx_ptr,
			"includes/img/0.xpm", &xpm->ground_width,
			&xpm->ground_height);
	xpm->player_img = mlx_xpm_file_to_image(win->mlx_ptr,
			"includes/img/P.xpm", &xpm->player_width,
			&xpm->player_height);
	xpm->collec_img = mlx_xpm_file_to_image(win->mlx_ptr,
			"includes/img/C.xpm", &xpm->collec_width,
			&xpm->collec_height);
	xpm->exit_img = mlx_xpm_file_to_image(win->mlx_ptr,
			"includes/img/E.xpm", &xpm->exit_width,
			&xpm->exit_height);
	if (!xpm->player_img || !xpm->underground_img
		|| !xpm->ground_img || !xpm->collec_img)
	{
		ft_free(params, 0);
		exit(EXIT_FAILURE);
	}
}

void	move_player(t_xpm *xpm, t_map *map, int keycode, t_params *params)
{
	int		new_x;
	int		new_y;

	new_x = xpm->player_x;
	new_y = xpm->player_y;
	if (keycode == KEY_W)
		new_y--;
	else if (keycode == KEY_S)
		new_y++;
	else if (keycode == KEY_A)
		new_x--;
	else if (keycode == KEY_D)
		new_x++;
	if (map->map[new_y][new_x] != '1' && map->map[new_y][new_x] != 'E')
		collec_and_print_moves(params, new_x, new_y, keycode);
	else if (map->map[new_y][new_x] == 'E')
		can_i_exit(params);
}

void	update_position(t_params *params, int x, int y)
{
	params->map->map[params->xpm->player_y][params->xpm->player_x] = '0';
	params->xpm->player_x = x;
	params->xpm->player_y = y;
	params->map->map[y][x] = 'P';
}

void	can_i_exit(t_params *params)
{
	if (params->map->collected == params->map->total_collec)
	{
		params->map->nb_moves++;
		ft_printf("%d\n", params->map->nb_moves);
		ft_free(params, 0);
		exit(EXIT_SUCCESS);
	}
}
