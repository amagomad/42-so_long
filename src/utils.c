/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagomad <amagomad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 10:10:22 by amagomad          #+#    #+#             */
/*   Updated: 2024/09/21 14:04:12 by amagomad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	close_window(t_params *params)
{
	ft_free(params, 1);
	(void)params;
	exit(EXIT_SUCCESS);
}

int	key_press(int keycode, t_params *params)
{
	if (keycode == KEY_ESC)
		close_window(params);
	move_player(params->xpm, params->map, keycode, params);
	draw_map(params);
	return (0);
}

char	*ft_strdup(char *src)
{
	char	*dest;
	int		i;

	i = 0;
	while (src[i] != '\0')
		i++;
	dest = malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	collec_and_print_moves(t_params *params, int x, int y, int code)
{
	if (params->map->map[y][x] == 'C')
	{
		params->map->collected++;
		params->map->map[y][x] = '0';
	}
	update_position(params, x, y);
	if (code == KEY_W || code == KEY_S
		|| code == KEY_A || code == KEY_D)
	{
		params->map->nb_moves++;
		printf("%d\n", params->map->nb_moves);
	}
}
