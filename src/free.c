/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagomad <amagomad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 12:17:17 by amagomad          #+#    #+#             */
/*   Updated: 2024/10/28 18:37:53 by amagomad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_free(t_params *params, int i)
{
	if (i > 0)
	{
		free(params->xpm);
		free(params->map);
		free(params->win);
		free(params);
	}
	else
	{
		if (params->map)
			map_destroyer(params);
		if (params->xpm)
			xpm_destroyer(params);
		if (params->win)
			win_destroyer(params);
		if (params)
			free(params);
	}
}

void	xpm_destroyer(t_params *params)
{
	if (params->xpm != NULL)
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
		free(params->xpm);
	}
}

void	map_destroyer(t_params *params)
{
	int		i;

	i = 0;
	if (params->map)
	{
		if (params->map->map)
		{
			while (params->map->map[i])
			{
				if (params->map->map[i])
					free(params->map->map[i]);
				i++;
			}
			free(params->map->map);
		}
		free(params->map);
	}
}

void	win_destroyer(t_params *params)
{
	if (params->win->win_ptr)
		mlx_destroy_window(params->win->mlx_ptr, params->win->win_ptr);
	if (params->win->mlx_ptr)
	{
		mlx_destroy_display(params->win->mlx_ptr);
		free(params->win->mlx_ptr);
	}
	free(params->win);
}

void	invalid_map(t_params *params)
{
	if (params->map->height < 1 || params->map->width < 2)
	{
		ft_printf("ERROR : Invalid format\n");
		ft_free(params, 1);
		exit(EXIT_FAILURE);
	}
}
