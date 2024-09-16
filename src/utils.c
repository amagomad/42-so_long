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

int     ft_strlen(char *str)
{
    int     i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

void    ac_check(int ac)
{
    if (ac - 1 != 1)
    {
        ft_printf("ERROR : 1 argument is the amount required");
        exit(EXIT_FAILURE);
    }
}

int     close_window(void *param)
{
	(void)param;
	exit(EXIT_SUCCESS);
}

int		key_press(int keycode, void *param)
{
	if (keycode == KEY_ESC)
		close_window(param);
	return (0);
}

void    open_errors(int fd)
{
    if (fd < 0)
    {
        ft_printf("ERROR : couldn't open file");
        exit(EXIT_FAILURE);
    }
}