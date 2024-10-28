/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagomad <amagomad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 10:09:58 by amagomad          #+#    #+#             */
/*   Updated: 2024/10/28 18:31:52 by amagomad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_ESC 65307

# include "ft_printf/ft_printf.h"
# include "getnextline/get_next_line.h"
# include "minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>
# include <string.h>

typedef struct s_flood
{
	char	**map_copy;
	int		collectibles;
	int		exit;
	int		start_x;
	int		start_y;
}	t_flood;

typedef struct s_win
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			height;
	int			width;
}	t_win;

typedef struct s_map
{
	int		height;
	int		width;
	char	**map;
	int		collected;
	int		total_collec;
	int		nb_moves;
}	t_map;

typedef struct s_xpm
{
	// player
	void	*player_img;
	int		player_width;
	int		player_height;
	int		player_x;
	int		player_y;
	// walls
	void	*underground_img;
	int		underground_width;
	int		underground_height;
	// grass
	void	*ground_img;
	int		ground_width;
	int		ground_height;
	// collectibles
	void	*collec_img;
	int		collec_width;
	int		collec_height;
	// exit
	void	*exit_img;
	int		exit_width;
	int		exit_height;
}	t_xpm;

typedef struct s_params
{
	t_xpm	*xpm;
	t_map	*map;
	t_win	*win;
}	t_params;

// so_long

void	mlx_xpm_init(t_xpm *xpm, t_win *win, t_params *params);
void	move_player(t_xpm *xpm, t_map *map, int keycode, t_params *params);
void	update_position(t_params *params, int x, int y);
void	can_i_exit(t_params *params);

//utils

int		ft_strlen(char *str);
int		close_window(t_params *params);
int		key_press(int keycode, t_params *params);
char	*ft_strdup(char *src);
void	collec_and_print_moves(t_params *params, int new_x,
			int new_y, int keycode);

// free

void	ft_free(t_params *params, int i);
void	xpm_destroyer(t_params *params);
void	map_destroyer(t_params *params);
void	win_destroyer(t_params *params);
void	invalid_map(t_params *params);

// fd

int		open_errors(int fd);
void	ac_ext_check(int ac, char **av);
void	file_read_stock(t_map *map, int fd);
int		file_ext(char *filename);
int		ismaptoobig(t_params *params);

// map

	// draw_characters

void	draw_1(t_params *params, int x, int y);
void	draw_0(t_params *params, int x, int y);
void	draw_p(t_params *params, int x, int y);
void	draw_c(t_params *params, int x, int y);
void	draw_e(t_params *params, int x, int y);

	// map

void	stock_and_draw(t_params *params, char **av);
void	stock_map(t_params *params, char **av);
void	draw_map(t_params *params);
void	collectibles_count(t_map *map);
char	**copy_map(t_map *map);

	// map_parsing

int		count_lines(char *line, int fd, t_params *params);
void	flood_fill(t_flood *flood, int x, int y);
int		check_walls(t_map *map);
void	characters_check(t_map *map);
void	exits_count(t_params *params);

	// map_parsing 2

int		validate_map(t_params *params);
void	find_start_position(t_map *map, int *start_x, int *start_y);
void	free_map_copy(char **map_copy, int height);
void	lines_checker(t_params *params, char *line, int fd);
void	players_count(t_params *params);

#endif