/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_characters.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagomad <amagomad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 11:15:29 by amagomad          #+#    #+#             */
/*   Updated: 2024/09/21 13:40:59 by amagomad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	draw_1(t_params *params, int x, int y)
{
	mlx_put_image_to_window(params->win->mlx_ptr,
		params->win->win_ptr,
		params->xpm->underground_img,
		x * params->xpm->underground_width,
		y * params->xpm->underground_height);
}

void	draw_0(t_params *params, int x, int y)
{
	mlx_put_image_to_window(params->win->mlx_ptr,
		params->win->win_ptr,
		params->xpm->ground_img,
		x * params->xpm->ground_width,
		y * params->xpm->ground_height);
}

void	draw_p(t_params *params, int x, int y)
{
	params->xpm->player_x = x;
	params->xpm->player_y = y;
	mlx_put_image_to_window(params->win->mlx_ptr,
		params->win->win_ptr, params->xpm->player_img,
		x * params->xpm->player_width,
		y * params->xpm->player_height);
}

void	draw_c(t_params *params, int x, int y)
{
	mlx_put_image_to_window(params->win->mlx_ptr,
		params->win->win_ptr,
		params->xpm->collec_img,
		x * params->xpm->collec_width,
		y * params->xpm->collec_height);
}

void	draw_e(t_params *params, int x, int y)
{
	mlx_put_image_to_window(params->win->mlx_ptr,
		params->win->win_ptr,
		params->xpm->exit_img,
		x * params->xpm->exit_width,
		y * params->xpm->exit_height);
}
