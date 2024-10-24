/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagomad <amagomad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 12:43:53 by amagomad          #+#    #+#             */
/*   Updated: 2024/10/24 13:29:16 by amagomad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	open_errors(int fd)
{
	if (fd < 0)
	{
		ft_printf("ERROR : couldn't open file\n");
		exit(EXIT_FAILURE);
	}
}

void	ac_ext_check(int ac, char **av)
{
	if (ac - 1 != 1)
	{
		ft_printf("ERROR : 1 argument is the amount required\n");
		exit(EXIT_FAILURE);
	}
	if (!file_ext(av[1]))
	{
		ft_printf("ERROR : File must have a .ber extension\n");
		exit(EXIT_FAILURE);
	}
}

void	file_read_stock(t_map *map, int fd)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		map->map[i] = line;
		i++;
		line = get_next_line(fd);
	}
	map->map[i] = NULL;
}

int	file_ext(char *filename)
{
	char	*ext;
	size_t	len;
	size_t	ext_len;

	ext = ".ber";
	len = ft_strlen(filename);
	ext_len = strlen(ext);
	if (len >= ext_len && strcmp(filename + len - ext_len, ext) == 0)
		return (1);
	else
		return (0);
}

int		ismaptoobig(t_params *params)
{
	mlx_get_screen_size(params->win->mlx_ptr, &params->win->width, &params->win->height);
	if (params->map->height > params->win->height || params->map->width > params->win->width)
		return(1);
	else
		return (0);
}