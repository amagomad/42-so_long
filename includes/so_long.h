/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagomad <amagomad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 10:09:58 by amagomad          #+#    #+#             */
/*   Updated: 2024/09/18 16:02:42 by amagomad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#define KEY_W 119
#define KEY_A 97
#define KEY_S 115
#define KEY_D 100
#define KEY_ESC 65307

# include "ft_printf/ft_printf.h"
# include "getnextline/get_next_line.h"
# include "mlx/mlx.h"
# include <fcntl.h>
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>

typedef struct s_win 
{
    void		*mlx_ptr;
	void		*win_ptr;
} t_win;

typedef struct s_map
{
	int		height;
	int		width;
	char	**map;
} t_map;

typedef struct s_xpm
{
	void	*player_img;
	int		player_width;
	int		player_height;
	int		player_x;
	int		player_y;
	void	*underground_img;
	int		underground_width;
	int		underground_height;
	void	*ground_img;
	int		ground_width;
	int		ground_height;
} t_xpm;

typedef struct s_params
{
    t_xpm *xpm;
    t_map *map;
    t_win *win;
} t_params;

//utils

void    ac_check(int ac);
int		close_window(void *param);
int		key_press(int keycode, t_params *params);
int     ft_strlen(char *str);
void    open_errors(int fd);

//utils_2

void    mlx_xpm_init(t_xpm *xpm, t_win *win);
void    map_init(t_map *map);
void	stock_map(t_map *map, char **av);
void    ft_free(t_win *win, t_map *map, t_xpm *xpm);
void	draw_map(t_win *win, t_xpm *xpm, t_map *map);
int		count_lines(char *line, int fd, t_map *map);

//utils_3

void    move_player(t_xpm *xpm, t_map *map, int keycode);

#endif