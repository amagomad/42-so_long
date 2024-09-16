/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagomad <amagomad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 10:10:22 by amagomad          #+#    #+#             */
/*   Updated: 2024/09/08 14:10:28 by amagomad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	mlx_xpm_init(t_xpm *xpm, t_win *win)
{
    win->mlx_ptr = mlx_init();
	if (!win->mlx_ptr)
		exit(EXIT_FAILURE);
    xpm->underground_img = mlx_xpm_file_to_image(win->mlx_ptr, "includes/img/1.xpm", &xpm->underground_width, &xpm->underground_height);
	if (!xpm->underground_img)
    {
		free(win->mlx_ptr);
        exit(EXIT_FAILURE);
    }
	xpm->ground_img = mlx_xpm_file_to_image(win->mlx_ptr, "includes/img/0.xpm", &xpm->ground_width, &xpm->ground_height);
	if (!xpm->ground_img)
    {
		free(win->mlx_ptr);
        exit(EXIT_FAILURE);
    }
	xpm->player_img = mlx_xpm_file_to_image(win->mlx_ptr, "includes/img/P0.xpm", &xpm->player_width, &xpm->player_height);
	if (!xpm->player_img)
    {
		free(win->mlx_ptr);
        exit(EXIT_FAILURE);
    }
}

void	stock_map(t_map *map, char **av)
{
	int		fd;
	char	*line;
	int		height;
	int		i;
	int		first_line_length;

	height = 0;
	i = 0;

	// Open file
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		ft_printf("ERROR : Couldn't open the file\n");
		exit(EXIT_FAILURE);
	}

	// lines count and verify line lengths
	first_line_length = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		// remove the newline character if present
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';

		// stock first line width
		if (height == 0)
		{
			first_line_length = ft_strlen(line);
		}
		else
		{
			// check if all lines got the same width
			if ((int)ft_strlen(line) != first_line_length)
			{
				ft_printf("ERROR : Lines must all be the same width\n");
				free(line);
				close(fd);
				exit(EXIT_FAILURE);
			}
		}

		free(line);
		height++;
	}
	close(fd);

	// Memory Allocation
	map->map = (char **)malloc(sizeof(char *) * (height + 1));
	if (!map->map)
	{
		ft_printf("ERROR : Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}

	// Re-open to stock this time
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		ft_printf("ERROR : Couldn't reopen the file\n");
		exit(EXIT_FAILURE);
	}

	//initiate map dimensions in struct
	map->height = height;
	map->width = first_line_length;

	i = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';

		map->map[i] = line;
		i++;
	}

	map->map[i] = NULL;
	close(fd);
}



void	ft_free(t_win *win, t_map *map, t_xpm *xpm)
{
    mlx_destroy_image(win->mlx_ptr, xpm->underground_img);
	mlx_destroy_image(win->mlx_ptr, xpm->ground_img);
	mlx_destroy_image(win->mlx_ptr, xpm->player_img);
	mlx_destroy_window(win->mlx_ptr, win->win_ptr);
	mlx_destroy_display(win->mlx_ptr);
	free(win->mlx_ptr);
	free(map->map);
	free(map);
	free(win);
}
