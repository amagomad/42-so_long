/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagomad <amagomad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 12:17:17 by amagomad          #+#    #+#             */
/*   Updated: 2024/09/21 14:04:30 by amagomad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_free(t_params *params, int i)
{
	if (i > 0)
	{
		if (params->map)
			map_destroyer(params);
		if (params->xpm)
			mlx_destroyer(params);
		if (params->win)
			win_destroyer(params);
		free(params);
	}
	else
	{
		free(params->map);
		free(params->xpm);
		free(params->win);
		free(params);
	}
}

void	win_destroyer(t_params *params)
{
	if (params->win->mlx_ptr)
	{
		mlx_destroy_window(params->win->mlx_ptr, params->win->win_ptr);
		mlx_destroy_display(params->win->mlx_ptr);
		free(params->win->mlx_ptr);
	}
	free(params->win);
}

void	mlx_destroyer(t_params *params)
{
	mlx_destroy_image(params->win->mlx_ptr, params->xpm->underground_img);
	mlx_destroy_image(params->win->mlx_ptr, params->xpm->ground_img);
	mlx_destroy_image(params->win->mlx_ptr, params->xpm->player_img);
	mlx_destroy_image(params->win->mlx_ptr, params->xpm->collec_img);
	mlx_destroy_image(params->win->mlx_ptr, params->xpm->exit_img);
	free(params->xpm);
}

void	map_destroyer(t_params *params)
{
	int		i;

	i = 0;
	if (params->map->map)
	{
		while (params->map->map[i])
		{
			free(params->map->map[i]);
			i++;
		}
		free(params->map->map);
	}
	free(params->map);
}
