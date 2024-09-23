/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagomad <amagomad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 12:17:17 by amagomad          #+#    #+#             */
/*   Updated: 2024/09/23 19:34:22 by amagomad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_free(t_params *params, int i)
{
	int j;

	j = 0;
	if (i > 0)
	{
		free(params->xpm);
		free(params->map);
		free(params->win);
		free(params);
	}
	else
	{
		// if (params->map->map)
		// {
		// 	while (params->map->map[j])
		// 	{
		// 		if (params->map->map[j])
		// 			free(params->map->map[j]);
		// 		j++;
		// 	}
		// 	free(params->map->map);
		// }
		if (params->map)
			map_destroyer(params);
		if (params->xpm)
			xpm_destroyer(params);
		if (params)
			free(params);
	}
}

void	xpm_destroyer(t_params *params)
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
