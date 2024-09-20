/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagomad <amagomad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 10:10:22 by amagomad          #+#    #+#             */
/*   Updated: 2024/09/20 17:42:29 by amagomad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	mlx_xpm_init(t_xpm *xpm, t_win *win)
{
    win->mlx_ptr = mlx_init();
	if (!win->mlx_ptr)
	{
		ft_printf("initiation of minilibx failed\n");
		exit(EXIT_FAILURE);
	}
    xpm->underground_img = mlx_xpm_file_to_image(win->mlx_ptr, "includes/img/1.xpm", &xpm->underground_width, &xpm->underground_height);
	xpm->ground_img = mlx_xpm_file_to_image(win->mlx_ptr, "includes/img/0.xpm", &xpm->ground_width, &xpm->ground_height);
	xpm->player_img = mlx_xpm_file_to_image(win->mlx_ptr, "includes/img/P.xpm", &xpm->player_width, &xpm->player_height);
	xpm->collec_img = mlx_xpm_file_to_image(win->mlx_ptr, "includes/img/C.xpm", &xpm->collec_width, &xpm->collec_height);
	xpm->exit_img = mlx_xpm_file_to_image(win->mlx_ptr, "includes/img/E.xpm", &xpm->exit_width, &xpm->exit_height);
	if (!xpm->player_img || !xpm->underground_img || !xpm->ground_img || !xpm->collec_img)
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

	i = 0;
	line = NULL;
	fd = open(av[1], O_RDONLY);				// open file to check lines
	open_errors(fd);
	height = count_lines(line, fd, map);	// verify all lines are same lengths
	close(fd);
	map->map = (char **)malloc(sizeof(char *) * (height + 1));		// malloc it
	if (!map->map)
	{
		ft_printf("ERROR : Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}
	fd = open(av[1], O_RDONLY);		// re-open to stock this time
	open_errors(fd);
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

void	ft_free(t_params *params)
{
	int		i;

	i = 0;
	mlx_destroy_image(params->win->mlx_ptr, params->xpm->underground_img);
	mlx_destroy_image(params->win->mlx_ptr, params->xpm->ground_img);
	mlx_destroy_image(params->win->mlx_ptr, params->xpm->player_img);
	mlx_destroy_image(params->win->mlx_ptr, params->xpm->collec_img);
	mlx_destroy_image(params->win->mlx_ptr, params->xpm->exit_img);
	mlx_destroy_window(params->win->mlx_ptr, params->win->win_ptr);
	mlx_destroy_display(params->win->mlx_ptr);
	free(params->win->mlx_ptr);
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
	free(params->win);
}


void	draw_map(t_win *win, t_xpm *xpm, t_map *map)
{
	int		x;
	int		y;

	y = 0;
    while (y < map->height)
    {
        x = 0;
        while (x < map->width)
        {
            if (map->map[y][x] == '1')
                mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, xpm->underground_img, x * xpm->underground_width, y * xpm->underground_height);
            else if (map->map[y][x] == '0')
                mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, xpm->ground_img, x * xpm->ground_width, y * xpm->ground_height);
            else if (map->map[y][x] == 'P')
			{
				xpm->player_x = x;
    			xpm->player_y = y;
                mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, xpm->player_img, x * xpm->player_width, y * xpm->player_height);
			}
			else if (map->map[y][x] == 'C')
				mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, xpm->collec_img, x * xpm->collec_width, y * xpm->collec_height);
			else if (map->map[y][x] == 'E')
			{
				if (map->collected == map->total_collec)
					mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, xpm->exit_img, x * xpm->exit_width, y * xpm->exit_height);
				else
					mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, xpm->ground_img, x * xpm->ground_width, y * xpm->ground_height);
			}
            x++;
        }
        y++;
    }
}

int		count_lines(char *line, int fd, t_map *map)
{
	int		first_line_length;
	int		height;

	first_line_length = 0;
	height = 1;
	while ((line = get_next_line(fd)) != NULL)
	{
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		if (height == 1)
			first_line_length = ft_strlen(line);
		else
		{
			if ((int)ft_strlen(line) != first_line_length)
			{
				ft_printf("ERROR : Lines must all be the same width\n");
				free(line);
				close(fd);
				exit(EXIT_FAILURE);
			}
		}
		map->height = height;
		map->width = first_line_length;
		free(line);
		height++;
	}
	return (height);
}
