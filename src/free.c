/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagomad <amagomad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 12:17:17 by amagomad          #+#    #+#             */
/*   Updated: 2024/09/21 15:13:09 by amagomad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_free(t_params *params, int i)
{
	if (i > 0)
	{
		if (params->map != NULL)
			map_destroyer(params);
		if (params->xpm != NULL)
			mlx_destroyer(params);
		if (params->win != NULL)
			win_destroyer(params);
		if (params != NULL)
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
	if (params->win->mlx_ptr != NULL)
	{
		mlx_destroy_window(params->win->mlx_ptr, params->win->win_ptr);
		mlx_destroy_display(params->win->mlx_ptr);
		free(params->win->mlx_ptr);
	}
	if (params->win != NULL)
		free(params->win);
}

void	mlx_destroyer(t_params *params)
{
	if (params->win != NULL && params->xpm != NULL)
	{
		if (params->xpm->underground_img != NULL)
			mlx_destroy_image(params->win->mlx_ptr,
				params->xpm->underground_img);
		if (params->xpm->ground_img != NULL)
			mlx_destroy_image(params->win->mlx_ptr, params->xpm->ground_img);
		if (params->xpm->player_img != NULL)
			mlx_destroy_image(params->win->mlx_ptr, params->xpm->player_img);
		if (params->xpm->collec_img != NULL)
			mlx_destroy_image(params->win->mlx_ptr, params->xpm->collec_img);
		if (params->xpm->exit_img != NULL)
			mlx_destroy_image(params->win->mlx_ptr, params->xpm->exit_img);
		if (params->xpm != NULL)
			free(params->xpm);
	}
}

void	map_destroyer(t_params *params)
{
	int		i;

	if (params->map)
	{
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
}
