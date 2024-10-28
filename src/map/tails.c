/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tails.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagomad <amagomad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:35:26 by amagomad          #+#    #+#             */
/*   Updated: 2024/10/28 13:42:35 by amagomad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	tails_updater(t_params	*params)
{
	if (params->xpm->player_y > params->pos->tails_max)
	{
		params->pos->tails_max = params->pos->tails_max + 2;
		params->pos->tails_min = params->pos->tails_min + 2;
	}
	else if (params->xpm->player_y < params->pos->tails_min)
	{
		params->pos->tails_max = params->pos->tails_max - 2;
		params->pos->tails_min = params->pos->tails_min - 2;
	}
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