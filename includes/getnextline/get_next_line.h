/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagomad <amagomad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 19:48:49 by amagomad          #+#    #+#             */
/*   Updated: 2024/07/02 20:17:59 by amagomad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

char	*read_until_newline(int fd, char *buffer);
char	*extract_line(char *s);
char	*save_remainder(char *s);
char	*get_next_line(int fd);

char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlengnl(const char *str);
char	*ft_strchr(const char *str, int c);

#endif
